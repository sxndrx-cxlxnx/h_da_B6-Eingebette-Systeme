#ifndef _SAM3XA_USART_COMPONENT_
#define _SAM3XA_USART_COMPONENT_

/*! @brief [Universal Synchronous Asynchronous Receiver Transmitter](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=769) */
typedef struct {
  __O  uint32_t US_CR;         /*! @brief [Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=824) */
  __IO uint32_t US_MR;         /*! @brief [Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=827) */
  __O  uint32_t US_IER;        /*! @brief [Interrupt Enable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=831) */
  __O  uint32_t US_IDR;        /*! @brief [Interrupt Disable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=833) */
  __I  uint32_t US_IMR;        /*! @brief [Interrupt Mask Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=835) */
  __I  uint32_t US_CSR;        /*! @brief [Channel Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=837) */
  __I  uint32_t US_RHR;        /*! @brief [Receive Holding Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=841) */
  __O  uint32_t US_THR;        /*! @brief [Transmit Holding Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=842) */
  __IO uint32_t US_BRGR;       /*! @brief [Baud Rate Generator Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=843) */
  __IO uint32_t US_RTOR;       /*! @brief [Receiver Time-out Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=844) */
  __IO uint32_t US_TTGR;       /*! @brief [Transmitter Timeguard Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=845) */
  __I  uint32_t Reserved1[5];
  __IO uint32_t US_FIDI;       /*! @brief [FI DI Ratio Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=846) */
  __I  uint32_t US_NER;        /*! @brief [Number of Errors Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=847) */
  __I  uint32_t Reserved2[1];
  __IO uint32_t US_IF;         /*! @brief [IrDA Filter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=848) */
  __IO uint32_t US_MAN;        /*! @brief [Manchester Configuration Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=849) */
  __IO uint32_t US_LINMR;      /*! @brief [LIN Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=851) */
  __IO uint32_t US_LINIR;      /*! @brief [LIN Identifier Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=853) */
  __I  uint32_t US_LINBRR;     /*! @brief LIN Baud Rate Register */
  __I  uint32_t Reserved3[33];
  __IO uint32_t US_WPMR;       /*! @brief [Write Protection Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=854) */
  __I  uint32_t US_WPSR;       /*! @brief [Write Protection Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=855) */
  __I  uint32_t Reserved4[5];
  __IO uint32_t US_RPR;        /*! @brief [Receive Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=509) */
  __IO uint32_t US_RCR;        /*! @brief [Receive Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=510) */
  __IO uint32_t US_TPR;        /*! @brief [Transmit Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=511) */
  __IO uint32_t US_TCR;        /*! @brief [Transmit Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=512) */
  __IO uint32_t US_RNPR;       /*! @brief [Receive Next Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=513) */
  __IO uint32_t US_RNCR;       /*! @brief [Receive Next Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=514) */
  __IO uint32_t US_TNPR;       /*! @brief [Transmit Next Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=515) */
  __IO uint32_t US_TNCR;       /*! @brief [Transmit Next Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=516) */
  __O  uint32_t US_PTCR;       /*! @brief [Transfer Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=517) */
  __I  uint32_t US_PTSR;       /*! @brief [Transfer Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=518) */
} Usart;

#define US_CR_RSTRX (0x1u << 2) 
#define US_CR_RSTTX (0x1u << 3) 
#define US_CR_RXEN (0x1u << 4) 
#define US_CR_RXDIS (0x1u << 5) 
#define US_CR_TXEN (0x1u << 6) 
#define US_CR_TXDIS (0x1u << 7) 
#define US_CR_RSTSTA (0x1u << 8) 
#define US_CR_STTBRK (0x1u << 9) 
#define US_CR_STPBRK (0x1u << 10) 
#define US_CR_STTTO (0x1u << 11) 
#define US_CR_SENDA (0x1u << 12) 
#define US_CR_RSTIT (0x1u << 13) 
#define US_CR_RSTNACK (0x1u << 14) 
#define US_CR_RETTO (0x1u << 15) 
#define US_CR_RTSEN (0x1u << 18) 
#define US_CR_RTSDIS (0x1u << 19) 
#define US_CR_LINABT (0x1u << 20) 
#define US_CR_LINWKUP (0x1u << 21) 
#define US_CR_FCS (0x1u << 18) 
#define US_CR_RCS (0x1u << 19) 

