// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: clock.h
// CONTENTS: Declarations of local clock module

#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <stdint.h>
#include "constants.h"

// clock uses MCK/128 so one tick is 128/84 MHz (about 1,5 usec)
// -> recognize  the overflow after about 6000 seconds / 100 minutes
#define CLOCK_TICKS_PER_SECOND (DUE_MCK/128)

// get the clock tick recognized as tick of the current loop
uint32_t clock_get_loop_tick(void);
uint32_t clock_get_loop_usec(void);

// get the maximal latency of a loop since start [mikroseconds]
uint32_t clock_get_max_latency_usec(void);

// get the number of loops in the past second
uint32_t clock_get_loop_frequency(void);

// wait a number of microseconds
void clock_wait(uint32_t usec);

// initialization steps for the local clock
void clock_init(void);

// loop for regular tasks related to local clock
void clock_loop(void);

#endif // _CLOCK_H_