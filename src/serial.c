// Eingebettete Systeme  / Embedded Systems
// Embedded Distance Assistent (EDA)
// SEMESTER: SS24
// AUTHORS: David Heiss, Manfred Pester, Jens-Peter Akelbein
// FILE: serial.c
// CONTENTS: source of usart driver being used to interface
//           with PC / minicom via USART

#include <sam3x8e.h>
#include <serial.h>
#include <state.h>

// receives a character via serial device
bool serial_receive_char(char *const character, const bool blocking)
{
    // USART channel status register - if receiver is ready
    if (USART1->US_CSR & US_CSR_RXRDY)
    {
        // USART receive holding register - reading received character
        // reading RHR clears it for receiving next character
        *character = USART1->US_RHR;
        
        return true;
    }
    return false;
}

// transmits a character via serial device
bool serial_transmit_char(const char character, const bool blocking)
{
    // if the function should wait for former characters to be transmitted
    if ( blocking )
    {
        // wait till whether transmitter is ready so not character in THR
        while ( !(USART1->US_CSR & US_CSR_TXRDY) );
    }
    else
    {
        // non-blocking so return false
        if ( !( USART1->US_CSR & US_CSR_TXRDY)) return false;

    }
    // USART transmit holding register - write char in TCCHR field (bits 7..0)
    USART1->US_THR = (character & US_THR_TXCHR_Msk);

    // if the function should wait till character is transmitted
    if ( blocking )
    {
        // check whether transmitter is empty
        while (!(USART1->US_CSR & US_CSR_TXRDY));
    }
    return true;
}

// transmit (characterwise) a string of characters with a blocking behaviour
bool serial_transmit_string(const char *const string, const uint32_t size)
{
    // // index to the current character to be transmitted
    uint32_t index = 0;

    // wait till whether transmitter is empty from previous any character
    while (!(USART1->US_CSR & US_CSR_TXRDY));

    // while there are still characters to be transmitted
    while ( index < size)
    {
        // try transmitting with blocking behaviour
        if ( !serial_transmit_char(string[index], true) ) return false;

        // next character
        index++;
    }
    return true;
}

// initial config for serial so turn on usart for being ready to receive/transmit
// USART1 is being used for serial
void serial_init(void)
{
    // Power Management - turn on clock for USART1
    PMC->PMC_PCER0 = 1 << ID_USART1;

    // Disable PIO ports as USART1 is multiplexed and controlled by PIO_ABSR
    PIOA->PIO_PDR = PIO_PA12A_RXD1 |
                    PIO_PA13A_TXD1;

    // Enable USART as Peripheral A by writing 0 into port bits
    uint32_t mask = ~(PIO_PA12A_RXD1 | PIO_PA13A_TXD1);
    PIOA->PIO_ABSR = PIOA->PIO_ABSR & mask;

    // USART1 control register - disable device for configuration
    USART1->US_CR = US_CR_RSTRX |               // Resets the receiver
                    US_CR_RSTTX |               // Resets the transmitter
                    US_CR_RXDIS |               // Disables the receiver
                    US_CR_TXDIS |               // Disables the transmitter
                    US_CR_RSTSTA;               // Resets the status bits

    // USART1 DMA transfer control register - disable DMA transfers
    USART1->US_PTCR = US_PTCR_RXTDIS |          // Disables the PDC receiver channel requests
                      US_PTCR_TXTDIS;           // Disables the PDC transmitter channel requests

    // USART1 mode register - configure serial protocol
    USART1->US_MR = US_MR_USART_MODE_NORMAL |   // USART mode is in normal mode
                    US_MR_USCLKS_MCK |          // Master clock MCK is selected
                    US_MR_CHRL_8_BIT |          // Character length is 8 bits
                    US_MR_PAR_EVEN |            // Even parity
                    US_MR_NBSTOP_1_BIT;         // 1 stop bit

    // calculate clock divisor CD and fractional part FP
    const uint32_t USART1_SC = DUE_MCK;         // Due System Clock
    const uint32_t USART1_CD =                  // set Clock Divider
        USART1_SC / 16 / USART1_BAUDRATE;  
    const uint32_t USART1_FP =                  // set Fractional Part (FP * 1/8)
        (USART1_SC / 16. / USART1_BAUDRATE - USART1_CD) * 8 + 0.5;
    
    // USART1 baud rate generator register - set baudrate by CD and FP
    USART1->US_BRGR =                           // Baudrate = MCK / (CD + FP / 8)
        USART1_CD | USART1_FP << US_BRGR_FP_Pos;                           

    // USART1 control register - enable lines
    USART1->US_CR = US_CR_RXEN |                // Enables the receiver
                    US_CR_TXEN;                 // Enables the transmitter

    // USART1 DMA transfer control register - enable DMA transfers
    USART1->US_PTCR = US_PTCR_RXTEN |           // Enables the PDC receiver channel requests
                      US_PTCR_TXTEN;            // Enables the PDC transmitter channel requests
}

// loop for serial
void serial_loop()
{
}