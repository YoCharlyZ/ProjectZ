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
      PD2   D2        ---> softTX <--- softRX D3gpio0 NodeMcu <--|
      PD3   D3   pwm  ---> 
      PD4   D4        ---> softRX <--- softRX D4gpio2 NodeMcu <--|
      PD5   D5   pwm  --->  
      PD6   D6   pwm  --->  
      PD7   D7        --->  
  
      PB0   D8        --->  
      PB1   D9   pwm  --->  
      PB2   D10  pwm  --->  CC/SS  --->  
      PB3   D11  pwm  --->  MOSI   --->  
      PB4   D12       --->  MISO   --->  
      PB5   D13       --->  SCLK   --->  
            GND       --->  GND   <--- GND NodeMcu <--|  
            AREF      --->  
      PC5   SCL   A5  --->  
      PC4   SDA   A4  --->  
  
            IOREF     --->  
      PC6   D14 RESET --->  <---|  
            VCC       --->  +3.3vcc --->!  
            VCC       --->  +5vcc   --->!  
            GND       --->   GND   <--- GND NodeMcu <--|  
            GND       --->   GND   <--- GND NodeMcu <--|  
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
      GND            --->   GND  <---  GND Uno <--|   
      VCC            --->  +3.3vcc --->!  
      EN             --->  Enable  ---> Encendido pullUp4.7k/+3.3vcc  
      RST            --->  <---|  
      VIN            --->  +3.3vcc --->!  
  
      gpio16   D0    ---> (el unico que sirve para despertar) --->  
      gpio5    D1    --->    SCL   pullUp4.7k/+3.3vcc   --->  
      gpio4    D2    --->    SDA   pullUp4.7k/+3.3vcc   --->  
      gpio0    D3    ---> pullUp4.7k/+3.3vcc (arranque normal) ---> softRX <--- softTX pinD2 Uno <--|
      gpio2    D4    ---> pullUp4.7k/+3.3vcc (arranque normal) ---> softTX <--- softRX pinD4 Uno <--|
      VCC            --->  +3.3vcc --->!  
      GND            --->   GND   <--- GND Uno <--|  
      gpio14   D5    --->   SCLK   --->  SD card  <---|  
      gpio12   D6    --->   MISO   --->  SD card  <---|  
      gpio13   D7    --->   MOSI   --->  SD card  <---|  
      gpio15   D8    --->   CC/SS  --->  SD card  <---|  
      gpio3    RX    ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      gpio1    TX    ---> mientras se usen impedira la reprogramacion (no usar) <---|  
      GND            --->   GND   <--- GND Uno <--|   
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
#include <SoftwareSerial.h> // https://github.com/plerup/espsoftwareserial/  
#include <SPI.h> // https://github.com/esp8266/Arduino/tree/master/libraries/SPI  
//#include <EEPROM.h> // https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM  
#include <FS.h>            // https://github.com/esp8266/Arduino/tree/master/libraries/FSTools
#include <LittleFS.h>      // https://github.com/esp8266/Arduino/tree/master/libraries/LittleFS
#include <SD.h>            // https://github.com/esp8266/Arduino/tree/master/libraries/SD
#include <ArduinoJson.h>  // https://github.com/bblanchon/ArduinoJson
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
const uint8_t softRX = 0;            //| Pin RX del SoftwareSerial (ajusta según placa) Uno PinD4(softRX)   NodeMcu Gpio0 = pinD3(softRX)
const uint8_t softTX = 2;            //| Pin TX del SoftwareSerial (ajusta según placa) Uno PinD2(softTX)   NodeMcu Gpio2 = pinD4(softTX)
///////////////////////////////////////| 
const uint8_t pinSDA = 4;            //|  
const uint8_t pinSCL = 5;            //|  
///////////////////////////////////////| 
const uint8_t CS_SD = 15;            //| 
///////////////////////////////////////|
bool master_loadConfig = false;      //| 
bool slave_loadConfig = false;       //| 
bool flag_restart = true;            //| 
///////////////////////////////////////| 
const uint8_t targetID = 0;          //| Un adressID especial reservado para algun fin especifico.
const uint8_t mySlaveID = 10;        //| Mi adressID de Esclavo (ajusta según placa)
const uint8_t toMasterID = 8;        //| El adressID de al menos un Maestro Uno (ajusta según placa)
const uint8_t broadcastID = 255;     //| Un ID para MultiDifusion
///////////////////////////////////////| 
const unsigned long interval = 500;  //| Intervalo de envío en ms
///////////////////////////////////////| 
//////////////////////////////////////////////| 
const uint16_t softSerialBautRate = 9600;   //| Velocidad Baudrate para SoftwareSerial
const uint32_t hardSerialBautRate = 115200; //| Velocidad Baudrate para HardwareSerial
//////////////////////////////////////////////| 
//____________________________
// Configuracion de FileSystem
const char* fsName = "LittleFS";
FS* fileSystem = &LittleFS;
LittleFSConfig fileSystemConfig = LittleFSConfig();
static bool fsOK;
String unsupportedFiles = String();
File uploadFile;
bool flag_readConfig = false;
bool flag_loadConfig = false;
bool flag_writeConfig = false;
bool flag_saveConfig = false;
String receivedString1 = "Valor por defecto 1";
String receivedString2 = "Valor por defecto 2";
String receivedString3 = "Valor por defecto 3";
//________________________________________________________________________________________
// Variables Independientes para almacenar los valores de los pines analógicos y digitales
char valCharInit = '<';
uint16_t valPinA0 = 0, valPinA1 = 0, valPinA2 = 0, valPinA3 = 0, valPinA4 = 0, valPinA5 = 0;
uint8_t /*valPinD0 = 0, valPinD1 = 0, valPinD2 = 0,*/ valPinD3 = 0, /*valPinD4 = 0,*/ valPinD5 = 0;
uint8_t valPinD6 = 0, valPinD7 = 0, valPinD8 = 0, valPinD9 = 0, valPinD10 = 0, valPinD11 = 0, valPinD12 = 0, valPinD13 = 0;
char valCharEnd = '>';
//_________________________________________________________
// Configuracion dedicada a la comunicacion Software Serial  
SoftwareSerial softSerial(softRX, softTX);     // Instancia de SoftwareSerial con RX, TX
//#pragma pack(1) // Definición del struct para manejar datos con directivas globales de empaquetamiento alineado a 1 byte sin relleno.
// Definición del struct para manejar datos con atributo especifico de empaquetamiento alineado a 1 byte sin relleno.
struct __attribute__((packed, aligned(1))) DataPacket {
  char charInit;            // Carácter de inicio '<' (1 byte)
  uint8_t sourceID;         // ID de dispositivo remitente de origen
  uint8_t destinationID;    // ID de dispositivo destinatario

