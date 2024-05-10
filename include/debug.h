// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: debug.h
// CONTENTS: declaration for all debug functions

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <sample.h>

// print sample_series as debug info
void debug_print_sample_series(struct sample_series_t *series);

// print your own debug info
void debug_print_custom();

// initialization steps for debugging
void debug_init(void);

// loop for regular tasks related to debugging
void debug_loop(void);

#endif // DEBUG_H
