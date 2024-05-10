// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: menu.h
// CONTENTS: menu communicating with PC via serial

#ifndef _MENU_H_
#define _MENU_H_

#include <stdint.h>

// clear terminal screen
void menu_clearscreen(void);

// move cursor on terminal screeen
void menu_cursor(uint8_t row, uint8_t column);

// transmit a string to the terminal
void menu_transmit(const char *const text);

// initialization steps for menu
void menu_init(void);

// loop for regular tasks related to menu
void menu_loop(void);

#endif //_MENU_H_