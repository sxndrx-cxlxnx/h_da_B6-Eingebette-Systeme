#ifndef _SAM3XA_TWI_COMPONENT_
#define _SAM3XA_TWI_COMPONENT_

/** \brief Twi hardware registers */
typedef struct Twi
{
    __O uint32_t TWI_CR;        /*! @brief [Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=736) */
    __IO uint32_t TWI_MMR;      /*! @brief [Master Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=738) */
    __IO uint32_t TWI_SMR;      /*! @brief [Slave Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=739) */
    __IO uint32_t TWI_IADR;     /*! @brief [Internal Address Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=740) */
    __IO uint32_t TWI_CWGR;     /*! @brief [Clock Waveform Generator Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=741) */
    __I uint32_t Reserved1[3];  /*! @brief reserved */
    __I uint32_t TWI_SR;        /*! @brief [Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=742) */
    __O uint32_t TWI_IER;       /*! @brief [Interrupt Enable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=745) */
    __O uint32_t TWI_IDR;       /*! @brief [Interrupt Disable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=746) */
    __I uint32_t TWI_IMR;       /*! @brief [Interrupt Mask Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=747) */
    __I uint32_t TWI_RHR;       /*! @brief [Receive Holding Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=748) */
    __O uint32_t TWI_THR;       /*! @brief [Transmit Holding Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=7409 */
    __I uint32_t Reserved2[50]; /*! @brief reserved */
    __IO uint32_t TWI_RPR;      /*! @brief [Receive Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=509) */
    __IO uint32_t TWI_RCR;      /*! @brief [Receive Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=510) */
    __IO uint32_t TWI_TPR;      /*! @brief [Transmit Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=511) */
    __IO uint32_t TWI_TCR;      /*! @brief [Transmit Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=512) */
    __IO uint32_t TWI_RNPR;     /*! @brief [Receive Next Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=513) */
    __IO uint32_t TWI_RNCR;     /*! @brief [Receive Next Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=514) */
    __IO uint32_t TWI_TNPR;     /*! @brief [Transmit Next Pointer Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=515) */
    __IO uint32_t TWI_TNCR;     /*! @brief [Transmit Next Counter Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=516) */
    __O uint32_t TWI_PTCR;      /*! @brief [Transfer Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=517) */
    __I uint32_t TWI_PTSR;      /*! @brief [Transfer Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=518) */
} Twi;

#define TWI_CR_START (0x1u << 0)
#define TWI_CR_STOP (0x1u << 1)
#define TWI_CR_MSEN (0x1u << 2)
#define TWI_CR_MSDIS (0x1u << 3)
#define TWI_CR_SVEN (0x1u << 4)
#define TWI_CR_SVDIS (0x1u << 5)
#define TWI_CR_QUICK (0x1u << 6)
#define TWI_CR_SWRST (0x1u << 7)

#define TWI_MMR_IADRSZ_Pos 8
#define TWI_MMR_IADRSZ_Msk (0x3u << TWI_MMR_IADRSZ_Pos)
#define TWI_MMR_IADRSZ_NONE (0x0u << 8)
#define TWI_MMR_IADRSZ_1_BYTE (0x1u << 8)
#define TWI_MMR_IADRSZ_2_BYTE (0x2u << 8)
#define TWI_MMR_IADRSZ_3_BYTE (0x3u << 8)
#define TWI_MMR_MREAD (0x1u << 12)
#define TWI_MMR_DADR_Pos 16
#define TWI_MMR_DADR_Msk (0x7fu << TWI_MMR_DADR_Pos)
#define TWI_MMR_DADR(value) ((TWI_MMR_DADR_Msk & ((value) << TWI_MMR_DADR_Pos)))

#define TWI_SMR_SADR_Pos 16
#define TWI_SMR_SADR_Msk (0x7fu << TWI_SMR_SADR_Pos)
#define TWI_SMR_SADR(value) ((TWI_SMR_SADR_Msk & ((value) << TWI_SMR_SADR_Pos)))

#define TWI_IADR_IADR_Pos 0
#define TWI_IADR_IADR_Msk (0xffffffu << TWI_IADR_IADR_Pos)
#define TWI_IADR_IADR(value) ((TWI_IADR_IADR_Msk & ((value) << TWI_IADR_IADR_Pos)))

