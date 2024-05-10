// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: sonic.h
// CONTENTS: declaration of sonic driver using ultrasonic sensor HC-SR04

#ifndef _SONIC_H_
#define _SONIC_H_

#include "constants.h"

// initialization steps for ultrasonic sensor HC-SR04
void sonic_init(void);

// loop for regular tasks related to ultrasonic sensor
void sonic_loop(void);

#endif // SONIC_H
