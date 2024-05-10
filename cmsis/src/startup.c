/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#include "sam3x8e.h"

/* Initialize segments */
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
int main(void);
/** \endcond */

void __libc_init_array(void);

/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M3 core handlers */
void NMI_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void RSTC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void RTC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void RTT_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void WDT_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void PMC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void EFC0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void EFC1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void UART_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SMC_INSTANCE_
void SMC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SMC_INSTANCE_ */
#ifdef _SAM3XA_SDRAMC_INSTANCE_
void SDRAMC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SDRAMC_INSTANCE_ */
void PIOA_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void PIOB_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_PIOC_INSTANCE_
void PIOC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOC_INSTANCE_ */
#ifdef _SAM3XA_PIOD_INSTANCE_
void PIOD_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOD_INSTANCE_ */
#ifdef _SAM3XA_PIOE_INSTANCE_
void PIOE_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOE_INSTANCE_ */
#ifdef _SAM3XA_PIOF_INSTANCE_
void PIOF_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOF_INSTANCE_ */
void USART0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void USART1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void USART2_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_USART3_INSTANCE_
void USART3_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_USART3_INSTANCE_ */
void HSMCI_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TWI0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TWI1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void SPI0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SPI1_INSTANCE_
void SPI1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SPI1_INSTANCE_ */
void SSC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC2_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC3_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC4_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TC5_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_TC2_INSTANCE_
void TC6_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_TC2_INSTANCE_ */
#ifdef _SAM3XA_TC2_INSTANCE_
void TC7_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_TC2_INSTANCE_ */
#ifdef _SAM3XA_TC2_INSTANCE_
void TC8_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_TC2_INSTANCE_ */
void PWM_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void ADC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void DACC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void DMAC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void UOTGHS_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void TRNG_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_EMAC_INSTANCE_
void EMAC_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_EMAC_INSTANCE_ */
void CAN0_Handler(void) __attribute__((weak, alias("Dummy_Handler")));
void CAN1_Handler(void) __attribute__((weak, alias("Dummy_Handler")));