#define TWI_CWGR_CLDIV_Pos 0
#define TWI_CWGR_CLDIV_Msk (0xffu << TWI_CWGR_CLDIV_Pos)
#define TWI_CWGR_CLDIV(value) ((TWI_CWGR_CLDIV_Msk & ((value) << TWI_CWGR_CLDIV_Pos)))
#define TWI_CWGR_CHDIV_Pos 8
#define TWI_CWGR_CHDIV_Msk (0xffu << TWI_CWGR_CHDIV_Pos)
#define TWI_CWGR_CHDIV(value) ((TWI_CWGR_CHDIV_Msk & ((value) << TWI_CWGR_CHDIV_Pos)))
#define TWI_CWGR_CKDIV_Pos 16
#define TWI_CWGR_CKDIV_Msk (0x7u << TWI_CWGR_CKDIV_Pos)
#define TWI_CWGR_CKDIV(value) ((TWI_CWGR_CKDIV_Msk & ((value) << TWI_CWGR_CKDIV_Pos)))

#define TWI_SR_TXCOMP (0x1u << 0)
#define TWI_SR_RXRDY (0x1u << 1)
#define TWI_SR_TXRDY (0x1u << 2)
#define TWI_SR_SVREAD (0x1u << 3)
#define TWI_SR_SVACC (0x1u << 4)
#define TWI_SR_GACC (0x1u << 5)
#define TWI_SR_OVRE (0x1u << 6)
#define TWI_SR_NACK (0x1u << 8)
#define TWI_SR_ARBLST (0x1u << 9)
#define TWI_SR_SCLWS (0x1u << 10)
#define TWI_SR_EOSACC (0x1u << 11)
#define TWI_SR_ENDRX (0x1u << 12)
#define TWI_SR_ENDTX (0x1u << 13)
#define TWI_SR_RXBUFF (0x1u << 14)
#define TWI_SR_TXBUFE (0x1u << 15)

#define TWI_IER_TXCOMP (0x1u << 0)
#define TWI_IER_RXRDY (0x1u << 1)
#define TWI_IER_TXRDY (0x1u << 2)
#define TWI_IER_SVACC (0x1u << 4)
#define TWI_IER_GACC (0x1u << 5)
#define TWI_IER_OVRE (0x1u << 6)
#define TWI_IER_NACK (0x1u << 8)
#define TWI_IER_ARBLST (0x1u << 9)
#define TWI_IER_SCL_WS (0x1u << 10)
#define TWI_IER_EOSACC (0x1u << 11)
#define TWI_IER_ENDRX (0x1u << 12)
#define TWI_IER_ENDTX (0x1u << 13)
#define TWI_IER_RXBUFF (0x1u << 14)
#define TWI_IER_TXBUFE (0x1u << 15)

#define TWI_IDR_TXCOMP (0x1u << 0)
#define TWI_IDR_RXRDY (0x1u << 1)
#define TWI_IDR_TXRDY (0x1u << 2)
#define TWI_IDR_SVACC (0x1u << 4)
#define TWI_IDR_GACC (0x1u << 5)
#define TWI_IDR_OVRE (0x1u << 6)
#define TWI_IDR_NACK (0x1u << 8)
#define TWI_IDR_ARBLST (0x1u << 9)
#define TWI_IDR_SCL_WS (0x1u << 10)
#define TWI_IDR_EOSACC (0x1u << 11)
#define TWI_IDR_ENDRX (0x1u << 12)
#define TWI_IDR_ENDTX (0x1u << 13)
#define TWI_IDR_RXBUFF (0x1u << 14)
#define TWI_IDR_TXBUFE (0x1u << 15)