  bool varMasterLoadConfig; // Estado lógico = 8 bits = 1 Byte
  bool varSlaveLoadConfig;  // Estado lógico = 8 bits = 1 Byte
  bool varFlagRestart;      // Estado lógico = 8 bits = 1 Byte
  
  uint8_t varPinA0, varPinA1, varPinA2, varPinA3, varPinA4, varPinA5; // [(8 bits = 1 Byte) x6] = 6 Bytes Compactados
  uint8_t /*varPinD0, varPinD1, varPinD2,*/ varPinD3, /*varPinD4,*/ varPinD5; // [(8 bits = 1 Byte) x2] = 2 Bytes
  uint8_t varPinD6, varPinD7, varPinD8, varPinD9, varPinD10, varPinD11, varPinD12, varPinD13; // [(8 bits = 1 Byte) x8] = 8 Bytes

  uint8_t structSize;       // Tamaño del struct en bytes (1 byte)
  char charEnd;             // Carácter de fin '>' (1 byte)
}; // #pragma pack() // Restaura las directivas globales del empaquetamiento a su propio predeterminado.
// Variables globales para el struct de Inicialización explícita con caracteres de control
DataPacket dataPacketIN  = {'<', 0, 0, false, false, true, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, sizeof(DataPacket), '>'};  // Estructura para datos entrantes
DataPacket dataPacketOUT = {'<', 0, 0, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, sizeof(DataPacket), '>'};   // Estructura para datos salientes
//_________________________________________________________
// Configuracion dedicada al FiFo para la comunicacion del SoftwareSerial
#define FIFO_SIZE 64                               // Tamaño fijo del FIFO (ajustable)
uint8_t fifoRX[FIFO_SIZE];                         // Buffer RX
uint8_t fifoTX[FIFO_SIZE];                         // Buffer TX
uint8_t fifoIndexReadRX = 0;                       // Índice de lectura RX
uint8_t fifoIndexWriteRX = 0;                      // Índice de escritura RX
uint8_t fifoCountRX = 0;                           // Cantidad de bytes en RX
uint8_t fifoIndexReadTX = 0;                       // Índice de lectura TX
uint8_t fifoIndexWriteTX = 0;                      // Índice de escritura TX
uint8_t fifoCountTX = 0;                           // Cantidad de bytes en TX
unsigned long overflowCountRX = 0;                 // Veces que RX intentó escribir con buffer lleno
unsigned long overflowCountTX = 0;                 // Veces que TX intentó escribir con buffer lleno
bool paqueteCompleto = false;                      // Indica que hay un paquete listo para procesar
//_________________________________________________________
// Máquina de estados para la gestión del SoftwareSerial
enum EstadoSoftSerial {                            // Estados posibles para la máquina
  ESTADO_IDLE,                                      // Esperando envío o llegada de datos
  ESTADO_RECEIVING,                                 // Estado de recepción (llenar FIFO RX)
  ESTADO_PROCESSING,                                // Procesar paquete recibido
  ESTADO_SENDING                                    // Enviar paquete desde FIFO TX
};
EstadoSoftSerial estadoActual = ESTADO_IDLE;       // Estado inicial
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
// Prototipos de funciones                   //
void setupInit();                            // Configuraciónes iniciales del hardwardware
void setupHardSerial();                      // Configura el Hardware Serial 
void setupSoftSerial();                      // Configura el Software Serial
void setupI2C();                             // Inicializa puerto de comunicacion I2C
void setupSPI();                             // Inicializa puerto de comunicacion SPI
void setupFileSystem();                      // Configurar Sistema de Archivos Interno ./LittleFS
void setupFileSystemExt();                   // Configurar Sistema de Archivos Externo ./SD 
void setupConfigPins();                      // Configura los pines como entrada o salida según corresponda
void setupPrintInfoVersion();                // Imprime Informacion y Detalles del Proyecto
void setupEnd();                             // Configuraciones finales y Mensaje de finalización del setup
///////////////////////////////////////////////
void printSending();                         // Imprime paquete enviado (por Serial)
void printReceived();                        // Imprime paquete recibido (por Serial)
void printVarsInternal();                    // Imprime variables internas (por Serial)
void printFileConfig();                      // Imprime el contenido del archivo de configuración
void saveConfigCallBack();                   // La Llamada forzara bajar todas las banderas y escribir un archivo
void readSaveConfig();                       // Lee el Archivo de Configuraciones
void writeSaveConfig();                      // Escribe el Archivo de Configuraciones
void deleteSaveConfig();                     // Elimina el Archivo de Configuraciones
void updateStruct();                         // Actualiza campos del struct de salida
void updateVars();                           // Copia valores recibidos a variables internas
void rwDataPins();                           // Lógica de lectura/escritura de pines
void sendSoftSerial();                       // Prepara y envía bytes desde FIFO TX
void readSoftSerial();                       // Lee desde SoftSerial y almacena en FIFO RX sin bloquear
void fifoWriteRX(uint8_t dato);              // Inserta byte en FIFO RX (si hay espacio)
int  fifoReadRX();                           // Extrae byte de FIFO RX o devuelve -1
int  fifoPeekRX(uint8_t offset);             // Observa byte en RX sin remover (-1 si fuera índice)
void fifoClearRX();                          // Limpia FIFO RX (resetea índices y count)
void fifoWriteTX(uint8_t dato);              // Inserta byte en FIFO TX (si hay espacio)
int  fifoReadTX();                           // Extrae byte de FIFO TX o devuelve -1
int  fifoPeekTX(uint8_t offset);             // Observa byte en TX sin remover (-1 si fuera índice)
void fifoClearTX();                          // Limpia FIFO TX (resetea índices y count)
void processDataPacket();                    // Procesa dataPacketIN cuando paqueteCompleto == true
void handleSoftSerial();                     // Manejador principal llamado en loop()
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setup() {
  setupInit(); // Configuraciónes iniciales del hardwardware
  setupEnd();  // Configuraciones finales y Mensaje de finalización del setup
}
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void loop() {
  handleSoftSerial();

  if (millis() >= timeLine0 + 500) {

    // otras acciones menos eventuales 
    
    timeLine0 = millis();
  }
  if (millis() >= timeLine1 + 1000) {
   // otras acciones menos eventuales 
   // otras acciones menos eventuales 
   timeLine1 = millis();
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
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setupInit(){                            // Configuraciónes iniciales del hardwardware
  setupHardSerial(); // Configura el Hardware Serial 
  setupSoftSerial(); // Configura el Software Serial 
  setupI2C(); // Inicializa puerto de comunicacion I2C
  setupSPI(); // Inicializa puerto de comunicacion SPI
  setupFileSystem(); // Configurar Sistema de Archivos Interno ./LittleFS
  setupFileSystemExt(); // Configurar Sistema de Archivos Externo ./SD 
  setupConfigPins(); // Configura los pines como entrada o salida según corresponda
  setupPrintInfoVersion(); // Imprime Informacion y Detalles del Proyecto
  setupEnd(); // Configuraciones finales y Mensaje de finalización del setup
}
void setupHardSerial(){                      // Configura el Hardware Serial
  Serial.begin(hardSerialBautRate, SERIAL_8N1); // Inicializa puerto de comunicacion Hardware Serial
  Serial.println(F("Iniciando..."));
  Serial.println(F("Puerto Hardware Serial: Iniciado Correctamente."));
}
void setupSoftSerial(){                      // Configura el Software Serial
  pinMode(softRX, INPUT);    // Configura el pin RX como entrada
  pinMode(softTX, OUTPUT);   // Configura el pin TX como salida
  softSerial.begin(softSerialBautRate); // Inicializa puerto de comunicacion Software Serial
  Serial.println(F("Puerto Software Serial: Iniciado Correctamente."));
}
void setupI2C() {                            // Inicializa puerto de comunicacion I2C
  Wire.begin(pinSDA, pinSCL);
  Serial.println("Puerto I2C: Iniciado Correctamente.");
}
void setupSPI(){                             // Inicializa puerto de comunicacion SPI
  SPI.begin();
  Serial.println("Puerto SPI: Iniciado Correctamente.");
}
void setupFileSystem(){                      // Configurar Sistema de Archivos Interno ./LittleFS
  if (!LittleFS.begin()) {
    Serial.println("Fallo el Punto de Montaje ./LittleFS");
    return;
  }
  fileSystemConfig.setAutoFormat(false);
  fileSystem->setConfig(fileSystemConfig);
  fsOK = fileSystem->begin();
  Serial.println(fsOK ? F("Filesystem inicializado.") : F("Filesystem Fallo!"));
}
void setupFileSystemExt(){                   // Configurar Sistema de Archivos Externo ./SD
  if (!SD.begin(CS_SD)) {  // Asegúrate de usar el pin correcto para tu módulo SD
    Serial.println("Error al inicializar SD");
    return;
  }
}
void setupConfigPins(){                      // Configura los pines como entrada o salida según corresponda
  pinMode(LED_BUILTIN, OUTPUT); //Esto esta ligado al pin GPIO2, lo utilizaremos como testigoLed momentaneamente.
  digitalWrite(LED_BUILTIN, HIGH); 
  //gpio0  - D3  Este lo usamos como softRX para conectarlo al softTX de la otra placa. Mientras lo utilizemos, no podremos reprogramar, deberemos levantar.
  //gpio2  - D4  Este lo usamos como softTX para conectarlo al softRX de la otra placa. Mientras lo utilizemos, no podremos reprogramar, deberemos levantar.
  //gpio16 - D0  Dejemoslo reservado (el unico que sirve para despertar) *esp.ecial;
  //gpio17 - A0  Dejemoslo reservado, no lo utilizaremos por ahora. *esp.ecial;
  Serial.println(F("Inicialización y configuración de pines completada."));  
  digitalWrite(LED_BUILTIN, LOW);
}
void setupPrintInfoVersion(){                // Imprime Informacion y Detalles del Proyecto
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
  Serial.println(F("|    Count Versions Previous: 31                                               |"));
  Serial.println(F("|    Current Date Version: V. 0.3.2 - 07 December 2025                         |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("================================================================================"));
  Serial.println();
  Serial.println();  
}
void setupEnd(){                             // Configuraciones finales y Mensaje de finalización del setup

  // Cargar configuración después de inicializar los sistemas de archivos y configuracion de los pines
  Serial.println("Buscando archivo de configuraciones..");
  readSaveConfig(); // Lee el Archivo de Configuraciones
  printFileConfig(); // Imprime el contenido del archivo de configuración
  
  Serial.println(F("Inicializando Funciones de Algo++..."));
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(F("Gracias por esperar"));
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(F("Inicializaciones Terminadas Correctamente"));
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(F("usted es el jefe de los minisuper?"));
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(F("enserio??"));
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(F("usted???"));
  digitalWrite(LED_BUILTIN, LOW);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printSending() {                        // Imprime en Serial los datos que se enviaron
  Serial.println(F("Paquete Enviado:"));               // Cabecera
  Serial.print(F("Inicio: ")); Serial.println(dataPacketOUT.charInit);   // Muestra '<'
  Serial.print(F("Origen: ")); Serial.println(dataPacketOUT.sourceID);       // Muestra sourceID
  Serial.print(F("Destino: ")); Serial.println(dataPacketOUT.destinationID); // Muestra destinationID
  Serial.print(F("Estado del Maestro: ")); Serial.print(dataPacketOUT.varMasterLoadConfig ? "true" : "false");
  Serial.print(F(", Estado del Esclavo: ")); Serial.print(dataPacketOUT.varSlaveLoadConfig ? "true" : "false");
  Serial.print(F(", Estado de Reinicio: ")); Serial.print(dataPacketOUT.varFlagRestart ? "true" : "false");
  Serial.println(F(". ")); 

  Serial.println(F("Valores Pines Analogicos: "));
  Serial.print(F("A0 ")); Serial.print(dataPacketOUT.varPinA0); 
  Serial.print(F(", A1 ")); Serial.print(dataPacketOUT.varPinA1); 
  Serial.print(F(", A2 ")); Serial.print(dataPacketOUT.varPinA2); 
  Serial.print(F(", A3 ")); Serial.print(dataPacketOUT.varPinA3);
  Serial.print(F(", A4 ")); Serial.print(dataPacketOUT.varPinA4); 
  Serial.print(F(", A5 ")); Serial.print(dataPacketOUT.varPinA5); 
  Serial.println(F(". ")); 
  
  Serial.println(F("Valores Pines Digitales: "));
  //Serial.print(F("D0 ")); Serial.print(dataPacketOUT.varPinD0); 
  //Serial.print(F(", D1 ")); Serial.print(dataPacketOUT.varPinD1); 
  //Serial.print(F(", D2 ")); Serial.print(dataPacketOUT.varPinD2); 
  Serial.print(F("D3 ")); Serial.print(dataPacketOUT.varPinD3); 
  //Serial.print(F(", D4 ")); Serial.print(dataPacketOUT.varPinD4);
  Serial.print(F(", D5 ")); Serial.print(dataPacketOUT.varPinD5); 
  Serial.print(F(", D6 ")); Serial.print(dataPacketOUT.varPinD6);
  Serial.print(F(", D7 ")); Serial.print(dataPacketOUT.varPinD7); 
  Serial.print(F(", D8 ")); Serial.print(dataPacketOUT.varPinD8);
  Serial.print(F(", D9 ")); Serial.print(dataPacketOUT.varPinD9);
  Serial.print(F(", D10 ")); Serial.print(dataPacketOUT.varPinD10);
  Serial.print(F(", D11 ")); Serial.print(dataPacketOUT.varPinD11); 
  Serial.print(F(", D12 ")); Serial.print(dataPacketOUT.varPinD12); 
  Serial.print(F(", D13 ")); Serial.print(dataPacketOUT.varPinD13); 
  Serial.println(F(". "));

  Serial.println(F("Informacion del Paquete: "));
  Serial.print(F("Tamaño: ")); Serial.print(dataPacketOUT.structSize, DEC); // Muestra tamaño
  Serial.print(F(" Fin: ")); Serial.println(dataPacketOUT.charEnd);     // Muestra '>'
  Serial.println(F(" "));                               // Línea en blanco
}
void printReceived() {                       // Imprime en Serial los datos recibidos en dataPacketIN
  Serial.println(F("Paquete Recibido:"));              // Cabecera
  Serial.print(F(" Inicio: ")); Serial.println(dataPacketIN.charInit);     // Muestra '<'
  Serial.print(F("Origen: ")); Serial.println(dataPacketIN.sourceID);       // Muestra sourceID
  Serial.print(F("Destino: ")); Serial.println(dataPacketIN.destinationID); // Muestra destinationID
  Serial.print(F("Estado del Maestro: ")); Serial.print(dataPacketIN.varMasterLoadConfig ? "true" : "false");
  Serial.print(F(", Estado del Esclavo: ")); Serial.print(dataPacketIN.varSlaveLoadConfig ? "true" : "false");
  Serial.print(F(", Estado de Reinicio: ")); Serial.print(dataPacketIN.varFlagRestart ? "true" : "false");
  Serial.println(F(". ")); 

  Serial.println(F("Valores Pines Analogicos: "));
  Serial.print(F("A0 ")); Serial.print(dataPacketIN.varPinA0); 
  Serial.print(F(", A1 ")); Serial.print(dataPacketIN.varPinA1); 
  Serial.print(F(", A2 ")); Serial.print(dataPacketIN.varPinA2); 
  Serial.print(F(", A3 ")); Serial.print(dataPacketIN.varPinA3);
  Serial.print(F(", A4 ")); Serial.print(dataPacketIN.varPinA4); 
  Serial.print(F(", A5 ")); Serial.print(dataPacketIN.varPinA5); 
  Serial.println(F(". ")); 
  
  Serial.println(F("Valores Pines Digitales: "));
  //Serial.print(F("D0 ")); Serial.print(dataPacketIN.varPinD0); 
  //Serial.print(F(", D1 ")); Serial.print(dataPacketIN.varPinD1); 
  //Serial.print(F(", D2 ")); Serial.print(dataPacketIN.varPinD2); 
  Serial.print(F("D3 ")); Serial.print(dataPacketIN.varPinD3); 
  //Serial.print(F(", D4 ")); Serial.print(dataPacketIN.varPinD4);
  Serial.print(F(", D5 ")); Serial.print(dataPacketIN.varPinD5); 
  Serial.print(F(", D6 ")); Serial.print(dataPacketIN.varPinD6);
  Serial.print(F(", D7 ")); Serial.print(dataPacketIN.varPinD7); 
  Serial.print(F(", D8 ")); Serial.print(dataPacketIN.varPinD8);
  Serial.print(F(", D9 ")); Serial.print(dataPacketIN.varPinD9);
  Serial.print(F(", D10 ")); Serial.print(dataPacketIN.varPinD10);
  Serial.print(F(", D11 ")); Serial.print(dataPacketIN.varPinD11); 
  Serial.print(F(", D12 ")); Serial.print(dataPacketIN.varPinD12); 
  Serial.print(F(", D13 ")); Serial.print(dataPacketIN.varPinD13); 
  Serial.println(F(". ")); 

  Serial.println(F("Informacion del Paquete: "));
  Serial.print(F("Tamaño: ")); Serial.print(dataPacketIN.structSize, DEC); // Muestra tamaño recibido
  Serial.print(F(" Fin: ")); Serial.println(dataPacketIN.charEnd);       // Muestra '>'
  Serial.println(F(" "));                               // Línea en blanco
}
void printVarsInternal() {                   // Imprime variables internas de ejemplo
  Serial.println(F("Paquete Interno:"));               // Cabecera
  Serial.print(F("Inicio: ")); Serial.println(valCharInit);
  Serial.print(F("Estado del Maestro: ")); Serial.print(master_loadConfig ? "true" : "false");
  Serial.print(F(", Estado del Esclavo: ")); Serial.print(slave_loadConfig ? "true" : "false");
  Serial.print(F(", Estado de Reinicio: ")); Serial.print(flag_restart ? "true" : "false");
  Serial.println(F(". ")); 

  Serial.println(F("Valores Pines Analogicos: "));
  Serial.print(F("A0 ")); Serial.print(valPinA0); 
  Serial.print(F(", A1 ")); Serial.print(valPinA1); 
  Serial.print(F(", A2 ")); Serial.print(valPinA2); 
  Serial.print(F(", A3 ")); Serial.print(valPinA3);
  Serial.print(F(", A4 ")); Serial.print(valPinA4); 
  Serial.print(F(", A5 ")); Serial.print(valPinA5); 
  Serial.println(F(". ")); 
  
  Serial.println(F("Valores Pines Digitales: "));
  //Serial.print(F("D0 ")); Serial.print(valPinD0); 
  //Serial.print(F(", D1 ")); Serial.print(valPinD1); 
  //Serial.print(F(", D2 ")); Serial.print(valPinD2); 
  Serial.print(F("D3 ")); Serial.print(valPinD3); 
  //Serial.print(F(", D4 ")); Serial.print(valPinD4);
  Serial.print(F(", D5 ")); Serial.print(valPinD5); 
  Serial.print(F(", D6 ")); Serial.print(valPinD6);
  Serial.print(F(", D7 ")); Serial.print(valPinD7); 
  Serial.print(F(", D8 ")); Serial.print(valPinD8);
  Serial.print(F(", D9 ")); Serial.print(valPinD9);
  Serial.print(F(", D10 ")); Serial.print(valPinD10);
  Serial.print(F(", D11 ")); Serial.print(valPinD11); 
  Serial.print(F(", D12 ")); Serial.print(valPinD12); 
  Serial.print(F(", D13 ")); Serial.print(valPinD13); 
  Serial.println(F(". ")); 
  Serial.print(F("Fin: ")); Serial.println(valCharEnd);
  Serial.println(F(" "));                               // Línea en blanco
}
void printFileConfig() {                     // Imprime el contenido del archivo de configuración
  StaticJsonDocument<512> doc;

  // Intentar abrir el archivo en LittleFS
  File file = LittleFS.open("/config.txt", "r");
  if (!file) {
    Serial.println(F("Archivo no encontrado en LittleFS. Intentando en SD..."));
    file = SD.open("/config.txt", FILE_READ);
    if (!file) {
      Serial.println(F("Archivo de configuración no encontrado ni en LittleFS ni en SD."));
      return;
    }
  }

  // Deserializar el archivo JSON
  DeserializationError error = deserializeJson(doc, file);
  if (error) {
    Serial.println(F("Error al deserializar el archivo de configuración."));
    file.close();
    return;
  }

  Serial.println(F("Contenido del archivo de configuración:"));
  serializeJsonPretty(doc, Serial); // Imprimir JSON con formato legible
  Serial.println();
  file.close();
}
void readSaveConfig() {                      // Lee el Archivo de Configuraciones
  StaticJsonDocument<512> doc;

  // Intentar abrir el archivo en LittleFS
  File file = LittleFS.open("/config.txt", "r");
  if (!file) {
    Serial.println(F("Archivo no encontrado en LittleFS. Intentando en SD..."));
    file = SD.open("/config.txt", FILE_READ);
    if (file) {
      Serial.println(F("Archivo encontrado en SD. Copiando a LittleFS..."));

      // Copiar a LittleFS
      File newFile = LittleFS.open("/config.txt", "w");
      if (newFile) {
        while (file.available()) {
          newFile.write(file.read());
        }
        newFile.close();
        Serial.println(F("Archivo copiado desde SD a LittleFS."));
      } else {
        Serial.println(F("Error al crear archivo en LittleFS."));
      }
    } else {
      Serial.println(F("Archivo no encontrado ni en SD ni en LittleFS."));
      // Forzamos la creacion de un archivo de configuraciones con valores predeterminados.
      Serial.println(F("Generando archivo de configuración predeterminado..."));
      writeSaveConfig(); // Guardar configuración predeterminada en LittleFS
      return;
    }
  }

  // Leer configuración desde el archivo
  DeserializationError error = deserializeJson(doc, file);
  if (error) {
    Serial.println(F("Error al deserializar el archivo de configuración."));
    file.close();
    return;
  }

      // Cargar valores del archivo o usar valores predeterminados
      receivedString1 = doc["setString1"].isNull() ? "Valor por defecto 1" : doc["setString1"].as<String>();
      receivedString2 = doc["setString2"].isNull() ? "Valor por defecto 2" : doc["setString2"].as<String>();
      receivedString3 = doc["setString3"].isNull() ? "Valor por defecto 3" : doc["setString3"].as<String>();
  
      // Leer los valores de los pines analógicos
      valPinA0 = doc["valPinA0"] | 0;
      valPinA1 = doc["valPinA1"] | 0;
      valPinA2 = doc["valPinA2"] | 0;
      valPinA3 = doc["valPinA3"] | 0;
      valPinA4 = doc["valPinA4"] | 0;
      valPinA5 = doc["valPinA5"] | 0;

      // Leer los valores de los pines digitales
      valPinD3 = doc["valPinD3"] | 0;
      valPinD5 = doc["valPinD5"] | 0;
      valPinD6 = doc["valPinD6"] | 0;
      valPinD7 = doc["valPinD7"] | 0;
      valPinD8 = doc["valPinD8"] | 0;
      valPinD9 = doc["valPinD9"] | 0;
      valPinD10 = doc["valPinD10"] | 0;
      valPinD11 = doc["valPinD11"] | 0;
      valPinD12 = doc["valPinD12"] | 0;
      valPinD13 = doc["valPinD13"] | 0;

  file.close();
  Serial.println(F("Archivo de configuración cargado correctamente."));
  printFileConfig(); // Imprime el contenido del archivo de configuración
}
void saveConfigCallBack() {                  // La Llamada forzara bajar todas las banderas y escribir un archivo
  flag_saveConfig = false;
  flag_readConfig = false;
  master_loadConfig = false;
  slave_loadConfig = false;
  Serial.println(F("Guardando configuracion..."));
  writeSaveConfig();
}
void writeSaveConfig() {                     // Escribe el Archivo de Configuraciones
  StaticJsonDocument<512> doc;

    // Establecer valores actuales en el JSON
    doc[String("setString1")] = receivedString1;
    doc[String("setString2")] = receivedString2;
    doc[String("setString3")] = receivedString3;
    
    // Pines analógicos
    doc["valPinA0"] = valPinA0;
    doc["valPinA1"] = valPinA1;
    doc["valPinA2"] = valPinA2;
    doc["valPinA3"] = valPinA3;
    doc["valPinA4"] = valPinA4;
    doc["valPinA5"] = valPinA5;

    // Pines digitales
    doc["valPinD3"] = valPinD3;
    doc["valPinD5"] = valPinD5;
    doc["valPinD6"] = valPinD6;
    doc["valPinD7"] = valPinD7;
    doc["valPinD8"] = valPinD8;
    doc["valPinD9"] = valPinD9;
    doc["valPinD10"] = valPinD10;
    doc["valPinD11"] = valPinD11;
    doc["valPinD12"] = valPinD12;
    doc["valPinD13"] = valPinD13;

  // Guardar en LittleFS
  File file = LittleFS.open("/config.txt", "w");
  if (!file) {
    Serial.println(F("Error al abrir el archivo para escritura en LittleFS."));
    return;
  }

  // Serializar y escribir
  if (serializeJson(doc, file) == 0) {
    Serial.println(F("Error al escribir el archivo de configuración."));
  } else {
    Serial.println(F("Archivo de configuración guardado correctamente."));
  }

  file.close();
  printFileConfig(); // Imprime el contenido del archivo de configuración
}
void deleteSaveConfig() {                    // Elimina el Archivo de Configuraciones
  if (LittleFS.remove("/config.txt")) {
    Serial.println(F("Archivo de configuración eliminado."));
  } else {
    Serial.println(F("No se pudo eliminar el archivo de configuración."));
  }
}
void updateStruct() {                        // Actualiza campo structSize y calcula integridad antes de enviar
  
  dataPacketOUT.sourceID = mySlaveID;               // Actualiza sourceID
  dataPacketOUT.destinationID = toMasterID;     // Actualiza destinationID

  dataPacketOUT.varMasterLoadConfig = master_loadConfig;
  dataPacketOUT.varSlaveLoadConfig = slave_loadConfig;
  dataPacketOUT.varFlagRestart = flag_restart;

  dataPacketOUT.varPinA0 = map(valPinA0, 0, 1023, 0, 255); // Comprime A0 a un rango menor (0-255 desde 0-1023)
  dataPacketOUT.varPinA1 = map(valPinA1, 0, 1023, 0, 255); // Comprime A1 a un rango menor (0-255 desde 0-1023)
  dataPacketOUT.varPinA2 = map(valPinA2, 0, 1023, 0, 255); // Comprime A2 a un rango menor (0-255 desde 0-1023)
  dataPacketOUT.varPinA3 = map(valPinA3, 0, 1023, 0, 255); // Comprime A3 a un rango menor (0-255 desde 0-1023)
  dataPacketOUT.varPinA4 = map(valPinA4, 0, 1023, 0, 255); // Comprime A4 a un rango menor (0-255 desde 0-1023)
  dataPacketOUT.varPinA5 = map(valPinA5, 0, 1023, 0, 255); // Comprime A5 a un rango menor (0-255 desde 0-1023)

  //dataPacketOUT.varPinD0 = valPinD0;
  //dataPacketOUT.varPinD1 = valPinD1;
  //dataPacketOUT.varPinD2 = valPinD2;
  dataPacketOUT.varPinD3 = valPinD3;
  //dataPacketOUT.varPinD4 = valPinD4;
  dataPacketOUT.varPinD5 = valPinD5;
  dataPacketOUT.varPinD6 = valPinD6;
  dataPacketOUT.varPinD7 = valPinD7;
  dataPacketOUT.varPinD8 = valPinD8;
  dataPacketOUT.varPinD9 = valPinD9;
  dataPacketOUT.varPinD10 = valPinD10;
  dataPacketOUT.varPinD11 = valPinD11;
  dataPacketOUT.varPinD12 = valPinD12;
  dataPacketOUT.varPinD13 = valPinD13;
  dataPacketOUT.structSize = sizeof(dataPacketOUT);   // Tamaño actual del struct en bytes
}
void updateVars() {                          // Copia valores recibidos a variables internas
  master_loadConfig = dataPacketIN.varMasterLoadConfig;// Actualiza variables internas desde struct IN
  slave_loadConfig = dataPacketIN.varSlaveLoadConfig;  
  flag_restart = dataPacketIN.varFlagRestart;  

  valPinA0 = map(dataPacketIN.varPinA0, 0, 255, 0, 1023);   // Descomprime A0 a su rango original (0-1023 desde 0-255)
  valPinA1 = map(dataPacketIN.varPinA1, 0, 255, 0, 1023);   // Descomprime A1 a su rango original (0-1023 desde 0-255)
  valPinA2 = map(dataPacketIN.varPinA2, 0, 255, 0, 1023);   // Descomprime A2 a su rango original (0-1023 desde 0-255)
  valPinA3 = map(dataPacketIN.varPinA3, 0, 255, 0, 1023);   // Descomprime A3 a su rango original (0-1023 desde 0-255)
  valPinA4 = map(dataPacketIN.varPinA4, 0, 255, 0, 1023);   // Descomprime A4 a su rango original (0-1023 desde 0-255)
  valPinA5 = map(dataPacketIN.varPinA5, 0, 255, 0, 1023);   // Descomprime A5 a su rango original (0-1023 desde 0-255)

  //valPinD0 = dataPacketIN.varPinD0;
  //valPinD1 = dataPacketIN.varPinD1;
  //valPinD2 = dataPacketIN.varPinD2;
  valPinD3 = dataPacketIN.varPinD3; 
  //valPinD4 = dataPacketIN.varPinD4;
  valPinD5 = dataPacketIN.varPinD5;
  valPinD6 = dataPacketIN.varPinD6;
  valPinD7 = dataPacketIN.varPinD7;
  valPinD8 = dataPacketIN.varPinD8;
  valPinD9 = dataPacketIN.varPinD9;
  valPinD10 = dataPacketIN.varPinD10;
  valPinD11 = dataPacketIN.varPinD11;
  valPinD12 = dataPacketIN.varPinD12;
  valPinD13 = dataPacketIN.varPinD13;

}
void rwDataPins() {                          // Lógica para actualizar pines o variables periódicas
/*//gpio0  - D3  Este lo usamos como softRX para conectarlo al softTX de la otra placa. Mientras lo utilizemos, no podremos reprogramar, deberemos levantar.
  //gpio2  - D4  Este lo usamos como softTX para conectarlo al softRX de la otra placa. Mientras lo utilizemos, no podremos reprogramar, deberemos levantar.
  //gpio16 - D0  Dejemoslo reservado (el unico que sirve para despertar) *esp.ecial;
  //gpio17 - A0  Dejemoslo reservado, no lo utilizaremos por ahora. *esp.ecial;*/
  saveConfigCallBack();                      // Forzamos guardar configuraciones
}
void readSoftSerial() {                      // Lee desde SoftSerial y almacena en FIFO RX sin bloquear
  int availableBytes = softSerial.available();         // Lee cantidad de bytes disponibles en puerto (no bloqueante)
  if (availableBytes <= 0) return;                     // Si no hay bytes, salir inmediatamente

  // Determina cuantos bytes podemos leer sin provocar overflow en FIFO RX
  int freeSpace = FIFO_SIZE - fifoCountRX;             // Espacio libre en FIFO RX
  int toRead = availableBytes;                         // Inicializa toRead con disponibles
  if (toRead > freeSpace) toRead = freeSpace;          // Limita lectura al espacio libre para evitar overflow

  // Lee hasta 'toRead' bytes (sin usar while, usamos for)
  for (int i = 0; i < toRead; i++) {                   // Recorre la cantidad de bytes a leer
    int b = softSerial.read();                         // Lee un byte del puerto (puede devolver -1)
    if (b == -1) break;                                // Si falla la lectura, salimos del loop (seguro)
    fifoWriteRX((uint8_t)b);                           // Inserta el byte leído en FIFO RX (controla overflow internamente)
  }

  // Intentamos detectar si hay un paquete completo dentro del FIFO RX usando fifoPeekRX
  uint8_t structLen = sizeof(DataPacket);              // Longitud esperada del paquete
  if (fifoCountRX < structLen) return;                 // No hay suficientes bytes para formar un paquete

  // Buscamos el offset del caracter '<' que además tenga suficiente espacio para el paquete completo
  int startOffset = -1;                                // Offset donde estaría el '<' válido
  uint8_t maxSearch = fifoCountRX - (structLen - 1);   // Máximo offset posible para iniciar un paquete completo
  for (uint8_t off = 0; off < maxSearch; off++) {      // Recorremos offsets posibles (sin while)
    int c = fifoPeekRX(off);                           // Observa byte en offset sin removerlo
    if (c == -1) break;                                // Si peek falló, salir
    if ((char)c == valCharInit) {                      // Si encontramos '<'
      int endByte = fifoPeekRX(off + (structLen - 1));// Observa byte que debería ser '>' al final del paquete
      if (endByte != -1 && (char)endByte == valCharEnd) { // Si existe y es '>'
        startOffset = off;                             // Guardamos offset de inicio válido
        break;                                         // Salimos del for (encontrado)
      }
    }
  }

  // Si encontramos un paquete completo en algún offset, extraemos y verificamos integridad
  if (startOffset >= 0) {                              // Si se detectó offset válido
    // Descartamos bytes anteriores al inicio real para resinarizar (sin while)
    for (int d = 0; d < startOffset; d++) {            // Recorre cada byte previo
      int discarded = fifoReadRX();                    // Lee y descarta un byte
      (void)discarded;                                 // Evita warning por variable sin usar
    }
    // Ahora extraemos exactamente structLen bytes al struct de entrada
    uint8_t* ptrIn = (uint8_t*)&dataPacketIN;          // Puntero al struct de entrada
    for (uint8_t k = 0; k < structLen; k++) {          // Extrae exactamente structLen bytes al struct
      int dato = fifoReadRX();                         // Lee siguiente byte del FIFO RX
      if (dato == -1) return;                          // Si falla por underflow, aborta (seguro)
      *(ptrIn + k) = (uint8_t)dato;                    // Copia byte al struct
    }
    // Verificamos delimitador final por seguridad
    if (dataPacketIN.charEnd != valCharEnd) {          // Si no coincide el fin
      int dummy = fifoReadRX();                        // Lee y descarta 1 byte para re-sincronizar
      (void)dummy;                                     // Evita warning
      return;                                          // Salimos sin marcar paquete completo
    }

    // Si llegamos aquí, paquete íntegro: marcamos listo para procesamiento
    paqueteCompleto = true;                            // Indica que paquete listo para ser procesado
  }
}
void sendSoftSerial() {                      // Prepara y envía bytes desde FIFO TX
  updateStruct();                                     // Asegura que structSize y checks estén calculados
  uint8_t* ptrOut = (uint8_t*)&dataPacketOUT;         // Puntero a bytes del struct OUT
  uint8_t structLen = sizeof(DataPacket);             // Longitud del struct a enviar

  // Inserta cada byte del struct al FIFO TX (sin while)
  for (uint8_t i = 0; i < structLen; i++) {           // Recorre cada byte del struct
    fifoWriteTX(*(ptrOut + i));                       // Inserta byte en FIFO TX (control de overflow interno)
  }

  // Envía hasta structLen bytes por iteración (evita bloqueos prolongados), usando fifoReadTX
  for (uint8_t s = 0; s < structLen; s++) {           // Limita envíos a la longitud del struct por llamada
    int datoTX = fifoReadTX();                        // Extrae byte del FIFO TX (o -1 si vacío)
    if (datoTX == -1) break;                          // Si no hay datos, salimos del for
    softSerial.write((uint8_t)datoTX);                // Envía byte por SoftwareSerial
  }

  printSending();                                     // Muestra en Serial lo enviado
  rwDataPins();                                       // Actualiza contador interno para próximo envío
}
void fifoWriteRX(uint8_t dato) {             // Inserta un byte en FIFO RX si hay espacio
  if (fifoCountRX >= FIFO_SIZE) {                     // Si el buffer está lleno
    overflowCountRX++;                                 // Incrementa contador de overflow RX
    return;                                            // Ignora el byte nuevo (protege datos existentes)
  }
  fifoRX[fifoIndexWriteRX] = dato;                     // Escribe dato en la posición de escritura
  fifoIndexWriteRX++;                                  // Incrementa índice de escritura
  if (fifoIndexWriteRX >= FIFO_SIZE) fifoIndexWriteRX = 0; // Rebote circular del índice
  fifoCountRX++;                                       // Incrementa contador de bytes presentes
}
int fifoReadRX() {                           // Lee y elimina un byte del FIFO RX o devuelve -1 si vacío
  if (fifoCountRX == 0) return -1;                     // Nada por leer: underflow -> -1
  uint8_t dato = fifoRX[fifoIndexReadRX];              // Lee el byte en la posición de lectura
  fifoIndexReadRX++;                                   // Avanza índice de lectura
  if (fifoIndexReadRX >= FIFO_SIZE) fifoIndexReadRX = 0; // Rebote circular
  fifoCountRX--;                                       // Decrementa contador de bytes presentes
  return dato;                                         // Retorna el byte leído
}
int fifoPeekRX(uint8_t offset) {             // Observa un byte en RX sin removerlo; offset relativo a read index
  if (offset >= fifoCountRX) return -1;                // Offset fuera de rango -> -1
  uint8_t idx = fifoIndexReadRX + offset;              // Calcula índice lógico
  if (idx >= FIFO_SIZE) idx -= FIFO_SIZE;              // Ajusta por rebote circular si es necesario
  return fifoRX[idx];                                  // Retorna el byte observado
}
void fifoClearRX() {                         // Resetea completamente el FIFO RX
  fifoIndexReadRX = 0;                                 // Reinicia índice de lectura
  fifoIndexWriteRX = 0;                                // Reinicia índice de escritura
  fifoCountRX = 0;                                     // Pone contador a 0 (vacía buffer lógico)
}
void fifoWriteTX(uint8_t dato) {             // Inserta un byte en FIFO TX si hay espacio
  if (fifoCountTX >= FIFO_SIZE) {                      // Si el buffer TX está lleno
    overflowCountTX++;                                  // Cuenta evento de overflow TX
    return;                                             // Descarta el byte para no corromper buffer
  }
  fifoTX[fifoIndexWriteTX] = dato;                      // Escribe dato en posición de escritura TX
  fifoIndexWriteTX++;                                   // Avanza índice de escritura TX
  if (fifoIndexWriteTX >= FIFO_SIZE) fifoIndexWriteTX = 0; // Rebote circular
  fifoCountTX++;                                        // Incrementa el contador de bytes en TX
}
int fifoReadTX() {                           // Extrae y elimina un byte del FIFO TX o devuelve -1
  if (fifoCountTX == 0) return -1;                      // No hay datos -> -1
  uint8_t dato = fifoTX[fifoIndexReadTX];               // Lee byte en índice de lectura TX
  fifoIndexReadTX++;                                    // Avanza índice lectura TX
  if (fifoIndexReadTX >= FIFO_SIZE) fifoIndexReadTX = 0; // Rebote circular
  fifoCountTX--;                                        // Decrementa contador de bytes en TX
  return dato;                                          // Retorna byte extraído
}
int fifoPeekTX(uint8_t offset) {             // Observa un byte en TX sin removerlo; offset relativo a read index
  if (offset >= fifoCountTX) return -1;                 // Offset fuera de rango -> -1
  uint8_t idx = fifoIndexReadTX + offset;               // Calcula índice lógico
  if (idx >= FIFO_SIZE) idx -= FIFO_SIZE;               // Ajusta por rebote circular
  return fifoTX[idx];                                   // Retorna byte observado
}
void fifoClearTX() {                         // Resetea completamente el FIFO TX
  fifoIndexReadTX = 0;                                  // Reinicia índice lectura TX
  fifoIndexWriteTX = 0;                                 // Reinicia índice escritura TX
  fifoCountTX = 0;                                      // Reinicia contador TX
}
void processDataPacket() {                   // Procesa dataPacketIN cuando paqueteCompleto == true
  // Verifica si el mensaje NO está dirigido a mí, y NO es broadcast, y NO viene del master permitido
  if ( dataPacketIN.destinationID != mySlaveID      // Si el destinatario NO soy yo
       && dataPacketIN.destinationID != targetID      // Y TAMPOCO es target específico
       && dataPacketIN.destinationID != broadcastID // Y TAMPOCO es broadcast general
       && dataPacketIN.sourceID != toMasterID ) {   // Y NO viene del maestro autorizado
    
    return;                                         // Entonces ignoramos el paquete completamente
  }
  printReceived();                                    // Imprime los contenidos del paquete recibido
  updateVars();                                       // Actualiza variables internas desde el paquete
  printVarsInternal();                                // Muestra estado interno (contador)
  rwDataPins();                                       // Ejecuta acciones relacionadas a los datos/pines
  paqueteCompleto = false;                            // Resetea bandera de paquete completo
}
void handleSoftSerial() {                    // Manejador principal del Software Serial (envío y recepción)
  switch (estadoActual) {                             // Evalúa estado actual
    case ESTADO_IDLE:                                 // Si está idle
      if (softSerial.available() > 0) {               // Si hay bytes en el puerto
        estadoActual = ESTADO_RECEIVING;              // Pasa a recibir
      } else if (millis() - timeLine0 >= interval) {  // Si pasó el intervalo de envío
        estadoActual = ESTADO_SENDING;                // Pasa a enviar
      }
      break;

    case ESTADO_RECEIVING:                            // Si está recibiendo
      readSoftSerial();                               // Llama a la función que llena FIFO RX y detecta paquetes
      if (paqueteCompleto) {                          // Si se detectó paquete
        estadoActual = ESTADO_PROCESSING;             // Pasa a procesarlo
      } else {                                        // Si no, vuelve a IDLE para no saturar el loop
        estadoActual = ESTADO_IDLE;
      }
      break;

    case ESTADO_PROCESSING:                           // Si debe procesar paquete
      processDataPacket();                            // Procesa el paquete ya extraído a dataPacketIN
      estadoActual = ESTADO_IDLE;                     // Luego vuelve a IDLE
      break;

    case ESTADO_SENDING:                              // Si está en envío
      sendSoftSerial();                               // Prepara y envía bytes (no bloqueante por diseño)
      timeLine0 = millis();                           // Reinicia temporizador de envío
      estadoActual = ESTADO_IDLE;                     // Vuelve a IDLE
      break;

    default:                                          // Caso por seguridad si estado inválido
      Serial.println(F("Error: estadoSoftSerial inválido, reseteando a IDLE.")); // Mensaje de error
      estadoActual = ESTADO_IDLE;                     // Resetea a IDLE por seguridad
      break;
  }
}
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
