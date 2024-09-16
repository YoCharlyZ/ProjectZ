////////////////////////////////////////////////////////////////////////////////////////////////////////////  
/*#include <"Arduino.h">  */  
/*#include <"ProjectZ.h"> */  
/*#include <"CharlyZ">    */  
/*#include <"A_Hombros_De_Gigantes"> */  
/*#La informacion que no es compartida en tiempo y forma, simplemente muere.*/  
/* Map Pins */  
/*  Arduino UNO {  // https://github.com/arduino  
  
      PD0   D0   RX0  ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      PD1   D1   TX0  ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      PD2   D2        --->  
      PD3   D3   pwm  --->  
      PD4   D4        --->  
      PD5   D5   pwm  --->  
      PD6   D6   pwm  --->  
      PD7   D7        --->  
  
      PB0   D8        --->  
      PB1   D9   pwm  --->  
      PB2   D10  pwm  --->  CC/SS  --->  
      PB3   D11  pwm  --->  MOSI   --->  
      PB4   D12       --->  MISO   --->  
      PB5   D13       --->  SCLK   --->  
            GND       --->   gnd   --->  
            AREF      --->  
      PC5   SCL   A5  --->  
      PC4   SDA   A4  --->  
  
            IOREF     --->  
      PC6   D14 RESET --->  <---|  
            VCC       --->  +3.3vcc --->!  
            VCC       --->  +5vcc   --->!  
            GND       --->   gnd    --->  
            GND       --->   gnd    --->  
            VIN       --->  +3.3 a +12vcc --->!  
      PC0   A0        --->  
      PC1   A1        --->  
      PC2   A2        --->  
      PC3   A3        --->  
      PC4   A4   SDA  --->  SDA  pullUp4.7k/+3.3vcc  --->  
      PC5   A5   SCL  --->  SCL  pullUp4.7k/+3.3vcc  --->  
  
    }  
  */  
/*  Arduino ESP8266-01s 2 & 4Mb {  // https://github.com/esp8266/Arduino/tree/master  
  
      gpio0         ---> para programar por TTL añadir pullDown10k a GND  
      gpio1    TX   ---> para programar por TTL a RX // para programar desde otro micro a TX  
      gpio2         --->  
      gpio3    RX   ---> para programar por TTL a TX // para programar desde otro micro a RX  
      EN chpd       ---> Enable  ---> Encendido pullUp4.7k/+3.3vcc  
      VCC           ---> +3.3vcc --->!  
      GND           ---> gnd     --->  
        ***************************************************  
        ademas sumar 330ohms++ en la linea seleccionada SDA  
        ademas sumar 330ohms++ en la linea seleccionada SCL  
        ***************************************************  
        (luego de programar solo son necesarios +vcc & gnd)  
        ***************************************************  
        ********* Habilita el Pin como GPIO Normal ********  
                      pinMode(1, FUNCTION_3);  
                      pinMode(3, FUNCTION_3);  
        ********** Habilita el Pin como TX/RX *************  
                      pinMode(1, FUNCTION_0);  
                      pinMode(3, FUNCTION_0);  
        ***************************************************  
    }  
 */  
