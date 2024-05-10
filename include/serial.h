// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: serial.h
// CONTENTS: declaration of serial driver being used to interface
//           with PC / minicom via USART

#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <stdint.h>
#include <stdbool.h>

// receiving and transmitting characters
// character: character to be sent
// blocking: wait till character is sent (true)
// returns whether character(s) is/are received/transmitted 
bool serial_receive_char(char *const character, const bool blocking);
bool serial_transmit_char(const char character, const bool blocking);

// transmit (characterwise) a string of characters with a blocking behaviour
// string: a string of characters to be sent
// size: the number of characters to be sent
// returns whether character(s) is/are received/transmitted 
bool serial_transmit_string(const char *const character, const uint32_t size);

// initialization steps for serial
void serial_init(void);

// loop for regular tasks related to serial
void serial_loop(void);

#endif //_SERIAL_H