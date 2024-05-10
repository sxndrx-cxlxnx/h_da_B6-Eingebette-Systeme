// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: state.h
// CONTENTS: state of the eda application - enable/disable functions

#ifndef _STATE_H_
#define _STATE_H_

#include <stdint.h>
#include <stdbool.h>

#include "constants.h"

typedef enum clock_state {
    CLOCK_INVALID,          // no valid state
    CLOCK_MAX_LATENCY,      // show maximum duration since program start
    CLOCK_LOOP_FREQUENCY,   // show the number of loops in the past second
    CLOCK_TIME              // show current elapsed time of the loop till starting clock
} clock_state_t;

typedef enum debug_state {
    DEBUG_INVALID,          // no valid state
    DEBUG_CUSTOM,           // show your own debug info
    DEBUG_RAW_DATA,         // show raw data measurements
    DEBUG_OFF               // no debugging
} debug_state_t;

typedef enum led_state {
    LED_INVALID,            // no valid state
    LED_NOLOOP,             // disable led_loop
    LED_OFF,                // turn off LED
    LED_ON,                 // turn on LED
    LED_BLINKING            // LED blinking
} led_state_t;

typedef enum motion_state {
    MOTION_INVALID,         // no valid state
    MOTION_NOLOOP,          // disable motion_loop
    MOTION_ON,              // motors are used
    MOTION_OFF              // motors are off
} motion_state_t;

typedef enum sonic_state {
    SONIC_INVALID,          // no valid state
    SONIC_NOLOOP,           // disable sonic_loop
    SONIC_ON                // sonic measurements
} sonic_state_t;

// state contains the state of all functional components
struct state_t
{
    clock_state_t   clock;
    debug_state_t   debug;
    led_state_t     led;
    motion_state_t  motion;
    sonic_state_t   sonic;
};

extern struct state_t state;

// text to be displayed for a component state
extern const char *clock_state_text[];
extern const char *debug_state_text[];
extern const char *led_state_text[];
extern const char *motion_state_text[];
extern const char *sonic_state_text[];

// default target for the gap between sensor and wall
extern uint32_t gap_target;

extern float duty_cycle;
extern bool direction;

#endif // _STATE_H_