/*  Arduino NodeMCU amica 1.0 v3 ESP8266  {  // https://github.com/esp8266/Arduino/tree/master  
  
      gpio17   A0    --->  
      gpio10   SDD3  --->  
      gpio9    SDD2  --->  
      gpio8    SD1   --->  mosi  ---> no usar <---|  
      gpio11   CMD   --->  cs/ss ---> no usar <---|  
      gpio7    SD0   --->  miso  ---> no usar <---|  
      gpio6    SCLK  --->  sclk  ---> no usar <---|    
      GND            --->  gnd     --->  
      VCC            --->  +3.3vcc --->!  
      EN             --->  Enable  ---> Encendido pullUp4.7k/+3.3vcc  
      RST            --->  <---|  
      VIN            --->  +3.3vcc --->!  
  
      gpio16   D0    ---> (el unico que sirve para despertar) --->  
      gpio5    D1    --->    SCL   pullUp4.7k/+3.3vcc   --->  
      gpio4    D2    --->    SDA   pullUp4.7k/+3.3vcc   --->  
      gpio0    D3    ---> pullUp4.7k/+3.3vcc (arranque normal) --->  
      gpio2    D4    ---> pullUp4.7k/+3.3vcc (arranque normal) --->  
      VCC            --->  +3.3vcc --->!  
      GND            --->   gnd    --->  
      gpio14   D5    --->   SCLK   --->  
      gpio12   D6    --->   MISO   --->  
      gpio13   D7    --->   MOSI   --->  
      gpio15   D8    --->   CC/SS  --->  
      gpio3    RX    ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      gpio1    TX    ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      GND            --->   gnd    --->  
      VCC            --->  +3.3vcc --->!  
  
    }  
  */  
/*  Arduino NodeMCU32s v1.1 101010 ESP-WROOM-32  {  //https://github.com/espressif/arduino-esp32  
  
      VCC                  --->  +3.3vcc   --->  
      RST       EN  
      gioP36    SVP        ---> solo input --->  
      gioP39    SVN        ---> solo input --->  
      gioP34               ---> solo input --->  
      gioP35               ---> solo input --->  
      gioP32               --->  
      gioP33               --->  
      gioP25               --->  
      gioP26               --->  
      gioP27               --->  
      gioP14    HSPI       ---> sclk --->  no usar  <---|  
      gioP12    HSPI       ---> miso --->  no usar  <---|  
      GND                  ---> gnd  --->  
      gioP13    HSPI       ---> mosi --->  no usar  <---|  
      gioP9     SD2   RX1  --->  no usar  <---|  
      gioP10    SD3   TX1  --->  no usar  <---|  
      gioP11    CMD        --->  no usar  <---|  
      VIN                  --->   +5vcc    --->!  
  
      gioP6     CLK        --->  cs/ss ---> no usar <---|  
      gioP7     SD0        --->  no usar  <---|  
      gioP8     SD1        --->  no usar  <---|  
      gioP15    HSPI       --->  
      gioP2                --->  
      gioP0                --->  
      gioP4                --->  
      gioP16          RX2  --->  
      gioP17          TX2  --->  
      gioP5     VSPI       --->  CS/SS --->  
      gioP18    VSPI       --->  SCLK  --->  
      gioP19    VSPI       --->  MISO  --->  
      GND                  --->  gnd   --->  
      gioP21               --->  SCL   ---> pullUp4.7k/+3.3vcc --->  
      gioP3           RX0  --->  
      gioP1           TX0  --->  
      gioP22               --->  SDA   ---> pullUp4.7k/+3.3vcc --->  
      gioP23    VSPI       --->  MOSI  --->  
      GND                  --->  gnd   --->  
  
    }  
  */  
