// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: serial.c
// CONTENTS: some terminal-like interface for testing purposes
//           - usart driver being used to interface with PC / minicom via USART

#include <stdbool.h>
#include <stdio.h>
#include <string.h> // TODO: remove strlen deps
#include <menu.h>
#include <serial.h>
#include <state.h>
#include <sample.h>
#include <clock.h>
#include <led.h>
#include <debug.h>

// the number of updates on the terminal per second
#define MENU_UPDATE_FREQUENCY 5

// ANSI terminal control sequence parts
#define CS_CSI "\033["  // Control Sequence Introducer
#define CS_CUP "H"      // Cursor Position
// ANSI terminal control sequences
#define CS_ED  "\033[J" // Erase Display
#define CS_DECTCEM CS_CSI "?25l" // Hides the cursor

// buffer used in menu_print functions for putting together strings to be transmitted
static char buffer[100] = "";

// column numbers:           12345678901234567890123456789012345678901234567890123456789012345678901
#define TEXT_FRAME          "+---------+---------+---------+---------+---------+---------+---------+"
#define TEXT_DESCRIPTION    "|EDA TEST | c CLOCK |  l LED  |m motion | s SONIC | 1-9 GOAL| d DEBUG |"
#define TEXT_STATE          "|STATE    |         |         |         |         |     GAP |         |"
#define TEXT_VALUE          "|VALUE    |         |         |         |         |         |         |"
#define TEXT_UNIT           "|[UNIT]   |    [ms] |[on|off] |  [mm/s] |    [mm] |    [mm] |         |"
#define TEXT_UNIT_CLOCK_HZ  "    [Hz] "
#define TEXT_UNIT_CLOCK_MS  "    [ms] "
#define TEXT_UNIT_CLOCK_MM  "    [mm] "

#define ROW_FIRST              1
#define ROW_DESCRIPTION        2
#define ROW_LINE               3
#define ROW_STATE              4
#define ROW_VALUE              5
#define ROW_UNIT               6
#define ROW_LAST               7
#define COLUMN_CLOCK          12
#define COLUMN_LED            22
#define COLUMN_MOTION         32
#define COLUMN_SONIC          42
#define COLUMN_GOAL           52
#define COLUMN_DEBUG          62


// transmit the current content of buffer string
void menu_transmit(const char *const text)
{
    serial_transmit_string(text, strlen(text));
}

void menu_disable_cursor(void) {
    const char ctrl_sequence[] = CS_DECTCEM;
    serial_transmit_string(ctrl_sequence, sizeof(ctrl_sequence));
}

void menu_clearscreen(void)
{
    char ctrl_sequence [4];     // buffer[4]: ESC(1)+[(1)+J(1)\0(1)
    sprintf(ctrl_sequence, "%s", CS_ED);
    menu_transmit(ctrl_sequence);
}

void menu_cursor(uint8_t row, uint8_t column)
{
    // define strings with up to three digits
    char srow[]      = "000";   // for converting row into string
    char scolumn[]   = "000";   // for converting column into string
    char ctrl_sequence [12];    // string for control sequence

    sprintf(scolumn, "%hhu", column);
    sprintf(srow, "%hhu", row);
    sprintf(ctrl_sequence, "%s%s;%s%s", CS_CSI, srow, scolumn, CS_CUP);
    menu_transmit(ctrl_sequence);
}

// print frame with characters not changing
static void menu_print_frame(void)
{
    // seperator lines
    sprintf(buffer, TEXT_FRAME);
    menu_cursor(ROW_FIRST, 1);
    menu_transmit(buffer);
    menu_cursor(ROW_LAST, 1);
    menu_transmit(buffer);

    // description line
    menu_cursor(ROW_DESCRIPTION, 1);
    sprintf(buffer, TEXT_DESCRIPTION);
    menu_transmit(buffer);

    // description line
    menu_cursor(ROW_LINE, 1);
    sprintf(buffer, TEXT_FRAME);
    menu_transmit(buffer);

    // state line
    menu_cursor(ROW_STATE, 1);
    sprintf(buffer, TEXT_STATE);
    menu_transmit(buffer);    

    // value line
    menu_cursor(ROW_VALUE, 1);
    sprintf(buffer, TEXT_VALUE);
    menu_transmit(buffer);    

    // unit line
    menu_cursor(ROW_UNIT, 1);
    sprintf(buffer, TEXT_UNIT);
    menu_transmit(buffer);    
}

// current component state
static void menu_print_state(void)
{
    static uint32_t tick_update = 0;
    const uint32_t  interval    = CLOCK_TICKS_PER_SECOND / MENU_UPDATE_FREQUENCY;
    if ( tick_update + interval > clock_get_loop_tick() ) return;

    // print sonic state
    menu_cursor(ROW_STATE, COLUMN_CLOCK);
    sprintf(buffer, "%s", clock_state_text[state.clock]);
    menu_transmit(buffer);

    // print LED state
    menu_cursor(ROW_STATE, COLUMN_LED);
    sprintf(buffer, "%s", led_state_text[state.led]);
    menu_transmit(buffer);

    // print motion state
    menu_cursor(ROW_STATE, COLUMN_MOTION);
    sprintf(buffer, "%s", motion_state_text[state.motion]);
    menu_transmit(buffer);

    // print sonic state
    menu_cursor(ROW_STATE, COLUMN_SONIC);
    sprintf(buffer, "%s", sonic_state_text[state.sonic]);
    menu_transmit(buffer);

    // print debug state
    menu_cursor(ROW_STATE, COLUMN_DEBUG);
    sprintf(buffer, "%s", debug_state_text[state.debug]);
    menu_transmit(buffer);
}