#define US_MR_USART_MODE_Pos 0
#define US_MR_USART_MODE_Msk (0xfu << US_MR_USART_MODE_Pos) 
#define   US_MR_USART_MODE_NORMAL (0x0u << 0) 
#define   US_MR_USART_MODE_RS485 (0x1u << 0) 
#define   US_MR_USART_MODE_HW_HANDSHAKING (0x2u << 0) 
#define   US_MR_USART_MODE_ISO7816_T_0 (0x4u << 0) 
#define   US_MR_USART_MODE_ISO7816_T_1 (0x6u << 0) 
#define   US_MR_USART_MODE_IRDA (0x8u << 0) 
#define   US_MR_USART_MODE_LIN_MASTER (0xAu << 0) 
#define   US_MR_USART_MODE_LIN_SLAVE (0xBu << 0) 
#define   US_MR_USART_MODE_SPI_MASTER (0xEu << 0) 
#define   US_MR_USART_MODE_SPI_SLAVE (0xFu << 0) 
#define US_MR_USCLKS_Pos 4
#define US_MR_USCLKS_Msk (0x3u << US_MR_USCLKS_Pos) 
#define   US_MR_USCLKS_MCK (0x0u << 4) 
#define   US_MR_USCLKS_DIV (0x1u << 4) 
#define   US_MR_USCLKS_SCK (0x3u << 4) 
#define US_MR_CHRL_Pos 6
#define US_MR_CHRL_Msk (0x3u << US_MR_CHRL_Pos) 
#define   US_MR_CHRL_5_BIT (0x0u << 6) 
#define   US_MR_CHRL_6_BIT (0x1u << 6) 
#define   US_MR_CHRL_7_BIT (0x2u << 6) 
#define   US_MR_CHRL_8_BIT (0x3u << 6) 
#define US_MR_SYNC (0x1u << 8) 
#define US_MR_PAR_Pos 9
#define US_MR_PAR_Msk (0x7u << US_MR_PAR_Pos) 
#define   US_MR_PAR_EVEN (0x0u << 9) 
#define   US_MR_PAR_ODD (0x1u << 9) 
#define   US_MR_PAR_SPACE (0x2u << 9) 
#define   US_MR_PAR_MARK (0x3u << 9) 
#define   US_MR_PAR_NO (0x4u << 9) 
#define   US_MR_PAR_MULTIDROP (0x6u << 9) 
#define US_MR_NBSTOP_Pos 12
#define US_MR_NBSTOP_Msk (0x3u << US_MR_NBSTOP_Pos) 
#define   US_MR_NBSTOP_1_BIT (0x0u << 12) 
#define   US_MR_NBSTOP_1_5_BIT (0x1u << 12) 
#define   US_MR_NBSTOP_2_BIT (0x2u << 12) 
#define US_MR_CHMODE_Pos 14
#define US_MR_CHMODE_Msk (0x3u << US_MR_CHMODE_Pos) 
#define   US_MR_CHMODE_NORMAL (0x0u << 14) 
#define   US_MR_CHMODE_AUTOMATIC (0x1u << 14) 
#define   US_MR_CHMODE_LOCAL_LOOPBACK (0x2u << 14) 
#define   US_MR_CHMODE_REMOTE_LOOPBACK (0x3u << 14) 
#define US_MR_MSBF (0x1u << 16) 
#define US_MR_MODE9 (0x1u << 17) 
#define US_MR_CLKO (0x1u << 18) 
#define US_MR_OVER (0x1u << 19) 
#define US_MR_INACK (0x1u << 20) 
#define US_MR_DSNACK (0x1u << 21) 
#define US_MR_VAR_SYNC (0x1u << 22) 
#define US_MR_INVDATA (0x1u << 23) 
#define US_MR_MAX_ITERATION_Pos 24
#define US_MR_MAX_ITERATION_Msk (0x7u << US_MR_MAX_ITERATION_Pos) 
#define US_MR_MAX_ITERATION(value) ((US_MR_MAX_ITERATION_Msk & ((value) << US_MR_MAX_ITERATION_Pos)))
#define US_MR_FILTER (0x1u << 28) 
#define US_MR_MAN (0x1u << 29) 
#define US_MR_MODSYNC (0x1u << 30) 
#define US_MR_ONEBIT (0x1u << 31) 
#define US_MR_CPHA (0x1u << 8) 
#define US_MR_CPOL (0x1u << 16) 
#define US_MR_WRDBT (0x1u << 20) 

