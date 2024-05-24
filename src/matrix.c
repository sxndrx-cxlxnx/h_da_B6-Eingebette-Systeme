// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: matrix.c
// CONTENTS: implementation for all functions driving I2C LED matrix

#include "matrix.h"

#include <state.h>
#include <math.h>
#include <twi.h>
#include <sample.h>

#define MATRIX_ADDRESS 0x70
#define kHz *1000

void matrix_setup(Twi *const twi, const uint8_t device_address)
{
    const uint8_t input_sequence[] = {
        0x21, // internal system clock enable
        0xA0, // row output pin set
        0xE0, // dimming set
        0x81, // blinking set
    };
    for (uint32_t i = 0; i < sizeof(input_sequence); i++)
        twi_write(twi, device_address, input_sequence + i, 1);

    const uint8_t display_data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    twi_write(twi, MATRIX_ADDRESS, display_data, sizeof(display_data));
}

bool matrix_update(Twi *const twi, const uint8_t buffer[8])
{
    static uint8_t shadow[8];
    if (twi_check(twi, TWI_SR_TXBUFE))
    {
        uint8_t start = 0xFF;
        for (uint8_t i = 0; i < 8; i++)
        {
            if (buffer[i] != shadow[i] && start == 0xFF)
            {
                start = i;
            }

            if ((buffer[i] == shadow[i] && start != 0xFF) || (i == 7 && buffer[i] != shadow[i]))
            {
                uint8_t range = (i - start) * 2 - 1;
                if (i == 7 && buffer[i] != shadow[i])
                {
                    range += 2;
                }

                uint8_t message[range + 1];
                message[0] = start * 2; // display address
                for (uint8_t i = 0; i < sizeof(message) - 1; i++)
                {
                    if (i % 2)
                    {
                        message[i + 1] = 0x00;
                    }
                    else
                    {
                        message[i + 1] = buffer[start + i / 2];
                    }
                }

                if (sizeof(message) > 0) twi_write(twi, MATRIX_ADDRESS, message, sizeof(message));
                start = 0xFF;
            }

            if (buffer[i] != shadow[i])
            {
                shadow[i] = buffer[i];
            }
        }
        return true;
    }
    return false;
}

void matrix_progress(uint8_t*const buffer, const float progress)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (progress > i / 8. && progress < (i + 1) / 8.)
        {
            uint8_t power = round((progress - i / 8.) * 64);
            buffer[i] = (1 << (power)) - 1;
        }
        else if (progress > i / 8.)
        {
            buffer[i] = 0xFF;
        }
        else
        {
            buffer[i] = 0x00;
        }
    }
}


// initialization steps for LED matrix
void matrix_init(void)
{
    matrix_setup(TWI1, MATRIX_ADDRESS);
}

// loop for regular tasks related to LED matrix
void matrix_loop(void)
{
    const uint8_t kreuz[8] = {
        0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81
    };
    const uint8_t dot[8] = {
        0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00
    };
    const uint8_t circleSmall[8] = {
        0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00
    };
    const uint8_t circleMedium[8] = {
        0x00, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00
    };
    const uint8_t circleBig[8] = {
        0x3C, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3C
    };
    //matrix_update(TWI1, circleBig);

    static int pic = 0;
    switch (pic){
        case 0:
        case 1:
        case 2: matrix_update(TWI1, dot);
                pic++;
                break;
        case 3:
        case 4:
        case 5: matrix_update(TWI1, circleSmall);
                pic++;
                break;
        case 6:
        case 7:
        case 8: matrix_update(TWI1, circleMedium);
                pic++;
                break;
        case 9:
        case 10:
        case 11: matrix_update(TWI1, circleBig);
                pic++;
                break;
        case 12:
        case 13:
        case 14: matrix_update(TWI1, circleMedium);
                pic++;
                break;
        case 15:
        case 16:
        case 17: matrix_update(TWI1, circleSmall);
                pic = 0;
                break;
        default: matrix_update(TWI1, kreuz);
    }

    /*
    static int pic = 0;
    switch (pic){
        case 0 ... 7:
            matrix_update(TWI1, dot);
            pic++;
            break;
        case 8 ... 15:
                matrix_update(TWI1, circleSmall);
                pic++;
                break;
        case 16 ... 23:
                matrix_update(TWI1, circleMedium);
                pic++;
                break;
        case 24 ... 31:
                matrix_update(TWI1, circleBig);
                pic++;
                break;
        case 32 ... 39:
                matrix_update(TWI1, circleMedium);
                pic++;
                break;
        case 40 ... 46:
                matrix_update(TWI1, circleSmall);
                pic++;
                break;
        case 47:
                matrix_update(TWI1, circleSmall);
                pic = 0;
                break;
        default: matrix_update(TWI1, kreuz);
    }
    */
}
