#ifndef HARDWARE_PROFILE_PIC18F4550_PIM_H
#define HARDWARE_PROFILE_PIC18F4550_PIM_H


    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #if defined(USE_SELF_POWER_SENSE_IO)
    #define self_power          PORTAbits.RA2
    #else
    #define self_power          1
    #endif

    //#define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISAbits.TRISA1    // Input
    #if defined(USE_USB_BUS_SENSE_IO)
    #define USB_BUS_SENSE       PORTAbits.RA1
    #else
    #define USB_BUS_SENSE       1
    #endif

    //Uncomment the following line to make the output HEX of this  
    //  project work with the MCHPUSB Bootloader    
    //#define PROGRAMMABLE_WITH_USB_MCHPUSB_BOOTLOADER
	
    //Uncomment the following line to make the output HEX of this 
    //  project work with the HID Bootloader
    // #define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER		

    /*******************************************************************/
    /******** MDD File System selection options ************************/
    /*******************************************************************/
    #define USE_PIC18
    #define USE_SD_INTERFACE_WITH_SPI

    #define INPUT_PIN           1
    #define OUTPUT_PIN          0

    // Chip Select Signal
    #define SD_CS               PORTBbits.RB3
    #define SD_CS_TRIS          TRISBbits.TRISB3
    
    // Card detect signal
    #define SD_CD               PORTBbits.RB4
    #define SD_CD_TRIS          TRISBbits.TRISB4
    
    // Write protect signal
    #define SD_WE               PORTAbits.RA4
    #define SD_WE_TRIS          TRISAbits.TRISA4
    
    // Registers for the SPI module you want to use
    #define SPICON1             SSPCON1
    #define SPISTAT             SSPSTAT
    #define SPIBUF              SSPBUF
    #define SPISTAT_RBF         SSPSTATbits.BF
    #define SPICON1bits         SSPCON1bits
    #define SPISTATbits         SSPSTATbits

    #define SPI_INTERRUPT_FLAG  PIR1bits.SSPIF   

    // Defines for the FSUSB board
    #define SPICLOCK            TRISBbits.TRISB1
    #define SPIIN               TRISBbits.TRISB0
    #define SPIOUT              TRISCbits.TRISC7

    // Latch pins for SCK/SDI/SDO lines
    #define SPICLOCKLAT         LATBbits.LATB1
    #define SPIINLAT            LATBbits.LATB0
    #define SPIOUTLAT           LATCbits.LATC7

    // Port pins for SCK/SDI/SDO lines
    #define SPICLOCKPORT        PORTBbits.RB1
    #define SPIINPORT           PORTBbits.RB0
    #define SPIOUTPORT          PORTCbits.RC7

    #define SPIENABLE           SSPCON1bits.SSPEN

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    //#define DEMO_BOARD PICDEM_FS_USB
    //#define PICDEM_FS_USB
    #define CLOCK_FREQ 48000000
    #define GetSystemClock()  CLOCK_FREQ   
    #define GetInstructionClock() CLOCK_FREQ   
    
    /** LED ************************************************************/
    #define mInitAllLEDs()      {LATD &= 0xF0; TRISD &= 0xF0;}
    
    #define mLED_1              LATDbits.LATD0
    #define mLED_2              LATDbits.LATD1
    #define mLED_3              LATDbits.LATD2
    #define mLED_4              LATDbits.LATD3
    
    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4

    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitAllSwitches()  TRISBbits.TRISB4=1;TRISBbits.TRISB5=1;
    #define mInitSwitch2()      TRISBbits.TRISB4=1;
    #define mInitSwitch3()      TRISBbits.TRISB5=1;
    #define sw2                 PORTBbits.RB4
    #define sw3                 PORTBbits.RB5

    /** POT ************************************************************/
    #define mInitPOT()          {TRISAbits.TRISA0=1;ADCON0=0x01;ADCON2=0x3C;ADCON2bits.ADFM = 1;}

    //#define mInitPOT()          ADCON0=0x01;ADCON1=0x06;WDTCONbits.ADSHR=1;ANCON0=0x9E;ANCON1=0xFE;WDTCONbits.ADSHR=0;
    
    /** I 2 C   T E M P   S E N S E *************************************/
    #define	mInitI2CPins()		TRISC |= 0x18;		// RC3 and RC4 are I2C

    
    
    /** SPI : Chip Select Lines ****************************************/
    #define tris_cs_temp_sensor TRISBbits.TRISB2    // Output
    #define cs_temp_sensor      LATBbits.LATB2
    
    #define tris_cs_sdmmc       TRISBbits.TRISB3    // Output
    #define cs_sdmmc            LATBbits.LATB3
    
    /** SD/MMC *********************************************************/
    #define TRIS_CARD_DETECT    TRISBbits.TRISB4    // Input
    #define CARD_DETECT         PORTBbits.RB4
    
    #define TRIS_WRITE_DETECT   TRISAbits.TRISA4    // Input
    #define WRITE_DETECT        PORTAbits.RA4

    /** USB external transceiver interface (optional) ******************/
    #define tris_usb_vpo        TRISBbits.TRISB3    // Output
    #define tris_usb_vmo        TRISBbits.TRISB2    // Output
    #define tris_usb_rcv        TRISAbits.TRISA4    // Input
    #define tris_usb_vp         TRISCbits.TRISC5    // Input
    #define tris_usb_vm         TRISCbits.TRISC4    // Input
    #define tris_usb_oe         TRISCbits.TRISC1    // Output
    
    #define tris_usb_suspnd     TRISAbits.TRISA3    // Output
    
    /** MDD File System error checking *********************************/
    // Will generate an error if the clock speed is too low to interface to the card
    #if (GetSystemClock() < 400000)
        #error System clock speed must exceed 400 kHz
    #endif   

#endif  //HARDWARE_PROFILE_PIC18F87J50_PIM_H
