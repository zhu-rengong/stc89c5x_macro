

#ifndef __STC89C5X_SFR_H__
#define __STC89C5X_SFR_H__

sfr SFR_IRQ_ENABLE = 0xA8;
#define IRQ_EA_MASK                 0x80U
#define IRQ_ET2_MASK                0x20U
#define IRQ_ES_MASK                 0x10U
#define IRQ_ET1_MASK                0x08U
#define IRQ_EX1_MASK                0x04U
#define IRQ_ET0_MASK                0x02U
#define IRQ_EX0_MASK                0x01U

sfr SFR_IRQ_PRIO = 0xB8;
#define IRQ_PT2_MASK                0x20U
#define IRQ_PS_MASK                 0x10U
#define IRQ_PT1_MASK                0x08U
#define IRQ_PX1_MASK                0x04U
#define IRQ_PT0_MASK                0x02U
#define IRQ_PX0_MASK                0x01U

sfr SFR_TMR_CTRL = 0x88;
#define TCON_TF1_MASK               0x80U
#define TCON_TR1_MASK               0x40U
#define TCON_TF0_MASK               0x20U
#define TCON_TR0_MASK               0x10U
#define TCON_IE1_MASK               0x08U
#define TCON_IT1_MASK               0x04U
#define TCON_IE0_MASK               0x02U
#define TCON_IT0_MASK               0x01U

sfr SFR_TMR_MODE = 0x89;
#define TMOD_1_GATE_MASK            0x80U
#define TMOD_1_CT_MASK              0x40U
#define TMOD_1_M1_MASK              0x20U
#define TMOD_1_M0_MASK              0x10U
#define TMOD_0_GATE_MASK            0x08U
#define TMOD_0_CT_MASK              0x04U
#define TMOD_0_M1_MASK              0x02U
#define TMOD_0_M0_MASK              0x01U

sfr SFR_SERIAL_CTRL = 0x98;
#define SCON_SM0_MASK               0x80U
#define SCON_FE_MASK                0x80U
#define SCON_SM1_MASK               0x40U
#define SCON_SM2_MASK               0x20U
#define SCON_REN_MASK               0x10U
#define SCON_TB8_MASK               0x08U
#define SCON_RB8_MASK               0x04U
#define SCON_TI_MASK                0x02U
#define SCON_RI_MASK                0x01U

sfr SFR_POWER_CTRL = 0x87;
#define PCON_SMOD_MASK              0x80U
#define PCON_SMOD0_MASK             0x40U
#define PCON_POF_MASK               0x10U
#define PCON_GF1_MASK               0x08U
#define PCON_GF0_MASK               0x04U
#define PCON_PD_MASK                0x02U
#define PCON_IDL_MASK               0x01U

sfr SFR_AUXILIARY = 0x8E;
#define AUXR_EXTRAM_MASK            0x02U
#define AUXR_ALEOFF_MASK            0x01U

#endif // __STC89C5X_SFR_H__