/* Exception Table */
__attribute__((section(".vectors")))
const DeviceVectors exception_table = {

    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = (void *)(&_estack),

    .pfnReset_Handler = Reset_Handler,
    .pfnNMI_Handler = NMI_Handler,
    .pfnHardFault_Handler = HardFault_Handler,
    .pfnMemManage_Handler = MemManage_Handler,
    .pfnBusFault_Handler = BusFault_Handler,
    .pfnUsageFault_Handler = UsageFault_Handler,
    .pfnReserved1_Handler = 0UL, /* Reserved */
    .pfnReserved2_Handler = 0UL, /* Reserved */
    .pfnReserved3_Handler = 0UL, /* Reserved */
    .pfnReserved4_Handler = 0UL, /* Reserved */
    .pfnSVC_Handler = SVC_Handler,
    .pfnDebugMon_Handler = DebugMon_Handler,
    .pfnReserved5_Handler = 0UL, /* Reserved */
    .pfnPendSV_Handler = PendSV_Handler,
    .pfnSysTick_Handler = SysTick_Handler,

    /* Configurable interrupts */
    .pfnSUPC_Handler = SUPC_Handler, /* 0  Supply Controller */
    .pfnRSTC_Handler = RSTC_Handler, /* 1  Reset Controller */
    .pfnRTC_Handler = RTC_Handler,   /* 2  Real Time Clock */
    .pfnRTT_Handler = RTT_Handler,   /* 3  Real Time Timer */
    .pfnWDT_Handler = WDT_Handler,   /* 4  Watchdog Timer */
    .pfnPMC_Handler = PMC_Handler,   /* 5  Power Management Controller */
    .pfnEFC0_Handler = EFC0_Handler, /* 6  Enhanced Flash Controller 0 */
    .pfnEFC1_Handler = EFC1_Handler, /* 7  Enhanced Flash Controller 1 */
    .pfnUART_Handler = UART_Handler, /* 8  Universal Asynchronous Receiver Transceiver */
    .pfnSMC_Handler = SMC_Handler, /* 9  Static Memory Controller */
    .pvReserved10 = 0UL, /* 10 Reserved */
    .pfnPIOA_Handler = PIOA_Handler, /* 11 Parallel I/O Controller A, */
    .pfnPIOB_Handler = PIOB_Handler, /* 12 Parallel I/O Controller B */
    .pfnPIOC_Handler = PIOC_Handler, /* 13 Parallel I/O Controller C */
    .pfnPIOD_Handler = PIOD_Handler, /* 14 Parallel I/O Controller D */
    .pvReserved15 = 0UL, /* 15 Reserved */
    .pvReserved16 = 0UL, /* 16 Reserved */
    .pfnUSART0_Handler = USART0_Handler, /* 17 USART 0 */
    .pfnUSART1_Handler = USART1_Handler, /* 18 USART 1 */
    .pfnUSART2_Handler = USART2_Handler, /* 19 USART 2 */
    .pfnUSART3_Handler = USART3_Handler, /* 20 USART 3 */
    .pfnHSMCI_Handler = HSMCI_Handler, /* 21 Multimedia Card Interface */
    .pfnTWI0_Handler = TWI0_Handler,   /* 22 Two-Wire Interface 0 */
    .pfnTWI1_Handler = TWI1_Handler,   /* 23 Two-Wire Interface 1 */
    .pfnSPI0_Handler = SPI0_Handler,   /* 24 Serial Peripheral Interface */
    .pvReserved25 = 0UL, /* 25 Reserved */
    .pfnSSC_Handler = SSC_Handler, /* 26 Synchronous Serial Controller */
    .pfnTC0_Handler = TC0_Handler, /* 27 Timer Counter 0 */
    .pfnTC1_Handler = TC1_Handler, /* 28 Timer Counter 1 */
    .pfnTC2_Handler = TC2_Handler, /* 29 Timer Counter 2 */
    .pfnTC3_Handler = TC3_Handler, /* 30 Timer Counter 3 */
    .pfnTC4_Handler = TC4_Handler, /* 31 Timer Counter 4 */
    .pfnTC5_Handler = TC5_Handler, /* 32 Timer Counter 5 */
    .pfnTC6_Handler = TC6_Handler, /* 33 Timer Counter 6 */
    .pfnTC7_Handler = TC7_Handler, /* 34 Timer Counter 7 */
    .pfnTC8_Handler = TC8_Handler, /* 35 Timer Counter 8 */
    .pfnPWM_Handler = PWM_Handler,       /* 36 Pulse Width Modulation Controller */
    .pfnADC_Handler = ADC_Handler,       /* 37 ADC Controller */
    .pfnDACC_Handler = DACC_Handler,     /* 38 DAC Controller */
    .pfnDMAC_Handler = DMAC_Handler,     /* 39 DMA Controller */
    .pfnUOTGHS_Handler = UOTGHS_Handler, /* 40 USB OTG High Speed */
    .pfnTRNG_Handler = TRNG_Handler,     /* 41 True Random Number Generator */
    .pfnEMAC_Handler = EMAC_Handler, /* 42 Ethernet MAC */
    .pfnCAN0_Handler = CAN0_Handler, /* 43 CAN Controller 0 */
    .pfnCAN1_Handler = CAN1_Handler  /* 44 CAN Controller 1 */
};

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
__attribute__((naked)) void Reset_Handler(void)
{
    /* Set stack pointer to its correct address */
    asm("ldr sp, =_sfixed; ldr sp, [sp, #0]");

    /* Initialize the relocate segment */
    for (uint32_t *src = &_etext, *dest = &_srelocate, *end = &_erelocate; dest < end; src++, dest++)
    {
        *dest = *src;
    }

    /* Clear the zero segment */
    for (uint32_t *ptr = &_szero, *end = &_ezero; ptr <= end; ptr++)
    {
        *ptr = 0;
    }

    /* Set the exception table offset */
    if (&exception_table > (DeviceVectors *)0x20000000u)
    {
        SCB->VTOR = 0x1u << 29;
    }
    else
    {
        SCB->VTOR = (uint32_t)&exception_table;
    }

    /* Initialize the system */
    SystemInit();

    /* Disable the watchdog */
    WDT->WDT_MR = WDT_MR_WDDIS;

    /* Initialize the C library */
    __libc_init_array();

    /* Branch to main function */
    main();

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
    while (1)
    {
    }
}