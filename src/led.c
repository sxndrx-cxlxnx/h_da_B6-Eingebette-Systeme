// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: led.c
// CONTENTS: Source for Due Onboard LED control

#include <clock.h>
#include <constants.h>
#include <led.h>
#include <sam3x8e.h>
#include <state.h>

// BUILTIN-LED on Arduino Due Board on PIO Port B Bit 27
#define DUE_LED_BUILTIN PIO_PB27

//0x400E + 0x1000 --> Power Management PIOB?
//PER --> PIO Enable Register 0x00 (Offset)
//OER --> Output Enable Register 0x10 (Offset)

#define PIOB_PER ((volatile unsigned int *) 0x400E1000)

#define PIOD_PER ((volatile unsigned int *) 0x400E1400)
#define PIOD_ODR ((volatile unsigned int *) 0x400E1414)
#define PIOD_PDSR ((volatile unsigned int *) 0x400E143C)

#define PMC_PCER0 ((volatile unsigned int *) 0x400E0610) //PIOB an Register 12 --> 0x1000
#define PMC_PCER1 ((volatile unsigned int *) 0x400E0700)

#define PIOB_ODSR ((volatile unsigned int *) 0x400E1038) //PIO Output Data Status Register für PIOB
#define PIOB_SODR ((volatile unsigned int *) 0x400E1030) //PIO Set Output Data Register für PIOB
#define PIOB_CODR ((volatile unsigned int *) 0x400E1034) //PIO Clear Output Data Register für PIOB

unsigned int adr_PIOB_OER = 0x400E1010;
unsigned int led = 0x08000000;

// return state of LED
bool led_get(void) { 								//TODO: funktioniert das so?
	unsigned int status = *PIOB_ODSR;
	if(status & led == led){
		return true;
	}
	return false; 
}

// turn on/off LED
void led_set(bool led_on) {							//TODO: funktioniert das so?

	if(led_on){
		*PIOB_SODR = led;				
	}else{
		*PIOB_CODR = led;
	}

}

// toogle LED
static void led_toggle(void) {}

// LED is toggling after a number of calls
static void led_blinking(void)
{
	static uint32_t update_tick = 0;
	const uint32_t interval = CLOCK_TICKS_PER_SECOND / 2;

	// if last update is back more than an interval
	if (update_tick + interval < clock_get_loop_tick())
	{
		led_toggle();
		update_tick = clock_get_loop_tick();
	}
}

// initial config for using LED
void led_init(void) {
	*PMC_PCER0 = 0x1000; //Peripheral Clock für PIOB einschalten (Bit 12) (?)
	*PMC_PCER0 = 0x5000; //Peripheral Clock für PIOD einschalten (Bit 14) (?)
	*PIOB_PER = led; //idealerweise die LED aktivieren (Bit 27)

	*PIOD_ODR = 0x7; //idealerweise Tasten 1-3 aktivieren (PIOD0-2)

}

// loop for LED control - blinking when EDA code is running
void led_loop(void)
{/*											//TODO: Soll das so?
	unsigned int status = *PIOD_PDSR;
	int taste = -1;

	if (status & 0x1 == 0x1){
		taste = 0;
	} else if (status & 0x2 == 0x2){
		taste = 1;
	} else if (status & 0x4 == 0x4){
		taste = 2;
	}

	if (state.led == LED_NOLOOP)
		return;

	switch (taste)	{
	case 0:
		led_blinking();
		break;
	case 1:
		led_set(true);
		break;
	case 2:
		led_set(false);
		break;
	default:
		break;
	}
*/

	if (state.led == LED_NOLOOP)
		return;

	switch (state.led)
	{
	case LED_BLINKING:
		led_blinking();
		break;
	case LED_ON:
		led_set(true);
		break;
	case LED_OFF:
		led_set(false);
		break;
	case LED_NOLOOP:
	default:
		break;
	}
}
