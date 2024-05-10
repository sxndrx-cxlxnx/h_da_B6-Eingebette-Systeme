#ifndef _SAM3XA_TC_COMPONENT_
#define _SAM3XA_TC_COMPONENT_

/*! @brief [Timer Counter Channel](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=856) */
typedef struct TcChannel
{
  __O uint32_t TC_CCR;   /*! @brief [Channel Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=880) */
  __IO uint32_t TC_CMR;  /*! @brief Channel Mode Register ([Capture](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=881) / [Waveform](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=883)) */
  __IO uint32_t TC_SMMR; /*! @brief [Stepper Motor Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=887) */
  __I uint32_t Reserved1[1];
  __I uint32_t TC_CV;  /*! @brief [Counter Value](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=888) */
  __IO uint32_t TC_RA; /*! @brief [Register A](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=889) */
  __IO uint32_t TC_RB; /*! @brief [Register B](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=890) */
  __IO uint32_t TC_RC; /*! @brief [Register C](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=891) */
  __I uint32_t TC_SR;  /*! @brief [Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=892) */
  __O uint32_t TC_IER; /*! @brief [Interrupt Enable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=894) */
  __O uint32_t TC_IDR; /*! @brief [Interrupt Disable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=896) */
  __I uint32_t TC_IMR; /*! @brief [Interrupt Mask Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=898) */
  __I uint32_t Reserved2[4];
} TcChannel;

/** @brief [Timer Counter](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=856) */
typedef struct Tc
{
  TcChannel TC_CHANNEL[3];
  __O uint32_t TC_BCR;  /*! @brief [Block Control Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=900) */
  __IO uint32_t TC_BMR; /*! @brief [Block Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=901) */
  __O uint32_t TC_QIER; /*! @brief [QDEC Interrupt Enable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=903) */
  __O uint32_t TC_QIDR; /*! @brief [QDEC Interrupt Disable Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=904) */
  __I uint32_t TC_QIMR; /*! @brief [QDEC Interrupt Mask Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=905) */
  __I uint32_t TC_QISR; /*! @brief [QDEC Interrupt Status Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=906) */
  __IO uint32_t TC_FMR; /*! @brief [Fault Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=907) */
  __I uint32_t Reserved1[2];
  __IO uint32_t TC_WPMR; /*! @brief [Write Protect Mode Register](https://code.fbi.h-da.de/eingebettete-systeme/arduino-due/cmsis/-/raw/main/docs/datasheet.pdf#page=908) */
} Tc;

#define TC_CCR_CLKEN (0x1u << 0)
#define TC_CCR_CLKDIS (0x1u << 1)
#define TC_CCR_SWTRG (0x1u << 2)

