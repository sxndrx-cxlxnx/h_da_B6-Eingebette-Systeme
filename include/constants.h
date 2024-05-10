// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: constants.h
// CONTENTS: global constants and globally used variables

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

// Arduino Due uses 84 MHz as masterclock frequency by default
#define DUE_MCK     84000000
#define DUE_MCK2    (DUE_MCK/2)
#define DUE_MCK128  (DUE_MCK/128)

// baudrate for conncection to terminal
#define USART1_BAUDRATE 115200

#endif // _CONSTANTS_H
