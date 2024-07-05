
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
#include <sonic.h>

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
        TC_CMR_ACPC_SET |
        TC_CMR_ACPA_CLEAR |
        TC_CMR_TCCLKS_TIMER_CLOCK1;

    TC2->TC_CHANNEL[0].TC_RC = DUE_MCK2 / 100;

    // waveforming - RA Register does smth
    TC2->TC_CHANNEL[0].TC_RA = 1; //(DUE_MCK2 / 100) / 2;

    TC2->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

// loop for regular tasks related to PWM motor drive
void drive_loop(void)
{
    if(!new_sample){
        return;
    }
    new_sample = false;

    float distance_mean = 0.f;
    int ctr = 0;

    for(int i = 0; i < SAMPLE_SERIES_SIZE; i++) {
        struct sample_t current_sample = sample_series_get(distance_raw, i);
        float st2 = current_sample.value / 1000.;
        
        if(current_sample.valid) {
            distance_mean += st2;
            ctr++;
        }
    }
    distance_mean /= ctr;
    
    //struct sample_t older_sample = sample_series_get(distance_raw, 1);

    float wt = gap_target;
    /*
    float st1 = older_sample.value / 1000.;
    float et2 = wt - st2;
    float et1 = wt - st1;
    */
   float et2 = wt - distance_mean;
   static float et1 = 0;

    // Verstärkung
    float KP = 0.001; // 0.8, 1.
    float KD = 0.; // 0.00002;
    float k_duty_cycle = 1.; //0.3, 0.8
    float zeit = 0.00002;

    float distance = et2 - et1;
    float hysterese = 5;               // in mm

    float vt = (distance)/zeit;         // Geschwindigkeit
    float ut = KP * et2 + KD * vt;

    if(et2 > -hysterese && et2 < hysterese) {
        duty_cycle = 0.f;
    } else {
        if (ut <= 0) {

            //Rückwärts
            PIOC->PIO_SODR = PIO_PC24B_PWML7;
            PIOC->PIO_CODR = PIO_PC23B_PWML6;

            duty_cycle = -1 * ut;
            // duty_cycle = 1;

        } else if (ut >= 0){        

            //Vorwärts
            PIOC->PIO_SODR = PIO_PC23B_PWML6;
            PIOC->PIO_CODR = PIO_PC24B_PWML7;

            duty_cycle = ut;
            
        }
    }

    uint32_t RA = (DUE_MCK2 / 100) * (duty_cycle * k_duty_cycle);
    if (RA == 0) {
        RA = 1;
    }
    TC2->TC_CHANNEL[0].TC_RA = RA;
    et1 = et2;
}
