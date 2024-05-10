// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: clock.c
// CONTENTS: Implementation clock module for generating a local time

#include <sam3x8e.h>
#include <clock.h>

// Using timer/counter 6 (tc block 2 timer 0)
#define CLOCK_PID ID_TC3

// Due master clock frequency [in MHz]
#define DUE_MCK_MHZ (DUE_MCK / 1000000)

// clock data
struct clock_t
{
    uint32_t tick_current;      // current time tick being stored in each clock_loop
    uint32_t tick_frequency;    // time tick of the most recent loop_frequency update
    uint32_t loop_latency_max;  // maximum latency in a loop happened so far
    uint32_t loop_counter;      // number of loops so far in the current second
    uint32_t loop_frequency;    // number of loops in the past second
} clock = { 0, 0, 0, 0, 0};

// get the time stamp of the current loop  in ticks [MCK128] or microseconds
uint32_t clock_get_loop_tick(void) { return clock.tick_current; }
uint32_t clock_get_loop_usec(void) { return clock.tick_current / DUE_MCK_MHZ * 128; }

// get the number of loop iterations in the last second
uint32_t clock_get_loop_frequency(void ) { return clock.loop_frequency; }

// get the maximum duration happened so far in microseconds
uint32_t clock_get_max_latency_usec(void) {return ( clock.loop_latency_max / DUE_MCK_MHZ * 128 ); } 

// busy waiting (why no elaborating this function by using MCU sleep mode)
void clock_wait(uint32_t usec)
{
    uint32_t tick_start     = TC1->TC_CHANNEL[0].TC_CV;      // time tick where waiting starts
    uint32_t ticks_wait     = usec * DUE_MCK_MHZ / 128;         // time ticks this function should wait
    uint32_t ticks_current = 0;                             // number of ticks waiting so far
    
    // busy waiting
    do { ticks_current = TC1->TC_CHANNEL[0].TC_CV - tick_start; }
        while ( ticks_wait > ticks_current );
}


// initialize timer/counter for the local clock
void clock_init(void)
{
    // turn on clock for timer/counter used for the trigger signal
    PMC->PMC_PCER0 = 1 << CLOCK_PID;   // (modulo 32 for all PIDs on PCER1 being >=32)

    // Channel Control Register - disable channel clock
    TC1->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKDIS; 

    // Channel Mode Register - set parameters for counting up
    TC1->TC_CHANNEL[0].TC_CMR =
        TC_CMR_WAVE |               // Waveform mode is enabled.
        TC_CMR_WAVSEL_UP_RC |       // Enable UP mode with automatic trigger on RC compare
        TC_CMR_CPCDIS |             // stop counting when cv reached highest value
        TC_CMR_EEVT_XC0 |           // To make TIOB an output
        TC_CMR_TCCLKS_TIMER_CLOCK4; // select MCK/128 as timer clock
    
    // Register C value is maximum so the clock is counting up
    // 84MHz/128 = 656250 ticks per second / about 6500 seconds till clock stops
    TC1->TC_CHANNEL[0].TC_RC = 0xFFFFFFFF;

    // start measurements - reset the counter (SWTRG)  and start the clock (CLKEN)
    TC1->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;                        
}

void clock_loop(void)
{
    // remember time tick of previous loop and current counter value (CV) of the current loop
    uint32_t tick_previous = clock.tick_current;
    clock.tick_current = TC1->TC_CHANNEL[0].TC_CV;;

    // if needed remember this current duration as maximum latency time of a loop
    if ( clock.loop_latency_max < ( clock.tick_current - tick_previous ) )
    {
        clock.loop_latency_max = clock.tick_current - tick_previous;
    }

    // count this loop in the loop_counter for measuring loop frequency
    clock.loop_counter++;

     // store the loop_counter value after one second as the current loop_frequency and restart counting
     if ( ( clock.tick_current - clock.tick_frequency ) >= CLOCK_TICKS_PER_SECOND )
     {
        clock.loop_frequency = clock.loop_counter;
        clock.tick_frequency = clock.tick_current;
        clock.loop_counter = 0;
     }
}