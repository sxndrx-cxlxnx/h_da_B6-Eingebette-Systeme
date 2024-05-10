// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: sonic.h
// CONTENTS: implementation of sonic driver using ultrasonic sensor HC-SR04

#include <sam3x8e.h>
#include <sample.h>
#include <sonic.h>
#include <clock.h>

// HC-SR04 ultrasonic distance measurement sensor
// TIOB7 / TRIGGER: generates a trigger signal using timer 7 (TC block 2 channel 1)
//                  the trigger signal is a pulse with minimum 10usec duration
// TIOA8 / ECHO: measures duration of echo using timer 8 (TC block 2 channel 2)
//                  the echo starts with raising edge and ends with falling edge

// Peripheral IDs of both timer/counter
#define PID_TRIGGER         ID_TC7
#define PID_ECHO            ID_TC8

// Measurements restarted with this frequency of trigger pulse 
#define TRIGGER_FREQUENCY   40

// Sonic speed is about 343 m/s at 20 degrees Celsius
#define SONIC_SPEED 343

/*
__attribute__((interrupt("IRQ"))) void TC8_Handler()
{
    uint32_t status = TC2->TC_CHANNEL[2].TC_SR;
    if (status & TC_SR_LDRBS)
    {
        uint32_t ra = TC2->TC_CHANNEL[2].TC_RA;
        uint32_t rb = TC2->TC_CHANNEL[2].TC_RB;
        uint32_t diff = rb - ra;
        distance = diff * (EDA_SONICSPEED) / (84000000 / 1000000); // micro meters
        new_distance = true;

        TC2->TC_CHANNEL[2].TC_CCR = TC_CCR_SWTRG;
    }
}
*/

// initialize the timer used as ultrasonic sensor trigger
void init_trigger(void)
{
    // turn on clock for timer/counter used for the trigger signal
    PMC->PMC_PCER1 = 1 << PID_TRIGGER % 32; // (modulo 32 for all PIDs on PCER1 being >=32)

    // Enable PIO pin for Timer/counter TIOB7 which is on PIO port C
    PIOC->PIO_PDR = PIO_PC29B_TIOB7;        // disable PIO port pin for multiplexing 
    PIOC->PIO_ABSR = PIO_PC29B_TIOB7;       // TIOB7 is multiplexed as peripheral B

    // Channel Control Register - disable channel clock
    TC2->TC_CHANNEL[1].TC_CCR = TC_CCR_CLKDIS; 

    // Channel Mode Register - set parameters for WAVEFORM trigger signal
    TC2->TC_CHANNEL[1].TC_CMR =
        TC_CMR_WAVE |               // Waveform mode is enabled.
        TC_CMR_WAVSEL_UP_RC |       // Enable UP mode with automatic trigger on RC compare
        TC_CMR_EEVT_XC0 |           // To make TIOB an output
        TC_CMR_BCPB_CLEAR |         // RB compare effect on TIOB
        TC_CMR_BCPC_SET |           // RC compare effect on TIOB
        TC_CMR_BSWTRG_SET;
        
/*         |         // Software trigger effect on TIOB
        TC_CMR_TCCLKS_TIMER_CLOCK1; // select MCK/2 as timer clock
*/
    
    // Register C value after a period where the counter gets reseted on compare
    // clock MCK/2 ist used; period duration TRIGGER_FREQUENCY/1000  [msec]
    TC2->TC_CHANNEL[1].TC_RC = DUE_MCK2 / TRIGGER_FREQUENCY;

    // waveforming - RB Register clears output after a 20 usec pulse (10 usec is minimum)
    TC2->TC_CHANNEL[1].TC_RB = DUE_MCK2 / 50000;

    // start measurements - reset the counter (SWTRG)  and start the clock (CLKEN)
    TC2->TC_CHANNEL[1].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;                        
}

// initialize the timer used for measuring the time till echo arrives
void init_echo()
{
    // turn on clock for timer/counter used for receiving echo signal
    PMC->PMC_PCER1 = 1 << PID_ECHO % 32;        // modulo 32 for all TC's, PIDs on PCER1 are >=32

    // Enable PIO pin for Timer/counter TIOA8 which is on PIO port D
    PIOD->PIO_PDR = PIO_PD7B_TIOA8;        // disable PIO port pin for multiplexing 
    PIOD->PIO_ABSR = PIO_PD7B_TIOA8;       // TIOA8 is multiplexed as peripheral B

    TC2->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKDIS;             // Disable the clock

    // NVIC
    // NVIC_EnableIRQ(TC8_IRQn);

    TC2->TC_CHANNEL[2].TC_CMR =     TC_CMR_LDBSTOP |        // Counter clock is stopped when RB loading occurs
                                    TC_CMR_CPCTRG |         // RC Compare resets the counter and starts the counter clock
                                    TC_CMR_LDRA_RISING |    // Rising edge of TIOA
                                    TC_CMR_LDRB_FALLING;    // Falling edge of TIOA

    TC2->TC_CHANNEL[2].TC_RC = -1;                          // use maximum value for register RC

    // TC2->TC_CHANNEL[2].TC_IER = TC_IER_LDRBS;               // enable interrupt on register RB loaded

    TC2->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;// Reset the counter and start the clock
}

void sonic_init(void)
{
    init_trigger();
    init_echo();
}

void sonic_loop()
{
    // polling for the end of a measurement when the echo arrived
    if ( TC2->TC_CHANNEL[2].TC_SR & TC_SR_LDRBS )          // if echo status register says Register B is loaded
    {
        // duration of echo signal in EDA_
        int32_t duration = TC2->TC_CHANNEL[2].TC_RB - TC2->TC_CHANNEL[2].TC_RA;

        // create a new sample with measured distance [in mm] as value
        struct sample_t sample;
        sample.value = duration * SONIC_SPEED / ( DUE_MCK / 1000000 );
        sample.usec = clock_get_loop_usec();
        sample.valid = true;

        // insert new sample into the sample_queue - forget sample if queue is full
        sample_queue_insert(sample);
        
        // Reset the counter to be ready for the next measurement
        TC2->TC_CHANNEL[2].TC_CCR = TC_CCR_SWTRG;
    }
}
