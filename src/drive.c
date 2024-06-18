
// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: motion.c
// CONTENTS: implementation for all functions for PWM motor drive

#include <sam3x8e.h>
#include <drive.h>
#include <state.h>
#include <math.h>

void drive_duty(const uint32_t freq, const float duty)
{
}

// initialization steps for PWM motor drive
void drive_init(void)
{
    // IN1 (PIOC23), IN2 (PIOC24), ENA (PIOC25)
    // Ausgabe an PIOC25
    PIOC->PIO_PDR = 0x03800000;
    PIOC->PIO_ABSR = PIO_PC25B_TIOA6;

    // Channel Control Register - disable channel clock
    TC2->TC_CHANNEL[3].TC_CCR = TC_CCR_CLKDIS; 

    // Channel Mode Register - set parameters for WAVEFORM trigger signal
    TC2->TC_CHANNEL[3].TC_CMR =
        TC_CMR_WAVE |               // Waveform mode is enabled.
        TC_CMR_WAVSEL_UP_RC |       // Enable UP mode with automatic trigger on RC compare
        TC_CMR_EEVT_XC0 |           // To make TIOB an output
        TC_CMR_BCPB_CLEAR |         // RB compare effect on TIOB
        TC_CMR_BCPC_SET |           // RC compare effect on TIOB
        TC_CMR_BSWTRG_SET |         // Software trigger effect on TIOB
        TC_CMR_TCCLKS_TIMER_CLOCK1; // select MCK/2 as timer clock

    // Register C value after a period where the counter gets reseted on compare
    // clock MCK/2 ist used; period duration TRIGGER_FREQUENCY/1000  [msec]
    TC2->TC_CHANNEL[3].TC_RC = DUE_MCK2 / 10;

    // waveforming - RB Register clears output after a 20 usec pulse (10 usec is minimum)
    TC2->TC_CHANNEL[3].TC_RB = DUE_MCK2 / 50000;

    // start measurements - reset the counter (SWTRG)  and start the clock (CLKEN)
    TC2->TC_CHANNEL[3].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;

}

// loop for regular tasks related to PWM motor drive
void drive_loop(void)
{
}
