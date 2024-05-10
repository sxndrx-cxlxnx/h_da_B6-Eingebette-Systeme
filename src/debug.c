// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: debug.c
// CONTENTS: implementation of debug - generating strings containing debug information

#include <stdio.h>
#include <debug.h>
#include <menu.h>

#define ROW_SERIES_INDEX      9
#define ROW_SERIES_VALUE     10
#define ROW_SERIES_USEC      11
#define ROW_SERIES_VALID     12
#define COLUMN_SERIES         1

// buffer used in debug_print functions for putting together strings to be transmitted
static char buffer[100] = "";

// this function prints 4 samples from sample_series distance_raw (badly hacked just for debugging)
// please be aware that the output is fitted to 4 samples, but sample_series stores more samples
void debug_print_sample_series(struct sample_series_t *series)
{
    menu_cursor(ROW_SERIES_INDEX, COLUMN_SERIES);
    sprintf(buffer, "       [0]           [1]           [2]          [3]");
    menu_transmit(buffer);

    menu_cursor(ROW_SERIES_VALUE, COLUMN_SERIES);
    int32_t v0 = sample_series_get(series, 0).value;
    int32_t v1 = sample_series_get(series, 1).value;
    int32_t v2 = sample_series_get(series, 2).value;
    int32_t v3 = sample_series_get(series, 3).value;
    sprintf(buffer, "%9li[um] %9li[um] %9li[um] %9li[um]", v0, v1, v2, v3);
    menu_transmit(buffer);

    menu_cursor(ROW_SERIES_USEC, COLUMN_SERIES);
    int32_t t0 = sample_series_get(series, 0).usec;
    int32_t t1 = sample_series_get(series, 1).usec;
    int32_t t2 = sample_series_get(series, 2).usec;
    int32_t t3 = sample_series_get(series, 3).usec;
    sprintf(buffer, "%9li[us] %9li[us] %9li[us] %9li[us]", t0, t1, t2, t3);
    menu_transmit(buffer);

    menu_cursor(ROW_SERIES_VALID, COLUMN_SERIES);
    bool b0 = sample_series_get(series, 0).valid;
    bool b1 = sample_series_get(series, 1).valid;
    bool b2 = sample_series_get(series, 2).valid;
    bool b3 = sample_series_get(series, 3).valid;
    sprintf(buffer, "     %s          %s         %s        %s",
        b0 ? "true " : "false", b1 ? "true " : "false",
        b2 ? "true " : "false", b3 ? "true " : "false");
    menu_transmit(buffer);
}

void debug_print_custom(void)
{
    // have your own dedebug
}

// initialization steps for debugging
void debug_init(void)
{

}

// loop for regular tasks related to debugging
void debug_loop(void)
{

}
