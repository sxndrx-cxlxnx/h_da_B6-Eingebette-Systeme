// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: state.c
// CONTENTS: twi functions

#ifndef _TWI_H_
#define _TWI_H_

#include <sam3x8e.h>
#include <stdint.h>
#include <stdbool.h>

#define twi_check(twi, flag) ((twi->TWI_SR & (flag)) == (flag))
#define twi_wait(twi, flag) while (!twi_check(twi, flag))

void twi_init(Twi *const twi, const uint32_t freq, const bool slave);
void twi_write(Twi *const twi, const uint32_t address, const uint8_t *const ptr, const uint32_t size);

#endif // _TWI_H_