#define TC_CMR_TCCLKS_Pos 0
#define TC_CMR_TCCLKS_Msk (0x7u << TC_CMR_TCCLKS_Pos)
#define TC_CMR_TCCLKS_TIMER_CLOCK1 (0x0u << 0)
#define TC_CMR_TCCLKS_TIMER_CLOCK2 (0x1u << 0)
#define TC_CMR_TCCLKS_TIMER_CLOCK3 (0x2u << 0)
#define TC_CMR_TCCLKS_TIMER_CLOCK4 (0x3u << 0)
#define TC_CMR_TCCLKS_TIMER_CLOCK5 (0x4u << 0)
#define TC_CMR_TCCLKS_XC0 (0x5u << 0)
#define TC_CMR_TCCLKS_XC1 (0x6u << 0)
#define TC_CMR_TCCLKS_XC2 (0x7u << 0)
#define TC_CMR_CLKI (0x1u << 3)
#define TC_CMR_BURST_Pos 4
#define TC_CMR_BURST_Msk (0x3u << TC_CMR_BURST_Pos)
#define TC_CMR_BURST_NONE (0x0u << 4)
#define TC_CMR_BURST_XC0 (0x1u << 4)
#define TC_CMR_BURST_XC1 (0x2u << 4)
#define TC_CMR_BURST_XC2 (0x3u << 4)
#define TC_CMR_LDBSTOP (0x1u << 6)
#define TC_CMR_LDBDIS (0x1u << 7)
#define TC_CMR_ETRGEDG_Pos 8
#define TC_CMR_ETRGEDG_Msk (0x3u << TC_CMR_ETRGEDG_Pos)
#define TC_CMR_ETRGEDG_NONE (0x0u << 8)
#define TC_CMR_ETRGEDG_RISING (0x1u << 8)
#define TC_CMR_ETRGEDG_FALLING (0x2u << 8)
#define TC_CMR_ETRGEDG_EDGE (0x3u << 8)
#define TC_CMR_ABETRG (0x1u << 10)
#define TC_CMR_CPCTRG (0x1u << 14)
#define TC_CMR_WAVE (0x1u << 15)
#define TC_CMR_LDRA_Pos 16
#define TC_CMR_LDRA_Msk (0x3u << TC_CMR_LDRA_Pos)
#define TC_CMR_LDRA_NONE (0x0u << 16)
#define TC_CMR_LDRA_RISING (0x1u << 16)
#define TC_CMR_LDRA_FALLING (0x2u << 16)
#define TC_CMR_LDRA_EDGE (0x3u << 16)
#define TC_CMR_LDRB_Pos 18
#define TC_CMR_LDRB_Msk (0x3u << TC_CMR_LDRB_Pos)
#define TC_CMR_LDRB_NONE (0x0u << 18)
#define TC_CMR_LDRB_RISING (0x1u << 18)
#define TC_CMR_LDRB_FALLING (0x2u << 18)
#define TC_CMR_LDRB_EDGE (0x3u << 18)
#define TC_CMR_CPCSTOP (0x1u << 6)
#define TC_CMR_CPCDIS (0x1u << 7)
#define TC_CMR_EEVTEDG_Pos 8
#define TC_CMR_EEVTEDG_Msk (0x3u << TC_CMR_EEVTEDG_Pos)
#define TC_CMR_EEVTEDG_NONE (0x0u << 8)
#define TC_CMR_EEVTEDG_RISING (0x1u << 8)
#define TC_CMR_EEVTEDG_FALLING (0x2u << 8)
#define TC_CMR_EEVTEDG_EDGE (0x3u << 8)
#define TC_CMR_EEVT_Pos 10
#define TC_CMR_EEVT_Msk (0x3u << TC_CMR_EEVT_Pos)
#define TC_CMR_EEVT_TIOB (0x0u << 10)
#define TC_CMR_EEVT_XC0 (0x1u << 10)
#define TC_CMR_EEVT_XC1 (0x2u << 10)
#define TC_CMR_EEVT_XC2 (0x3u << 10)
#define TC_CMR_ENETRG (0x1u << 12)
#define TC_CMR_WAVSEL_Pos 13
#define TC_CMR_WAVSEL_Msk (0x3u << TC_CMR_WAVSEL_Pos)
#define TC_CMR_WAVSEL_UP (0x0u << 13)
#define TC_CMR_WAVSEL_UPDOWN (0x1u << 13)
#define TC_CMR_WAVSEL_UP_RC (0x2u << 13)
#define TC_CMR_WAVSEL_UPDOWN_RC (0x3u << 13)
#define TC_CMR_ACPA_Pos 16
#define TC_CMR_ACPA_Msk (0x3u << TC_CMR_ACPA_Pos)
#define TC_CMR_ACPA_NONE (0x0u << 16)
#define TC_CMR_ACPA_SET (0x1u << 16)
#define TC_CMR_ACPA_CLEAR (0x2u << 16)
#define TC_CMR_ACPA_TOGGLE (0x3u << 16)
#define TC_CMR_ACPC_Pos 18
#define TC_CMR_ACPC_Msk (0x3u << TC_CMR_ACPC_Pos)
#define TC_CMR_ACPC_NONE (0x0u << 18)
#define TC_CMR_ACPC_SET (0x1u << 18)
#define TC_CMR_ACPC_CLEAR (0x2u << 18)
#define TC_CMR_ACPC_TOGGLE (0x3u << 18)
#define TC_CMR_AEEVT_Pos 20
#define TC_CMR_AEEVT_Msk (0x3u << TC_CMR_AEEVT_Pos)
#define TC_CMR_AEEVT_NONE (0x0u << 20)
#define TC_CMR_AEEVT_SET (0x1u << 20)
#define TC_CMR_AEEVT_CLEAR (0x2u << 20)
#define TC_CMR_AEEVT_TOGGLE (0x3u << 20)
#define TC_CMR_ASWTRG_Pos 22
#define TC_CMR_ASWTRG_Msk (0x3u << TC_CMR_ASWTRG_Pos)
#define TC_CMR_ASWTRG_NONE (0x0u << 22)
#define TC_CMR_ASWTRG_SET (0x1u << 22)
#define TC_CMR_ASWTRG_CLEAR (0x2u << 22)
#define TC_CMR_ASWTRG_TOGGLE (0x3u << 22)
#define TC_CMR_BCPB_Pos 24
#define TC_CMR_BCPB_Msk (0x3u << TC_CMR_BCPB_Pos)
#define TC_CMR_BCPB_NONE (0x0u << 24)
#define TC_CMR_BCPB_SET (0x1u << 24)
#define TC_CMR_BCPB_CLEAR (0x2u << 24)
#define TC_CMR_BCPB_TOGGLE (0x3u << 24)
#define TC_CMR_BCPC_Pos 26
#define TC_CMR_BCPC_Msk (0x3u << TC_CMR_BCPC_Pos)
#define TC_CMR_BCPC_NONE (0x0u << 26)
#define TC_CMR_BCPC_SET (0x1u << 26)
#define TC_CMR_BCPC_CLEAR (0x2u << 26)
#define TC_CMR_BCPC_TOGGLE (0x3u << 26)
#define TC_CMR_BEEVT_Pos 28
#define TC_CMR_BEEVT_Msk (0x3u << TC_CMR_BEEVT_Pos)
#define TC_CMR_BEEVT_NONE (0x0u << 28)
#define TC_CMR_BEEVT_SET (0x1u << 28)
#define TC_CMR_BEEVT_CLEAR (0x2u << 28)
#define TC_CMR_BEEVT_TOGGLE (0x3u << 28)
#define TC_CMR_BSWTRG_Pos 30
#define TC_CMR_BSWTRG_Msk (0x3u << TC_CMR_BSWTRG_Pos)
#define TC_CMR_BSWTRG_NONE (0x0u << 30)
#define TC_CMR_BSWTRG_SET (0x1u << 30)
#define TC_CMR_BSWTRG_CLEAR (0x2u << 30)
#define TC_CMR_BSWTRG_TOGGLE (0x3u << 30)

