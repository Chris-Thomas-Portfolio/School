/***************************************************************************
 * Author: Chris Thomas
 * Date: 10/11/2022
 * Project: Lab 2 - Performance Issues
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
#include <math.h>
#include "FOURIER.h"
#define NSAMP 256
#define TPIN (2 * M_PI/NSAMP)
float in[256];
float real[256];
float imag[256];
float mag[256];

int main()
{
    int n;
    int i;
    int j;
    SYSKEY = 0; // Ensure lock
    SYSKEY = 0xAA996655; // Write Key 1
    SYSKEY = 0x556699AA; // Write Key 2
    PB3DIV = _PB3DIV_ON_MASK | 0 & _PB3DIV_PBDIV_MASK; // 0 = div by 1, 1 = div by 2, 2 = div by 3 etc up to 128
    T2CON = ((0 << _T2CON_TCKPS_POSITION) & _T2CON_TCKPS_MASK);
    T2CON = ((1 << _T2CON_T32_POSITION) & _T2CON_T32_MASK);
    PRECON = (1 & _PRECON_PFMWS_MASK) | ((2 << _PRECON_PREFEN_POSITION) & _PRECON_PREFEN_MASK);
    
    for(n = 0; n < 256; n++)
    {
        in[n] = 256 * sin(8 * 2 * M_PI / NSAMP * n);
    }
    
    for(j = 0; j < 3; j++)
    {
        T2CONSET = 0x8000; // Start the timer
        fft_float(NSAMP, 0, in, NULL, real, imag);
        T2CONSET = 0x7000; // Stop the timer
        TMR2 = 0;
    }
    
    for(i = 0; i < 256; i++)
    {
        mag[i] = sqrt((real[i]*real[i]) + (imag[i]*imag[i]));
    }
}