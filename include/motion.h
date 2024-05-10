// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: motion.h
// CONTENTS: declaration for all functions of motion module

#ifndef _MOTION_H_
#define _MOTION_H_

#include "constants.h"
#include <stdint.h>

// stupid value - needs to be implemented
extern int32_t motion_current;

// initialization steps for motion specific
void motion_init(void);

// loop for regular tasks related to motion functions
void motion_loop(void);

#endif // MOTION_H
