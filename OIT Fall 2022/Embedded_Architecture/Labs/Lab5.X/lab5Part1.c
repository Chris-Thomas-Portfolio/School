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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Functions
int ReadStatus();
void Write(int address, int data);
int Read(int address);

int main()
{
    int stat;
    int read;
    SYSKEY = 0; // Ensure lock
    SYSKEY = 0xAA996655; // Write Key 1
    SYSKEY = 0x556699AA; // Write Key 2
    PB2DIV = _PB2DIV_ON_MASK | 0 & _PB2DIV_PBDIV_MASK; // 0 = div by 1, 1 = div by 2, 2 = div by 3 etc up to 128
    SYSKEY = 0; // Re lock
    PRECON = (1 & _PRECON_PFMWS_MASK) | ((2 << _PRECON_PREFEN_POSITION) & _PRECON_PREFEN_MASK);
    
    SPI4BRG = 8;                                            //set baud rate
    ANSELBCLR = _ANSELB_ANSB3_MASK;
    SDI4R = 0x8;
    RPF2R = 0x8;
    
    LATFSET = _LATF_LATF8_MASK;
    TRISFCLR = _TRISF_TRISF8_MASK;
    
    SPI4CON = (_SPI4CON_MSTEN_MASK | _SPI4CON_CKP_MASK);    //Turn on master and ckp
    
    SPI4CONSET = _SPI4CON_ON_MASK;                          //turn on SPI4CON
    
    ReadStatus();
    Read(0xF800);
    Write(0xF800, 0xAA);
    Read(0xF800);
    
    return 0;
}

int Read(int address)
{
    int readItem;
    while(ReadStatus() & 1);
    
    LATFCLR = _LATF_LATF8_MASK;             //assert the CS
    
    SPI4BUF = 0x3;                          //write a read 
    
    while(SPI4STATbits.SPITBE == 0);        //wait for Transmit buffer to empty
    
    SPI4BUF = (address >> 8);               //write MSA
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;                                //read SPI4BUF 
    
    SPI4BUF = address;                      //write LSA
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;                                //read SPI4BUF
    
    SPI4BUF = 'x';                          //write dummy
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;                                //read SPI4BUF
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    readItem = SPI4BUF;                     //read data
    
    LATFSET = _LATF_LATF8_MASK;             //negate the CS
    
    return readItem;
}

void Write(int address, int data)
{
    
    while(ReadStatus() & 1);
/********Write Enable*******************************************************/
    LATFCLR = _LATF_LATF8_MASK;             //assert the CS
    
    SPI4BUF = 0x6;                          //write a write enable
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;                                //read SPI4BUF                                
    
    LATFSET = _LATF_LATF8_MASK;             //negate the CS
/***************************************************************************/
    asm("NOP");                             //added NOP for hold time
    asm("NOP");                     
    
    LATFCLR = _LATF_LATF8_MASK;             //assert the CS
    
    SPI4BUF = 0x2;                          //write a write 
    
    while(SPI4STATbits.SPITBE == 0);        //wait for Transmit buffer to empty
    
    SPI4BUF = (address >> 8);               //write MSA
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;
    
    SPI4BUF = address;                         //write LSA
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;
    
    SPI4BUF = data;
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;
    
    while(SPI4STATbits.SPIRBF == 0);        //wait for receive buffer full
    
    SPI4BUF;
    
    LATFSET = _LATF_LATF8_MASK;             //negate the CS
}

int ReadStatus()
{
    int status;
    
    LATFCLR = _LATF_LATF8_MASK;         //assert the CS
    
    SPI4BUF = 0x5;                      //write a read status
    
    while(SPI4STATbits.SPITBE == 0);    //wait for Transmit buffer to empty
    
    SPI4BUF = 'X';                      //write dummy byte
    
    while(SPI4STATbits.SPIRBF == 0);    //wait for receive buffer full
    
    SPI4BUF;                            //read SPI4BUFF
    
    while(SPI4STATbits.SPIRBF == 0);    //wait for receive buffer full
    
    status = SPI4BUF;
    
    LATFSET = _LATF_LATF8_MASK;         //negate the CS
    
    return status;
}