#define US_IER_RXRDY (0x1u << 0) 
#define US_IER_TXRDY (0x1u << 1) 
#define US_IER_RXBRK (0x1u << 2) 
#define US_IER_ENDRX (0x1u << 3) 
#define US_IER_ENDTX (0x1u << 4) 
#define US_IER_OVRE (0x1u << 5) 
#define US_IER_FRAME (0x1u << 6) 
#define US_IER_PARE (0x1u << 7) 
#define US_IER_TIMEOUT (0x1u << 8) 
#define US_IER_TXEMPTY (0x1u << 9) 
#define US_IER_ITER (0x1u << 10) 
#define US_IER_TXBUFE (0x1u << 11) 
#define US_IER_RXBUFF (0x1u << 12) 
#define US_IER_NACK (0x1u << 13) 
#define US_IER_CTSIC (0x1u << 19) 
#define US_IER_MANE (0x1u << 24) 
#define US_IER_UNRE (0x1u << 10) 
#define US_IER_LINBK (0x1u << 13) 
#define US_IER_LINID (0x1u << 14) 
#define US_IER_LINTC (0x1u << 15) 
#define US_IER_LINBE (0x1u << 25) 
#define US_IER_LINISFE (0x1u << 26) 
#define US_IER_LINIPE (0x1u << 27) 
#define US_IER_LINCE (0x1u << 28) 
#define US_IER_LINSNRE (0x1u << 29) 

#define US_IDR_RXRDY (0x1u << 0) 
#define US_IDR_TXRDY (0x1u << 1) 
#define US_IDR_RXBRK (0x1u << 2) 
#define US_IDR_ENDRX (0x1u << 3) 
#define US_IDR_ENDTX (0x1u << 4) 
#define US_IDR_OVRE (0x1u << 5) 
#define US_IDR_FRAME (0x1u << 6) 
#define US_IDR_PARE (0x1u << 7) 
#define US_IDR_TIMEOUT (0x1u << 8) 
#define US_IDR_TXEMPTY (0x1u << 9) 
#define US_IDR_ITER (0x1u << 10) 
#define US_IDR_TXBUFE (0x1u << 11) 
#define US_IDR_RXBUFF (0x1u << 12) 
#define US_IDR_NACK (0x1u << 13) 
#define US_IDR_CTSIC (0x1u << 19) 
#define US_IDR_MANE (0x1u << 24) 
#define US_IDR_UNRE (0x1u << 10) 
#define US_IDR_LINBK (0x1u << 13) 
#define US_IDR_LINID (0x1u << 14) 
#define US_IDR_LINTC (0x1u << 15) 
#define US_IDR_LINBE (0x1u << 25) 
#define US_IDR_LINISFE (0x1u << 26) 
#define US_IDR_LINIPE (0x1u << 27) 
#define US_IDR_LINCE (0x1u << 28) 
#define US_IDR_LINSNRE (0x1u << 29) 