#define TWI_IMR_TXCOMP (0x1u << 0)
#define TWI_IMR_RXRDY (0x1u << 1)
#define TWI_IMR_TXRDY (0x1u << 2)
#define TWI_IMR_SVACC (0x1u << 4)
#define TWI_IMR_GACC (0x1u << 5)
#define TWI_IMR_OVRE (0x1u << 6)
#define TWI_IMR_NACK (0x1u << 8)
#define TWI_IMR_ARBLST (0x1u << 9)
#define TWI_IMR_SCL_WS (0x1u << 10)
#define TWI_IMR_EOSACC (0x1u << 11)
#define TWI_IMR_ENDRX (0x1u << 12)
#define TWI_IMR_ENDTX (0x1u << 13)
#define TWI_IMR_RXBUFF (0x1u << 14)
#define TWI_IMR_TXBUFE (0x1u << 15)

#define TWI_RHR_RXDATA_Pos 0
#define TWI_RHR_RXDATA_Msk (0xffu << TWI_RHR_RXDATA_Pos)

#define TWI_THR_TXDATA_Pos 0
#define TWI_THR_TXDATA_Msk (0xffu << TWI_THR_TXDATA_Pos)
#define TWI_THR_TXDATA(value) ((TWI_THR_TXDATA_Msk & ((value) << TWI_THR_TXDATA_Pos)))

#define TWI_RPR_RXPTR_Pos 0
#define TWI_RPR_RXPTR_Msk (0xffffffffu << TWI_RPR_RXPTR_Pos)
#define TWI_RPR_RXPTR(value) ((TWI_RPR_RXPTR_Msk & ((value) << TWI_RPR_RXPTR_Pos)))

#define TWI_RCR_RXCTR_Pos 0
#define TWI_RCR_RXCTR_Msk (0xffffu << TWI_RCR_RXCTR_Pos)
#define TWI_RCR_RXCTR(value) ((TWI_RCR_RXCTR_Msk & ((value) << TWI_RCR_RXCTR_Pos)))

#define TWI_TPR_TXPTR_Pos 0
#define TWI_TPR_TXPTR_Msk (0xffffffffu << TWI_TPR_TXPTR_Pos)
#define TWI_TPR_TXPTR(value) ((TWI_TPR_TXPTR_Msk & ((value) << TWI_TPR_TXPTR_Pos)))

#define TWI_TCR_TXCTR_Pos 0
#define TWI_TCR_TXCTR_Msk (0xffffu << TWI_TCR_TXCTR_Pos)
#define TWI_TCR_TXCTR(value) ((TWI_TCR_TXCTR_Msk & ((value) << TWI_TCR_TXCTR_Pos)))

#define TWI_RNPR_RXNPTR_Pos 0
#define TWI_RNPR_RXNPTR_Msk (0xffffffffu << TWI_RNPR_RXNPTR_Pos)
#define TWI_RNPR_RXNPTR(value) ((TWI_RNPR_RXNPTR_Msk & ((value) << TWI_RNPR_RXNPTR_Pos)))

#define TWI_RNCR_RXNCTR_Pos 0
#define TWI_RNCR_RXNCTR_Msk (0xffffu << TWI_RNCR_RXNCTR_Pos)
#define TWI_RNCR_RXNCTR(value) ((TWI_RNCR_RXNCTR_Msk & ((value) << TWI_RNCR_RXNCTR_Pos)))

#define TWI_TNPR_TXNPTR_Pos 0
#define TWI_TNPR_TXNPTR_Msk (0xffffffffu << TWI_TNPR_TXNPTR_Pos)
#define TWI_TNPR_TXNPTR(value) ((TWI_TNPR_TXNPTR_Msk & ((value) << TWI_TNPR_TXNPTR_Pos)))

#define TWI_TNCR_TXNCTR_Pos 0
#define TWI_TNCR_TXNCTR_Msk (0xffffu << TWI_TNCR_TXNCTR_Pos)
#define TWI_TNCR_TXNCTR(value) ((TWI_TNCR_TXNCTR_Msk & ((value) << TWI_TNCR_TXNCTR_Pos)))

#define TWI_PTCR_RXTEN (0x1u << 0)
#define TWI_PTCR_RXTDIS (0x1u << 1)
#define TWI_PTCR_TXTEN (0x1u << 8)
#define TWI_PTCR_TXTDIS (0x1u << 9)

#define TWI_PTSR_RXTEN (0x1u << 0)
#define TWI_PTSR_TXTEN (0x1u << 8)

#endif /* _SAM3XA_TWI_COMPONENT_ */
