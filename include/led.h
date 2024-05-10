// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: led.c
// CONTENTS: Source for Due Onboard LED control

#ifndef _LED_H_
#define _LED_H_

#include <stdbool.h>
#include "constants.h"

// get/set state of LED
bool led_get(void);
void led_set(bool led_on);

// initialization steps for LED's attached to a PIO port
void led_init(void);

// loop for regular tasks related to Due Onboard LED
void led_loop(void);

#endif // _LED_H