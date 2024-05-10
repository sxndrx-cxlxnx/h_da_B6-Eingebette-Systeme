// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: drive.h
// CONTENTS: declaration for all functions for PWM motor drive

#ifndef _DRIVE_H_
#define _DRIVE_H_

#include <stdbool.h>
#include "constants.h"

void drive_duty(const uint32_t freq, const float duty);

// initialization steps for PWM motor drive
void drive_init(void);

// loop for regular tasks related to PWM motor drive
void drive_loop(void);

#endif // DRIVE_H
