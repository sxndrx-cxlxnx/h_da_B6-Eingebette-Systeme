// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: 
// FILE: matrix.c
// CONTENTS: main loop 
#include <serial.h>
#include <menu.h>
#include <clock.h>
#include <led.h>
#include <twi.h>
#include <matrix.h>

void init(void)
{
    led_init();
    serial_init();
    twi_init(TWI1, 100, false);
    matrix_init();
    menu_init();
    clock_init();
}

void loop(void)
{
    menu_loop();
    clock_loop();
    serial_loop();
    led_loop();
    matrix_loop();
    
    //char *const string = "";
    //serial_transmit_string("Hallo\\n", 7);
    
}

int main(void)
{
    init();
    while (1) {
        loop();
    }
}