#define US_IMR_RXRDY (0x1u << 0) 
#define US_IMR_TXRDY (0x1u << 1) 
#define US_IMR_RXBRK (0x1u << 2) 
#define US_IMR_ENDRX (0x1u << 3) 
#define US_IMR_ENDTX (0x1u << 4) 
#define US_IMR_OVRE (0x1u << 5) 
#define US_IMR_FRAME (0x1u << 6) 
#define US_IMR_PARE (0x1u << 7) 
#define US_IMR_TIMEOUT (0x1u << 8) 
#define US_IMR_TXEMPTY (0x1u << 9) 
#define US_IMR_ITER (0x1u << 10) 
#define US_IMR_TXBUFE (0x1u << 11) 
#define US_IMR_RXBUFF (0x1u << 12) 
#define US_IMR_NACK (0x1u << 13) 
#define US_IMR_CTSIC (0x1u << 19) 
#define US_IMR_MANE (0x1u << 24) 
#define US_IMR_UNRE (0x1u << 10) 
#define US_IMR_LINBK (0x1u << 13) 
#define US_IMR_LINID (0x1u << 14) 
#define US_IMR_LINTC (0x1u << 15) 
#define US_IMR_LINBE (0x1u << 25) 
#define US_IMR_LINISFE (0x1u << 26) 
#define US_IMR_LINIPE (0x1u << 27) 
#define US_IMR_LINCE (0x1u << 28) 
#define US_IMR_LINSNRE (0x1u << 29) 

#define US_CSR_RXRDY (0x1u << 0) 
#define US_CSR_TXRDY (0x1u << 1) 
#define US_CSR_RXBRK (0x1u << 2) 
#define US_CSR_ENDRX (0x1u << 3) 
#define US_CSR_ENDTX (0x1u << 4) 
#define US_CSR_OVRE (0x1u << 5) 
#define US_CSR_FRAME (0x1u << 6) 
#define US_CSR_PARE (0x1u << 7) 
#define US_CSR_TIMEOUT (0x1u << 8) 
#define US_CSR_TXEMPTY (0x1u << 9) 
#define US_CSR_ITER (0x1u << 10) 
#define US_CSR_TXBUFE (0x1u << 11) 
#define US_CSR_RXBUFF (0x1u << 12) 
#define US_CSR_NACK (0x1u << 13) 
#define US_CSR_CTSIC (0x1u << 19) 
#define US_CSR_CTS (0x1u << 23) 
#define US_CSR_MANERR (0x1u << 24) 
#define US_CSR_UNRE (0x1u << 10) 
#define US_CSR_LINBK (0x1u << 13) 
#define US_CSR_LINID (0x1u << 14) 
#define US_CSR_LINTC (0x1u << 15) 
#define US_CSR_LINBLS (0x1u << 23) 
#define US_CSR_LINBE (0x1u << 25) 
#define US_CSR_LINISFE (0x1u << 26) 
#define US_CSR_LINIPE (0x1u << 27) 
#define US_CSR_LINCE (0x1u << 28) 
#define US_CSR_LINSNRE (0x1u << 29) 

#define US_RHR_RXCHR_Pos 0
#define US_RHR_RXCHR_Msk (0x1ffu << US_RHR_RXCHR_Pos) 
#define US_RHR_RXSYNH (0x1u << 15) 

#define US_THR_TXCHR_Pos 0
#define US_THR_TXCHR_Msk (0x1ffu << US_THR_TXCHR_Pos) 
#define US_THR_TXCHR(value) ((US_THR_TXCHR_Msk & ((value) << US_THR_TXCHR_Pos)))
#define US_THR_TXSYNH (0x1u << 15) 

#define US_BRGR_CD_Pos 0
#define US_BRGR_CD_Msk (0xffffu << US_BRGR_CD_Pos) 
#define US_BRGR_CD(value) ((US_BRGR_CD_Msk & ((value) << US_BRGR_CD_Pos)))
#define US_BRGR_FP_Pos 16
#define US_BRGR_FP_Msk (0x7u << US_BRGR_FP_Pos) 
#define US_BRGR_FP(value) ((US_BRGR_FP_Msk & ((value) << US_BRGR_FP_Pos)))

#define US_RTOR_TO_Pos 0
#define US_RTOR_TO_Msk (0x1ffffu << US_RTOR_TO_Pos) 
#define US_RTOR_TO(value) ((US_RTOR_TO_Msk & ((value) << US_RTOR_TO_Pos)))

#define US_TTGR_TG_Pos 0
#define US_TTGR_TG_Msk (0xffu << US_TTGR_TG_Pos) 
#define US_TTGR_TG(value) ((US_TTGR_TG_Msk & ((value) << US_TTGR_TG_Pos)))

