// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: matrix.h
// CONTENTS: declaration driving I2C led matrix

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <sam3x8e.h>
#include <stdint.h>
#include <stdbool.h>
#include "constants.h"

// setup the matrix
void matrix_setup(Twi *const twi, const uint8_t device_address);

// ubdate the matrix according to change in the buffer
bool matrix_update(Twi *const twi, const uint8_t buffer[8]);

// map 0.-1. to 0-64 and change the buffer accordingly
void matrix_progress(uint8_t *const buffer, const float progress);

// initialization steps for led matrix
void matrix_init(void);

// loop for regular tasks for led matrix
void matrix_loop(void);

#endif // MATRIX_H