/*  Arduino Mega {  // https://github.com/arduino  
  
      PD0       D21   SCL   --->  
      PD1       D20   SDA   --->  
                AREF        --->  
                GND         --->  gnd  --->  
      PB7  pwm  D13   SCK   --->  
      PB6  pwm  D12   MISO  --->  
      PB5  pwm  D11   MOSI  --->  
      PB4  pwm  D10   CS/SS --->  
      PH6  pwm  D9          --->    
      PH5  pwm  D8          --->    
  
      PH4  pwm  D7          --->  
      PH3  pwm  D6          --->  
      PE3  pwm  D5          --->  
      PG5  pwm  D4          --->  
      PE5  pwm  D3          --->  
      PE4  pwm  D2          --->  
      PE1  pwm  D1    TX0   --->  
      PE0  pwm  D0    RX0   --->  
  

  
      PJ1       D14   TX3   --->  
      PJ0       D15   RX3   --->  
      PH1       D16   TX2   --->  
      PD3       D17   RX2   --->  
      PD2       D18   TX1   --->  
      PD2       D19   RX1   --->  
      PD1       D20   SDA   --->  
      PD0       D21   SCL   --->  
  
      PK7       A15         --->  
      PK6       A14         --->  
      PK5       A13         --->  
      PK4       A12         --->  
      PK3       A11         --->  
      PK2       A10         --->  
      PK1       A9          --->  
      PK0       A8          --->  
  
      PF7       A7    TDI   --->  
      PF6       A6    TDO   --->  
      PF5       A5    TMS   --->  
      PF4       A4    TCK   --->  
      PF3       A3          --->  
      PF2       A2          --->  
      PF1       A1          --->  
      PF0       A0          --->  
  

  
                GND         --->  gnd  --->  
                GND         --->  gnd  --->  
      PB0       D53   CS/SS --->  
      PB1       D52   SCLK  --->  
      PB2       D51   MOSI  --->  
      PB3       D50   MISO  --->  
      PL0       D49         --->  
      PL1       D48         --->  
      PL2       D47         --->  
      PL3  pwm  D46         --->  
      PL4  pwm  D45         --->  
      PL5  pwm  D44         --->  
      PL6       D43         --->  
      PL7       D42         --->  
      PG0       D41         --->  
      PG1       D40         --->  
      PG2       D39         --->  
      PD7       D38         --->  
      PC0       D37         --->  
      PC1       D36         --->  
      PC2       D35         --->  
      PC3       D34         --->  
      PC4       D33         --->  
      PC5       D32         --->  
      PC6       D31         --->  
      PC7       D30         --->  
      PA7       D29         --->  
      PA6       D28         --->  
      PA5       D27         --->  
      PA4       D26         --->  
      PA3       D25         --->  
      PA2       D24         --->  
      PA1       D23         --->  
      PA0       D22         --->  
                VCC         --->  +5vcc  --->!  
                VCC         --->  +5vcc  --->!  
  
    }  
  */  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
/*  LittleFS {  
      Arduino IDE v1.x Esp8266 https://github.com/earlephilhower/arduino-esp8266littlefs-plugin  
      Arduino IDE v2.x Esp8266 https://github.com/earlephilhower/arduino-littlefs-upload  
      Arduino IDE V2.x Esp32   https://github.com/earlephilhower/arduino-littlefs-upload  
  }
*/
/*  SpifFS {  
      Arduino IDE v1.x Esp8266 https://github.com/esp8266/arduino-esp8266fs-plugin  
      ArduionoIDE V1.x Esp32 https://github.com/me-no-dev/arduino-esp32fs-plugin  
      Arduino IDE v2.x No Soportado.  
  }  
*/
/*  SpifFS, LittleFS, FatFS {  
      Arduino IDE V1.x Esp32 https://github.com/lorol/arduino-esp32fs-plugin
  }
*/ 
/*  Exeption Decoder {  
      Arduino IDE v1.x https://github.com/me-no-dev/EspExceptionDecoder  
  }
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
/*  Ante reinicios inesperados... 
  //La forma correcta:
  //Aliméntar al perro regularmente o insertando esto en lugares estratégicos:

  //ESP.wdtFeed(); // Esto restablecerá el temporizador WDT y mantendrá contento al perro.
  //ESP.wdtDisable(); // El 'si sabes lo que estás haciendo': enciérralo con
  //ESP.wdtEnable(0); // Tenga en cuenta que puede sacarlo de nuevo con
  //El '0' es un número arbitrario que se requiere pero no se usa). 
  //SIN EMBARGO, todavía está el perro de hardware y no puedes desactivarlo! ah menos que se desee probar esto...
  */
/*  void hw_wdt_disable(){
    *((volatile uint32_t*) 0x60000900) &= ~(1); // Hardware WDT OFF
    }
  */
/*  void hw_wdt_enable(){
    *((volatile uint32_t*) 0x60000900) |= 1; // Hardware WDT ON
    }
  */
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setup() {  
  
}    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void loop() {  
  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  