#define US_FIDI_FI_DI_RATIO_Pos 0
#define US_FIDI_FI_DI_RATIO_Msk (0x7ffu << US_FIDI_FI_DI_RATIO_Pos) 
#define US_FIDI_FI_DI_RATIO(value) ((US_FIDI_FI_DI_RATIO_Msk & ((value) << US_FIDI_FI_DI_RATIO_Pos)))

#define US_NER_NB_ERRORS_Pos 0
#define US_NER_NB_ERRORS_Msk (0xffu << US_NER_NB_ERRORS_Pos) 

#define US_IF_IRDA_FILTER_Pos 0
#define US_IF_IRDA_FILTER_Msk (0xffu << US_IF_IRDA_FILTER_Pos) 
#define US_IF_IRDA_FILTER(value) ((US_IF_IRDA_FILTER_Msk & ((value) << US_IF_IRDA_FILTER_Pos)))

#define US_MAN_TX_PL_Pos 0
#define US_MAN_TX_PL_Msk (0xfu << US_MAN_TX_PL_Pos) 
#define US_MAN_TX_PL(value) ((US_MAN_TX_PL_Msk & ((value) << US_MAN_TX_PL_Pos)))
#define US_MAN_TX_PP_Pos 8
#define US_MAN_TX_PP_Msk (0x3u << US_MAN_TX_PP_Pos) 
#define   US_MAN_TX_PP_ALL_ONE (0x0u << 8) 
#define   US_MAN_TX_PP_ALL_ZERO (0x1u << 8) 
#define   US_MAN_TX_PP_ZERO_ONE (0x2u << 8) 
#define   US_MAN_TX_PP_ONE_ZERO (0x3u << 8) 
#define US_MAN_TX_MPOL (0x1u << 12) 
#define US_MAN_RX_PL_Pos 16
#define US_MAN_RX_PL_Msk (0xfu << US_MAN_RX_PL_Pos) 
#define US_MAN_RX_PL(value) ((US_MAN_RX_PL_Msk & ((value) << US_MAN_RX_PL_Pos)))
#define US_MAN_RX_PP_Pos 24
#define US_MAN_RX_PP_Msk (0x3u << US_MAN_RX_PP_Pos) 
#define   US_MAN_RX_PP_ALL_ONE (0x0u << 24) 
#define   US_MAN_RX_PP_ALL_ZERO (0x1u << 24) 
#define   US_MAN_RX_PP_ZERO_ONE (0x2u << 24) 
#define   US_MAN_RX_PP_ONE_ZERO (0x3u << 24) 
#define US_MAN_RX_MPOL (0x1u << 28) 
#define US_MAN_ONE (0x1u << 29) 
#define US_MAN_DRIFT (0x1u << 30) 

#define US_LINMR_NACT_Pos 0
#define US_LINMR_NACT_Msk (0x3u << US_LINMR_NACT_Pos) 
#define   US_LINMR_NACT_PUBLISH (0x0u << 0) 
#define   US_LINMR_NACT_SUBSCRIBE (0x1u << 0) 
#define   US_LINMR_NACT_IGNORE (0x2u << 0) 
#define US_LINMR_PARDIS (0x1u << 2) 
#define US_LINMR_CHKDIS (0x1u << 3) 
#define US_LINMR_CHKTYP (0x1u << 4) 
#define US_LINMR_DLM (0x1u << 5) 
#define US_LINMR_FSDIS (0x1u << 6) 
#define US_LINMR_WKUPTYP (0x1u << 7) 
#define US_LINMR_DLC_Pos 8
#define US_LINMR_DLC_Msk (0xffu << US_LINMR_DLC_Pos) 
#define US_LINMR_DLC(value) ((US_LINMR_DLC_Msk & ((value) << US_LINMR_DLC_Pos)))
#define US_LINMR_PDCM (0x1u << 16) 

