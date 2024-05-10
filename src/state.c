// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: state.c
// CONTENTS: state of the eda application - enable/disable functions

#include <state.h>

struct state_t state = { CLOCK_TIME, DEBUG_OFF, LED_BLINKING, MOTION_OFF, SONIC_ON };

const char *clock_state_text[] = {
    "CLK_INVD", "MAX_LTCY", "LOOP_FRQ", "   TIME  "
};

const char *debug_state_text[] = {
    "DEB_INVD", "CUSTOM", "RAW_DATA", "DBG_OFF"
};

const char *led_state_text[] = {
    "LED_INVD", "_NOLOOP_", " LED_OFF", " LED_ON ", " LEDBLK "
};

const char *motion_state_text[] = {
    "MOT_INVD", "_NOLOOP_", " MOT_ON ", " MOT_OFF"
};

const char *sonic_state_text[] = {
    "SON_INVD", "_NOLOOP_", "SONIC_ON"
};

// default target is 500mm for the gap between sensor and wall
uint32_t gap_target = 500;

// default duty cyle is 0%
float duty_cycle = 0;
// default direction is forward
bool direction = true;