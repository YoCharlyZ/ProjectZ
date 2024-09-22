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
#include <Wire.h> // https://github.com/esp8266/Arduino/tree/master/libraries/Wire  
#include <SoftwareSerial.h> //https://github.com/plerup/espsoftwareserial/  
#include <SPI.h> // https://github.com/esp8266/Arduino/tree/master/libraries/SPI  
//#include <EEPROM.h> // https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM  
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////| 
unsigned long timeLine0 = 0;         //| Dedicado para Software Serial
unsigned long timeLine1 = 0;         //| 
unsigned long timeLine2 = 0;         //| 
unsigned long timeLine3 = 0;         //| 
unsigned long timeLine4 = 0;         //| 
unsigned long timeLine5 = 0;         //| 
//unsigned long timeLine64 = 590000; //| 
///////////////////////////////////////| 
const uint8_t pinSCL = 5;            //| 
const uint8_t pinSDA = 4;            //| 
///////////////////////////////////////| 
const uint8_t softRX = 2;            //| 
const uint8_t softTX = 0;            //| 
///////////////////////////////////////| 
const uint8_t CS_SD = 15;            //| 
///////////////////////////////////////| 
bool master_loadConfig = false;      //| 
bool slave_loadConfig = false;       //| 
bool flag_restart = true;            //| 
///////////////////////////////////////| 
//___________________________________________________________________________________
// Variables para almacenar los valores de los pines analógicos y digitales recibidos
float valPinA0 = 0.00, valPinA1 = 0.00, valPinA2 = 0.00, valPinA3 = 0.00, valPinA4 = 0.00, valPinA5 = 0.00;
uint8_t /*valPinD0 = 0, valPinD1 = 0, valPinD2 = 0,*/ valPinD3 = 0, /*valPinD4 = 0,*/ valPinD5 = 0;
uint8_t valPinD6 = 0, valPinD7 = 0, valPinD8 = 0, valPinD9 = 0, valPinD10 = 0, valPinD11 = 0, valPinD12 = 0, valPinD13 = 0;
//_________________________________________________________
// Configuracion dedicada a la comunicacion Software Serial  
SoftwareSerial softSerial(softRX, softTX); // Instanciamos SoftwareSerial con pines RX y TX definidos
struct controlDataPins {
  float val_pinA0, val_pinA1, val_pinA2, val_pinA3, val_pinA4, val_pinA5;
  uint8_t /*val_pinD0, val_pinD1, val_pinD2,*/ val_pinD3, /*val_pinD4,*/ val_pinD5;
  uint8_t val_pinD6, val_pinD7, val_pinD8, val_pinD9, val_pinD10, val_pinD11, val_pinD12, val_pinD13;
};
controlDataPins controlData;  // Instanciamos el struct usando asignación de memoria estatica
const char charInit = '<'; // esto se envia antes del struct y fuera de este
const char charEnd = '>'; // esto se envia despues del struct y fuera de este
const uint8_t maxSize = sizeof(controlDataPins)+2; // esto es el tamaño que ocupe el struct + los 2 caracteres de control
const uint8_t maxTimeWait = 450; // esto es el tiempo maximo que puede tomarse o descartara todo completamente
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setup() {  
  setupInit();
  setupSoftSerial();
  setupEnding();
}    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void loop() {  
  if (millis() >= timeLine0 + 500) {

    handleSoftSerial();
    
    timeLine0 = millis();
  }
  if (millis() >= timeLine1 + 1000) {
   // otras acciones menos eventuales 
   // otras acciones menos eventuales 
  }
  if (millis() >= timeLine2 + 2000) {
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    timeLine2 = millis();
  }
  if (millis() >= timeLine3 + 3000) {
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    timeLine3 = millis();
  }
  if (millis() >= timeLine4 + 4000) {
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    timeLine4 = millis();
  }
  if (millis() >= timeLine5 + 5000) {
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    // otras acciones menos eventuales 
    timeLine5 = millis();
  }
  /*if (millis) >= timeLine64 + 590000) {
   
    timeLine64 = millis();
  }*/
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setupInit(){ // Configuraciones iniciales
  Serial.begin(115200, SERIAL_8N1); // Inicializa puerto de comunicacion Hardware Serial
  Serial.println(F("Iniciando..."));
  Serial.println(F("Puerto Hardware Serial: Iniciado Correctamente."));
  Wire.begin(pinSDA, pinSCL); // Inicializa puerto de comunicacion I2C
  Serial.println("Puerto I2C: Iniciado Correctamente.");
  SPI.begin(); // Inicializa puerto de comunicacion SPI
  Serial.println("Puerto SPI: Iniciado Correctamente.");
  Serial.println();
  Serial.println();
  Serial.println(F("================================================================================"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("|                                 Bienvenido                                   |"));
  Serial.println(F("|                =============================================                 |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("|    Authur:     CharlyZ                                                       |"));
  Serial.println(F("|    Repository: https://github.com/YoCharlyZ/ProjectZ                         |"));
  Serial.println(F("|    Init Date Version: V. 0.0.1 - 23th March 2022                             |"));
  Serial.println(F("|    Count Versions Previous: 28                                               |"));
  Serial.println(F("|    Current Date Version: V. 0.2.9 - 10th September 2024                      |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("================================================================================"));
  Serial.println();
  Serial.println();  

  setupConfigPins();
}
void setupConfigPins(){ // Configura los pines como entrada o salida según corresponda

  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH);
  
}
void setupSoftSerial(){ // Configura el Software Serial y Prepara el Struct que utilizara

  softSerial.begin(9600); // Inicializa puerto de comunicacion Software Serial
  Serial.println(F("Puerto Software Serial: Iniciado Correctamente."));

  memset(&controlData, 0, sizeof(controlDataPins));  // Usamos la referencia al struct estático // Limpia la memoria del struct (opcional ya que ya se inicializó)
  
  // Inicializamos el Struc controlData con valores preestablecidos por defecto
  Serial.println(F("Inicializando valores predefinidos para el Struct controlData..."));
  controlData.val_pinA0 = valPinA0;
  controlData.val_pinA1 = valPinA1;
  controlData.val_pinA2 = valPinA2;
  controlData.val_pinA3 = valPinA3;
  controlData.val_pinA4 = valPinA4;
  controlData.val_pinA5 = valPinA5;
  
  //controlData.val_pinD0 = valPinD0;
  //controlData.val_pinD1 = valPinD1;
  //controlData.val_pinD2 = valPinD2;
  controlData.val_pinD3 = valPinD3;
  //controlData.val_pinD4 = valPinD4;
  controlData.val_pinD5 = valPinD5;
  controlData.val_pinD6 = valPinD6;
  controlData.val_pinD7 = valPinD7;
  controlData.val_pinD8 = valPinD8;
  controlData.val_pinD9 = valPinD9;
  controlData.val_pinD10 = valPinD10;
  controlData.val_pinD11 = valPinD11;
  controlData.val_pinD12 = valPinD12;
  controlData.val_pinD13 = valPinD13;

  Serial.println(F("Struct controlData inicializado correctamente."));
  
}
void setupEnding(){ // Configuraciones finales
  
  Serial.println();
  Serial.println();
  Serial.println(F("================================================================================"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("|                                 Bienvenido                                   |"));
  Serial.println(F("|                =============================================                 |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("|    Authur:     CharlyZ                                                       |"));
  Serial.println(F("|    Repository: https://github.com/YoCharlyZ/ProjectZ                         |"));
  Serial.println(F("|    Init Date Version: V. 0.0.1 - 23th March 2022                             |"));
  Serial.println(F("|    Count Versions Previous: 28                                               |"));
  Serial.println(F("|    Current Date Version: V. 0.2.9 - 10th September 2024                      |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("================================================================================"));
  Serial.println();
  Serial.println();  

  Serial.println(F("Inicializando Funciones de Algo++..."));
  
  updateDataPins();

  Serial.println(F("Gracias por esperar"));
  Serial.println(F("Inicializaciones Terminadas Correctamente"));
  Serial.println(F("usted es el jefe de los minisuper?"));
  Serial.println(F("enserio??"));
  Serial.println(F("usted???"));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rwDataPins(){ // Lee y escribe correspondientemente los pines segun las variables globales

}
void infoDataPins() { // Imprime los valores actuales de las variables globales

  Serial.println(F("Estados y Valores Actuales de Variables Compartidas: "));
  Serial.print("< ");
  Serial.print(F("Master: ")); Serial.print(master_loadConfig); Serial.print(", ");
  Serial.print(F("Slave: ")); Serial.print(slave_loadConfig);
  Serial.println(" >");

  Serial.println(F("Estados y Valores Actuales de Pines Analogicos: "));
  Serial.print("< ");
  Serial.print(F("A0: ")); Serial.print(valPinA0); Serial.print(F(", "));
  Serial.print(F("A1: ")); Serial.print(valPinA1); Serial.print(F(", "));
  Serial.print(F("A2: ")); Serial.print(valPinA2); Serial.print(F(", "));
  Serial.print(F("A3: ")); Serial.print(valPinA3); Serial.print(F(", "));
  Serial.print(F("A4: ")); Serial.print(valPinA4); Serial.print(F(", "));
  Serial.print(F("A5: ")); Serial.print(valPinA5);
  Serial.println(" >");

  Serial.println(F("Estados y Valores Actuales de Pines Digitales: "));
  Serial.print("< ");
  //Serial.print(F("D0: ")); Serial.print(valPinD0); Serial.print(F(", "));
  //Serial.print(F("D1: ")); Serial.print(valPinD1); Serial.print(F(", "));
  //Serial.print(F("D2: ")); Serial.print(valPinD2); Serial.print(F(", "));
  Serial.print(F("D3: ")); Serial.print(valPinD3); Serial.print(F(", "));
  //Serial.print(F("D4: ")); Serial.print(valPinD4); Serial.print(F(", "));
  Serial.print(F("D5: ")); Serial.print(valPinD5); Serial.print(F(", "));
  Serial.print(F("D6: ")); Serial.print(valPinD6); Serial.print(F(", "));
  Serial.print(F("D7: ")); Serial.print(valPinD7); Serial.print(F(", "));
  Serial.print(F("D8: ")); Serial.print(valPinD8); Serial.print(F(", "));
  Serial.print(F("D9: ")); Serial.print(valPinD9); Serial.print(F(", "));
  Serial.print(F("D10: ")); Serial.print(valPinD10); Serial.print(F(", "));
  Serial.print(F("D11: ")); Serial.print(valPinD11); Serial.print(F(", "));
  Serial.print(F("D12: ")); Serial.print(valPinD12); Serial.print(F(", "));
  Serial.print(F("D13: ")); Serial.print(valPinD13);
  Serial.println(" >");
}
void updateDataPins() { // Actualiza los valores de las variables globales segun los datos del Struct dataControl
    
  valPinA0 = (controlData.val_pinA0);
  valPinA1 = (controlData.val_pinA1);
  valPinA2 = (controlData.val_pinA2);
  valPinA3 = (controlData.val_pinA3);
  valPinA4 = (controlData.val_pinA4);
  valPinA5 = (controlData.val_pinA5);

  //valPinD0 = (controlData.val_pinD0);
  //valPinD1 = (controlData.val_pinD1);
  //valPinD2 = (controlData.val_pinD2);
  valPinD3 = (controlData.val_pinD3);
  //valPinD4 = (controlData.val_pinD4);
  valPinD5 = (controlData.val_pinD5);
  valPinD6 = (controlData.val_pinD6);
  valPinD7 = (controlData.val_pinD7);
  valPinD8 = (controlData.val_pinD8);
  valPinD9 = (controlData.val_pinD9);
  valPinD10 = (controlData.val_pinD10);
  valPinD11 = (controlData.val_pinD11);
  valPinD12 = (controlData.val_pinD12);
  valPinD13 = (controlData.val_pinD13);

}
void readSoftSerial() { // Recibe los datos por Software Serial
  Serial.println(F("Intentando recibir datos por Software Serial..."));

  if (softSerial.available() > 0) {  // Verificar si hay datos disponibles
    char dataChar = (char)softSerial.read();  // Leer el primer byte

    if (dataChar == charInit) { // Verificar si el carácter de inicio coincide
      Serial.println(F("Caracter de inicio reconocido, leyendo..."));
      
      timeLine0 = millis();  // Guardar el tiempo de inicio de recepción

      if (millis() >= timeLine0 + maxTimeWait) { // Esperar los datos dentro del tiempo máximo permitido
        if (softSerial.available() >= (int)sizeof(controlDataPins)) {  // Verificar si llegaron todos los datos
          
          // Leer los datos del struct controlDataPins
          softSerial.readBytes(reinterpret_cast<char*>(&controlData), sizeof(controlDataPins));
          Serial.println(F("Datos recibidos por Software Serial:"));

          for (size_t i = 0; i < sizeof(controlDataPins); i++) { // Imprimir los datos recibidos
            Serial.print(reinterpret_cast<char*>(&controlData)[i]); // Opción: imprimir como caracteres ASCII
            //Serial.print(reinterpret_cast<char*>(&controlData)[i], DEC); // Opción: imprimir en decimal
            //Serial.print(reinterpret_cast<char*>(&controlData)[i], BIN); // Opción: imprimir en binario
            //Serial.print(reinterpret_cast<char*>(&controlData)[i], OCT); // Opción: imprimir en octal
            Serial.print(" ");  // Espacio entre bytes
          }
          Serial.println();  // Salto de línea al final

          if (softSerial.read() == charEnd) { // Verificar si el carácter de fin coincide
            Serial.println(F("Carácter de fin reconocido"));
            return;  // Finalizar si todo está correcto
          } else {
            Serial.println(F("Carácter de fin no reconocido"));
          }
        }
      }

      Serial.println(F("Tiempo de espera agotado"));
      softSerial.flush();  // Limpiar el buffer si no se completó la recepción
    } else {
      Serial.println(F("Carácter de inicio no reconocido"));
    }
  } else {
    Serial.println(F("No hay datos disponibles en Software Serial"));
  }
}
void sendSoftSerial() { // Envia los datos por Software Serial
  Serial.println(F("Enviando datos por Software Serial..."));

  softSerial.write(charInit); // Enviar el carácter de inicio

  // Enviar los datos del struct controlDataPins byte por byte
  softSerial.write(reinterpret_cast<char*>(&controlData), sizeof(controlDataPins));
  softSerial.write(charEnd); // Enviar el carácter de fin

  Serial.println(F("Datos enviados por Software Serial:"));
  
  for (size_t i = 0; i < sizeof(controlDataPins); i++) { // Imprimir los datos enviados para verificación
    Serial.print(reinterpret_cast<char*>(&controlData)[i]); // Opción: imprimir como caracteres ASCII
    //Serial.print(reinterpret_cast<char*>(&controlData)[i], DEC); // Opción: imprimir en decimal
    //Serial.print(reinterpret_cast<char*>(&controlData)[i], BIN); // Opción: imprimir en binario
    //Serial.print(reinterpret_cast<char*>(&controlData)[i], OCT); // Opción: imprimir en octal
    Serial.print(" ");  // Espacio entre bytes
  }
  Serial.println();  // Salto de línea al final
}
void handleSoftSerial(){ // Gestion general del Software Serial
  readSoftSerial();
  updateDataPins();
  rwDataPins();
  sendSoftSerial();
  infoDataPins();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  