#define US_LINIR_IDCHR_Pos 0
#define US_LINIR_IDCHR_Msk (0xffu << US_LINIR_IDCHR_Pos) 
#define US_LINIR_IDCHR(value) ((US_LINIR_IDCHR_Msk & ((value) << US_LINIR_IDCHR_Pos)))

#define US_LINBRR_LINCD_Pos 0
#define US_LINBRR_LINCD_Msk (0xffffu << US_LINBRR_LINCD_Pos) 
#define US_LINBRR_LINFP_Pos 16
#define US_LINBRR_LINFP_Msk (0x7u << US_LINBRR_LINFP_Pos) 

#define US_WPMR_WPEN (0x1u << 0) 
#define US_WPMR_WPKEY_Pos 8
#define US_WPMR_WPKEY_Msk (0xffffffu << US_WPMR_WPKEY_Pos) 
#define   US_WPMR_WPKEY_PASSWD (0x555341u << 8) 

#define US_WPSR_WPVS (0x1u << 0) 
#define US_WPSR_WPVSRC_Pos 8
#define US_WPSR_WPVSRC_Msk (0xffffu << US_WPSR_WPVSRC_Pos) 

#define US_RPR_RXPTR_Pos 0
#define US_RPR_RXPTR_Msk (0xffffffffu << US_RPR_RXPTR_Pos) 
#define US_RPR_RXPTR(value) ((US_RPR_RXPTR_Msk & ((value) << US_RPR_RXPTR_Pos)))

#define US_RCR_RXCTR_Pos 0
#define US_RCR_RXCTR_Msk (0xffffu << US_RCR_RXCTR_Pos) 
#define US_RCR_RXCTR(value) ((US_RCR_RXCTR_Msk & ((value) << US_RCR_RXCTR_Pos)))

#define US_TPR_TXPTR_Pos 0
#define US_TPR_TXPTR_Msk (0xffffffffu << US_TPR_TXPTR_Pos) 
#define US_TPR_TXPTR(value) ((US_TPR_TXPTR_Msk & ((value) << US_TPR_TXPTR_Pos)))

#define US_TCR_TXCTR_Pos 0
#define US_TCR_TXCTR_Msk (0xffffu << US_TCR_TXCTR_Pos) 
#define US_TCR_TXCTR(value) ((US_TCR_TXCTR_Msk & ((value) << US_TCR_TXCTR_Pos)))

#define US_RNPR_RXNPTR_Pos 0
#define US_RNPR_RXNPTR_Msk (0xffffffffu << US_RNPR_RXNPTR_Pos) 
#define US_RNPR_RXNPTR(value) ((US_RNPR_RXNPTR_Msk & ((value) << US_RNPR_RXNPTR_Pos)))

#define US_RNCR_RXNCTR_Pos 0
#define US_RNCR_RXNCTR_Msk (0xffffu << US_RNCR_RXNCTR_Pos) 
#define US_RNCR_RXNCTR(value) ((US_RNCR_RXNCTR_Msk & ((value) << US_RNCR_RXNCTR_Pos)))

#define US_TNPR_TXNPTR_Pos 0
#define US_TNPR_TXNPTR_Msk (0xffffffffu << US_TNPR_TXNPTR_Pos) 
#define US_TNPR_TXNPTR(value) ((US_TNPR_TXNPTR_Msk & ((value) << US_TNPR_TXNPTR_Pos)))

#define US_TNCR_TXNCTR_Pos 0
#define US_TNCR_TXNCTR_Msk (0xffffu << US_TNCR_TXNCTR_Pos) 
#define US_TNCR_TXNCTR(value) ((US_TNCR_TXNCTR_Msk & ((value) << US_TNCR_TXNCTR_Pos)))

#define US_PTCR_RXTEN (0x1u << 0) 
#define US_PTCR_RXTDIS (0x1u << 1) 
#define US_PTCR_TXTEN (0x1u << 8) 
#define US_PTCR_TXTDIS (0x1u << 9) 

#define US_PTSR_RXTEN (0x1u << 0) 
#define US_PTSR_TXTEN (0x1u << 8) 

#endif /* _SAM3XA_USART_COMPONENT_ */
