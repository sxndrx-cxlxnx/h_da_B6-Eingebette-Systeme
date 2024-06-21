
// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: motion.c
// CONTENTS: implementation for all functions for PWM motor drive

#include <sam3x8e.h>
#include <drive.h>
#include <state.h>
#include <sample.h>
#include <math.h>

void drive_duty(const uint32_t freq, const float duty)
{
}

// initialization steps for PWM motor drive
void drive_init(void)
{
    // IN1 (PIOC23), IN2 (PIOC24), ENA (PIOC25)
    PMC->PMC_PCER1 = 1u << 1;
    PMC->PMC_PCER0 = 1 << ID_PIOC;
    
    // PINs aktivieren
    PIOC->PIO_PER = 0x01800000;         // aktiviere PIN 23 & 24
    PIOC->PIO_OER = 0x01800000;         // aktiviere Output für PIN 23 & 24
    PIOC->PIO_SODR = PIO_PC23B_PWML6;
    PIOC->PIO_CODR = PIO_PC24B_PWML7;

    // Ausgabe an PIOC25
    PIOC->PIO_PDR = PIO_PC25B_TIOA6;
    PIOC->PIO_ABSR = PIOC->PIO_ABSR | PIO_PC25B_TIOA6;

    // Channel Control Register - disable channel clock
    TC2->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKDIS; 

    // Channel Mode Register - set parameters for WAVEFORM trigger signal
    TC2->TC_CHANNEL[0].TC_CMR =
        TC_CMR_WAVE |               // Waveform mode is enabled.
        TC_CMR_WAVSEL_UP_RC |       // Enable UP mode with automatic trigger on RC compare
        TC_CMR_EEVT_XC0 |           // To make TIOB an output
        TC_CMR_ACPC_CLEAR |
        TC_CMR_ACPA_SET |
        TC_CMR_TCCLKS_TIMER_CLOCK1;

    TC2->TC_CHANNEL[0].TC_RC = DUE_MCK2 / 100;

    // waveforming - RA Register does smth
    TC2->TC_CHANNEL[0].TC_RA = (DUE_MCK2 / 100) / 2;

    TC2->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

// loop for regular tasks related to PWM motor drive
void drive_loop(void)
{
    struct sample_t current_sample = sample_series_get(distance_raw, 0);
    struct sample_t older_sample = sample_series_get(distance_raw, 1);

    float wt = gap_target;
    float st = current_sample.value / 1000.;
    float et = wt - st;

    float zeit = 0;
    float vt = older_sample;         // Geschwindigkeit
    
    if (current_sample.value / 1000. > gap_target) {

        PIOC->PIO_SODR = PIO_PC23B_PWML6;
        PIOC->PIO_CODR = PIO_PC24B_PWML7;

        duty_cycle = 25.f;

    } else if (current_sample.value / 1000. < gap_target){

        PIOC->PIO_SODR = PIO_PC24B_PWML7;
        PIOC->PIO_CODR = PIO_PC23B_PWML6;

        duty_cycle = 25.f;
        
    } else {
        duty_cycle = 0.f;
    }

    duty_cycle = 0.f;

    TC2->TC_CHANNEL[0].TC_RA = (DUE_MCK2 / 100) / (1 + duty_cycle / 100);
}
