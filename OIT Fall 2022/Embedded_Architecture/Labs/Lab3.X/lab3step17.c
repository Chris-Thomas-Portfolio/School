/***************************************************************************
 * Author: Chris Thomas
 * Date: 10/18/2022
 * Project: Lab 3 - Interrupts in C
 * Updates: N/A
 ***************************************************************************/
// PIC32MZ2048ECG144, EFM144 or or EFG144 based HMZ144 board Configuration Bit Settings
// DEVCFG2
#if defined(__32MZ2048EFG144__) || defined(__32MZ2048EFM144__)
#pragma config FPLLIDIV = DIV_4         // System PLL Input Divider (4x Divider) for 24MHz clock (Rev C1 board w EFG) 24MHz/4 = 6MHz
                                        // also 24MHz clock rev C board w EFM (weird - went back to C. rev D also is EFM but with Osc)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)
#else
#pragma config FPLLIDIV = DIV_2         // System PLL Input Divider (2x Divider) for 12 MHz crystal (Rev B and C boards w ECG) 12MHz/2 = 6MHz
#pragma config UPLLEN = OFF             // USB PLL Enable (USB PLL is disabled)
#endif
#pragma config FPLLRNG = RANGE_5_10_MHZ // System PLL Input Range (5-10 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (POSC is input to the System PLL)
#pragma config FPLLMULT = MUL_112       // System PLL Multiplier (PLL Multiply by 112) 6MHz * 112 = 672MHz
#pragma config FPLLODIV = DIV_8         // System PLL Output Clock Divider (8x Divider) 672MHz / 2 = 84MHz

// DEVCFG1
#pragma config FNOSC = SPLL             // Oscillator Selection Bits (Primary Osc (HS,EC))
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disable SOSC)
#if defined(__32MZ2048EFG144__)
#pragma config POSCMOD = EC             // Primary Oscillator Configuration EC - External clock osc
                                        // Rev C1 board w EFG uses an Oscillator (Rev D boards too))
#else
#pragma config POSCMOD = HS             // Primary Oscillator Configuration HS - Crystal osc
                                        // Rev B and C (w ECG or EFM) use Crystals
#endif
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disabled, FSCM Disabled)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled)
#pragma config FDMTEN = OFF             // Deadman Timer Enable (Deadman Timer is disabled)
#pragma config DMTINTV = WIN_127_128    // Default DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config DMTCNT = DMT31           // Max Deadman Timer count = 2^31

// DEVCFG0
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx2        // ICD/ICE is on PGEC2/PGED2 pins (not default)

#include <xc.h>
#include <sys/attribs.h>
int tmr2var;
int tmr3var;

int main() 
{
    int i;
    T2CONSET = 0;
    INTCONSET = _INTCON_MVEC_MASK; // set MVEC bit
    IFS0CLR = _IFS0_T2IF_MASK; // Clear the timer interrupt status flag
    IEC0SET = _IEC0_T2IE_MASK;
    IPC2CLR = _IPC2_T2IP_MASK | _IPC2_T2IS_MASK;
    IPC2SET = (4 << _IPC2_T2IP_POSITION) & _IPC2_T2IP_MASK;
    IFS0CLR = _IFS0_T3IF_MASK; // Clear the timer interrupt status flag
    IEC0SET = _IEC0_T3IE_MASK;
    IPC3CLR = _IPC3_T3IP_MASK | _IPC3_T3IS_MASK;
    IPC3SET = (3 << _IPC3_T3IP_POSITION) & _IPC3_T3IP_MASK;
    SYSKEY = 0; // Ensure lock
    SYSKEY = 0xAA996655; // Write Key 1
    SYSKEY = 0x556699AA; // Write Key 2
    PB3DIV = _PB3DIV_ON_MASK | 0 & _PB3DIV_PBDIV_MASK; // 0 = div by 1, 1 = div by 2, 2 = div by 3 etc up to 128
    SYSKEY = 0; // Re lock
    T2CON = ((0 << _T2CON_TCKPS_POSITION) & _T2CON_TCKPS_MASK);
    PRECON = (1 & _PRECON_PFMWS_MASK) | ((2 << _PRECON_PREFEN_POSITION) & _PRECON_PREFEN_MASK);
    PR2 = 511;
    PR3 = 999;
    //PRISS = (7 << _PRISS_PRI7SS_POSITION) & _PRISS_PRI7SS_MASK;
    asm("ei");
    T2CONSET = _T2CON_ON_MASK; // Turn Timer 2 and Timer 3 on.
    T3CONSET = _T2CON_ON_MASK; // Do not rearrange these lines so timers will sync
    IFS0SET = _IFS0_T3IF_MASK; //artificially trigger a T3 int
    for(i = 0; i < 2; i++) // run the following twice so it runs from cache the second time
    { 
        TMR2 = 0;
        TMR3 = 5; // Needed to get TMR2 and 3 in sync
    }
    while(1);
}
void __ISR_AT_VECTOR(_TIMER_2_VECTOR, IPL4SOFT) MyTimer2Handler(void)
{
    tmr2var++;
    IFS0CLR = _IFS0_T2IF_MASK;  //clear flag
}
void __ISR_AT_VECTOR(_TIMER_3_VECTOR, IPL3SOFT) MyTimer3Handler(void)
{
    tmr3var++;
    while(TMR3 < 40);
    IFS0CLR = _IFS0_T3IF_MASK;  //clear flag
}