#define TC_SMMR_GCEN (0x1u << 0)
#define TC_SMMR_DOWN (0x1u << 1)

#define TC_CV_CV_Pos 0
#define TC_CV_CV_Msk (0xffffffffu << TC_CV_CV_Pos)

#define TC_RA_RA_Pos 0
#define TC_RA_RA_Msk (0xffffffffu << TC_RA_RA_Pos)
#define TC_RA_RA(value) ((TC_RA_RA_Msk & ((value) << TC_RA_RA_Pos)))

#define TC_RB_RB_Pos 0
#define TC_RB_RB_Msk (0xffffffffu << TC_RB_RB_Pos)
#define TC_RB_RB(value) ((TC_RB_RB_Msk & ((value) << TC_RB_RB_Pos)))

#define TC_RC_RC_Pos 0
#define TC_RC_RC_Msk (0xffffffffu << TC_RC_RC_Pos)
#define TC_RC_RC(value) ((TC_RC_RC_Msk & ((value) << TC_RC_RC_Pos)))

#define TC_SR_COVFS (0x1u << 0)
#define TC_SR_LOVRS (0x1u << 1)
#define TC_SR_CPAS (0x1u << 2)
#define TC_SR_CPBS (0x1u << 3)
#define TC_SR_CPCS (0x1u << 4)
#define TC_SR_LDRAS (0x1u << 5)
#define TC_SR_LDRBS (0x1u << 6)
#define TC_SR_ETRGS (0x1u << 7)
#define TC_SR_CLKSTA (0x1u << 16)
#define TC_SR_MTIOA (0x1u << 17)
#define TC_SR_MTIOB (0x1u << 18)

#define TC_IER_COVFS (0x1u << 0)
#define TC_IER_LOVRS (0x1u << 1)
#define TC_IER_CPAS (0x1u << 2)
#define TC_IER_CPBS (0x1u << 3)
#define TC_IER_CPCS (0x1u << 4)
#define TC_IER_LDRAS (0x1u << 5)
#define TC_IER_LDRBS (0x1u << 6)
#define TC_IER_ETRGS (0x1u << 7)