// print current value of clock data
static void menu_print_value_clock(void)
{
    static bool ms_as_unit = true;
    bool ms_as_new_unit = true;

    // print the chosen value of clock
    menu_cursor(ROW_VALUE, COLUMN_CLOCK);
    switch ( state.clock )
    {
        case CLOCK_MAX_LATENCY:
            sprintf(buffer, "%8lu ", clock_get_max_latency_usec() / 1000 );
            break;
        case CLOCK_LOOP_FREQUENCY:
            sprintf(buffer, "%8lu ", clock_get_loop_frequency());
            ms_as_new_unit = false;
            break;
        case CLOCK_TIME:
            sprintf(buffer, "%8lu ", clock_get_loop_usec() / 1000 );
            break;
        case CLOCK_INVALID:
        default:
            sprintf(buffer, "%s ", ".........");
            break;
    }
    menu_transmit(buffer);

    // switch shown unit if neccessary
    if ( ms_as_unit != ms_as_new_unit )
    {
        menu_cursor(ROW_UNIT, COLUMN_CLOCK);

        if ( ms_as_new_unit ) sprintf(buffer, "%s", TEXT_UNIT_CLOCK_MS);
            else sprintf(buffer, "%s", TEXT_UNIT_CLOCK_HZ);

        ms_as_unit = ms_as_new_unit;
        menu_transmit(buffer);
    }
}

// print current value of LED
static void menu_print_value_led(void)
{
    // state of the LED
    menu_cursor(ROW_VALUE, COLUMN_LED);
    sprintf(buffer, "    %s", led_get() ? " ON" : "OFF");
    menu_transmit(buffer);
}

// print current value of ultrasonic sensor
static void menu_print_value_sonic(void)
{
    // get the current sample from raw data series
    struct sample_t current_sample = sample_series_get(distance_raw, 0);

    // if valid print sample value
    if ( current_sample.valid )
    {
        menu_cursor(ROW_VALUE, COLUMN_SONIC);
        sprintf(buffer, "   %5lu ", current_sample.value / 1000);
        menu_transmit(buffer);
    }
}

// print current value of the gap target
static void menu_print_value_gap(void)
{
    menu_cursor(ROW_VALUE, COLUMN_GOAL);
    sprintf(buffer, "    %4lu ", gap_target);
    menu_transmit(buffer);    
}

// current value of components
static void menu_print_value(void) {

    menu_print_value_clock();
    menu_print_value_led();
    menu_print_value_sonic();
    menu_print_value_gap();
}

static void menu_print_debug(void)
{
    switch ( state.debug ) {
        case DEBUG_RAW_DATA:
            debug_print_sample_series(distance_raw);
            break;
        case DEBUG_CUSTOM:
            debug_print_custom();
            break;
        case DEBUG_OFF:
        default:
            break;
    }
}

// select the appropriate state
static void menu_switch_state(char selection)
{
    switch (selection) {
        case '1':           // possible gap targets
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        gap_target = (selection - '0') * 100;
        break;
        case 'c':           // switch clock state
            state.clock--;
            if ( state.clock == CLOCK_INVALID ) { state.clock = CLOCK_TIME; }
            break;
        case 'd':           // switch debug state
            state.debug--;
            if ( state.debug == DEBUG_INVALID ) { state.debug = DEBUG_OFF; }
            break;
        case 'l':           // switch LED state
            state.led--;
            if ( state.led == LED_INVALID ) { state.led = LED_BLINKING; }
            break;
        case 'm':           // switch LED state
            state.motion--;
            if ( state.motion == MOTION_INVALID ) { state.motion = MOTION_OFF; }
            break;
        case 's':           // switch LED state
            state.sonic--;
            if ( state.sonic == SONIC_INVALID) { state.sonic = SONIC_ON; }
            break;
        default:
            break;
    }
}

// print an update on terminal on a regular base
static void menu_print_update(void )
{
    static uint32_t tick_update = 0;
    const uint32_t  interval    = CLOCK_TICKS_PER_SECOND / MENU_UPDATE_FREQUENCY;

    // if last update is back more than an interval
    if ( tick_update + interval < clock_get_loop_tick() )
    {
        // print new values
        menu_print_value();

        //
        if ( state.debug == DEBUG_RAW_DATA )
        {
            menu_print_debug();
        }

        // leave cursor in the top left corner
        menu_cursor(ROW_UNIT, 1);

        // update values at current looptick
        tick_update = clock_get_loop_tick();
    }
}

// initialization steps for menu - print menu on screen
void menu_init(void)
{
    menu_disable_cursor();
    menu_clearscreen();
    menu_print_frame();
    menu_print_state();
}

// loop for regular tasks related to menu
void menu_loop(void)
{
    char selection;

    // if a character is received switch state and print state line
    if ( serial_receive_char(&selection, false) )
    {
        menu_switch_state(selection);
    }
    menu_print_state();
    menu_print_update();
}