#define TC_IDR_COVFS (0x1u << 0)
#define TC_IDR_LOVRS (0x1u << 1)
#define TC_IDR_CPAS (0x1u << 2)
#define TC_IDR_CPBS (0x1u << 3)
#define TC_IDR_CPCS (0x1u << 4)
#define TC_IDR_LDRAS (0x1u << 5)
#define TC_IDR_LDRBS (0x1u << 6)
#define TC_IDR_ETRGS (0x1u << 7)

#define TC_IMR_COVFS (0x1u << 0)
#define TC_IMR_LOVRS (0x1u << 1)
#define TC_IMR_CPAS (0x1u << 2)
#define TC_IMR_CPBS (0x1u << 3)
#define TC_IMR_CPCS (0x1u << 4)
#define TC_IMR_LDRAS (0x1u << 5)
#define TC_IMR_LDRBS (0x1u << 6)
#define TC_IMR_ETRGS (0x1u << 7)

#define TC_BCR_SYNC (0x1u << 0)

#define TC_BMR_TC0XC0S_Pos 0
#define TC_BMR_TC0XC0S_Msk (0x3u << TC_BMR_TC0XC0S_Pos)
#define TC_BMR_TC0XC0S_TCLK0 (0x0u << 0)
#define TC_BMR_TC0XC0S_TIOA1 (0x2u << 0)
#define TC_BMR_TC0XC0S_TIOA2 (0x3u << 0)
#define TC_BMR_TC1XC1S_Pos 2
#define TC_BMR_TC1XC1S_Msk (0x3u << TC_BMR_TC1XC1S_Pos)
#define TC_BMR_TC1XC1S_TCLK1 (0x0u << 2)
#define TC_BMR_TC1XC1S_TIOA0 (0x2u << 2)
#define TC_BMR_TC1XC1S_TIOA2 (0x3u << 2)
#define TC_BMR_TC2XC2S_Pos 4
#define TC_BMR_TC2XC2S_Msk (0x3u << TC_BMR_TC2XC2S_Pos)
#define TC_BMR_TC2XC2S_TCLK2 (0x0u << 4)
#define TC_BMR_TC2XC2S_TIOA1 (0x2u << 4)
#define TC_BMR_TC2XC2S_TIOA2 (0x3u << 4)
#define TC_BMR_QDEN (0x1u << 8)
#define TC_BMR_POSEN (0x1u << 9)
#define TC_BMR_SPEEDEN (0x1u << 10)
#define TC_BMR_QDTRANS (0x1u << 11)
#define TC_BMR_EDGPHA (0x1u << 12)
#define TC_BMR_INVA (0x1u << 13)
#define TC_BMR_INVB (0x1u << 14)
#define TC_BMR_INVIDX (0x1u << 15)
#define TC_BMR_SWAP (0x1u << 16)
#define TC_BMR_IDXPHB (0x1u << 17)
#define TC_BMR_FILTER (0x1u << 19)
#define TC_BMR_MAXFILT_Pos 20
#define TC_BMR_MAXFILT_Msk (0x3fu << TC_BMR_MAXFILT_Pos)
#define TC_BMR_MAXFILT(value) ((TC_BMR_MAXFILT_Msk & ((value) << TC_BMR_MAXFILT_Pos)))

#define TC_QIER_IDX (0x1u << 0)
#define TC_QIER_DIRCHG (0x1u << 1)
#define TC_QIER_QERR (0x1u << 2)

#define TC_QIDR_IDX (0x1u << 0)
#define TC_QIDR_DIRCHG (0x1u << 1)
#define TC_QIDR_QERR (0x1u << 2)

#define TC_QIMR_IDX (0x1u << 0)
#define TC_QIMR_DIRCHG (0x1u << 1)
#define TC_QIMR_QERR (0x1u << 2)

#define TC_QISR_IDX (0x1u << 0)
#define TC_QISR_DIRCHG (0x1u << 1)
#define TC_QISR_QERR (0x1u << 2)
#define TC_QISR_DIR (0x1u << 8)

#define TC_FMR_ENCF0 (0x1u << 0)
#define TC_FMR_ENCF1 (0x1u << 1)

#define TC_WPMR_WPEN (0x1u << 0)
#define TC_WPMR_WPKEY_Pos 8
#define TC_WPMR_WPKEY_Msk (0xffffffu << TC_WPMR_WPKEY_Pos)
#define TC_WPMR_WPKEY_PASSWD (0x54494Du << 8)

#endif /* _SAM3XA_TC_COMPONENT_ */
