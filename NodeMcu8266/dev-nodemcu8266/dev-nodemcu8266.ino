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
const uint8_t softRX = 0;            //| 
const uint8_t softTX = 2;            //|  
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
const uint8_t targetID = 0;          //| Un ID especial reservado para algun fin especifico.
const uint8_t mySlaveID = 10;        //| Mi ID de Esclavo
const uint8_t toMasterID = 8;        //| El ID de al menos un Maestro
const uint8_t broadcastID = 255;     //| Un ID para MultiDifusion
///////////////////////////////////////| 
uint16_t commSend = 0;               //|
uint16_t commErr = 0;                //|
uint16_t commOk = 0;                 //|
//////////////////////////////////////////////| 
const uint16_t softSerialBautRate = 9600;   //| Velocidad del SoftwareSerial
const uint32_t hardSerialBautRate = 115200; //| Velocidad del Hardware Serial
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
float valPinA0 = 000.00, valPinA1 = 000.00, valPinA2 = 000.00, valPinA3 = 000.00, valPinA4 = 000.00, valPinA5 = 000.00;
uint8_t /*valPinD0 = 0, valPinD1 = 0, valPinD2 = 0,*/ valPinD3 = 0, /*valPinD4 = 0,*/ valPinD5 = 0;
uint8_t valPinD6 = 0, valPinD7 = 0, valPinD8 = 0, valPinD9 = 0, valPinD10 = 0, valPinD11 = 0, valPinD12 = 0, valPinD13 = 0;
char valCharEnd = '>';
//_________________________________________________________
// Configuracion dedicada a la comunicacion Software Serial  
SoftwareSerial softSerial(softRX, softTX); // Instanciamos SoftwareSerial con pines RX y TX definidos
//#pragma pack(1) // Definición del struct para manejar datos con directivas globales de empaquetamiento alineado a 1 byte sin relleno.
// Definición del struct para manejar datos con atributo especifico de empaquetamiento alineado a 1 byte sin relleno.
struct __attribute__((packed, aligned(1))) DataPacket {
  char charInit;            // Carácter de inicio del paquete
  uint8_t sourceID;         // ID de dispositivo remitente de origen
  uint8_t destinationID;    // ID de dispositivo destinatario
  
  bool varMasterLoadConfig; // Estado lógico = 8 bits = 1 Byte
  bool varSlaveLoadConfig; // Estado lógico = 8 bits = 1 Byte
  bool varFlagRestart; // Estado lógico = 8 bits = 1 Byte
  float varPinA0, varPinA1, varPinA2, varPinA3, varPinA4, varPinA5; // [(un solo float = 32 bits = 4 Bytes) x6] = 24 Bytes
  uint8_t /*varPinD0, varPinD1, varPinD2,*/ varPinD3, /*varPinD4,*/ varPinD5; // [(8 bits = 1 Byte) x2] = 2 Bytes
  uint8_t varPinD6, varPinD7, varPinD8, varPinD9, varPinD10, varPinD11, varPinD12, varPinD13; // [(8 bits = 1 Byte) x8] = 8 Bytes
  
  uint8_t structSize;       // Tamaño del struct = 8 bits = 1 Byte
  uint8_t checksum;         // Para el checksum (1 Byte)
  uint16_t crc;             // Para el CRC (2 Bytes)
  char charEnd;             // Carácter de fin del paquete
}; // #pragma pack() // Restaura las directivas globales del empaquetamiento a su propio predeterminado.
// Variables globales para el struct de Inicialización explícita con caracteres de control
DataPacket dataEnvio = {'<', 0, 0, false, false, true, 000.00, 000.00, 000.00, 000.00, 000.00, 000.00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, sizeof(DataPacket), 0, 0, '>'}; // Inicialización explícita con caracteres de control
DataPacket dataRecibido = {'<', 0, 0, true, true, false, 000.00, 000.00, 000.00, 000.00, 000.00, 000.00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '>'}; // Inicialización para recepción con caracteres de control
//_________________________________________________________
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
// Prototipos de funciones
void setupInit(); // Configuraciónes iniciales del hardwardware
void setupHardSerial(); // Configura el Hardware Serial 
void setupSoftSerial(); // Configura el Softdware Serial
void setupI2C(); // Inicializa puerto de comunicacion I2C
void setupSPI(); // Inicializa puerto de comunicacion SPI
void setupFileSystem(); // Configurar Sistema de Archivos Interno ./LittleFS
void setupFileSystemExt(); // Configurar Sistema de Archivos Externo ./SD 
void setupConfigPins(); // Configura los pines como entrada o salida según corresponda
void setupPrintInfoVersion(); // Imprime Informacion y Detalles del Proyecto
void setupEnd(); // Configuraciones finales y Mensaje de finalización del setup
void calcularChecksum(); // Calcula el checksum y lo almacena directamente en el paquete
void calcularCRC();  // Calcula el CRC y lo almacena directamente en el paquete
void printSending(); // Imprime los datos enviados en varios formatos
void printReceived(); // Imprime los datos recibidos en varios formatos
void printVarsInternal(); // Imprime los datos de las variables intenas en varios formatos
void printFileConfig(); // Imprime el contenido del archivo de configuración
void readSaveConfig(); // Lee el Archivo de Configuraciones
void writeSaveConfig(); // Escribe el Archivo de Configuraciones
void deleteSaveConfig(); // Elimina el Archivo de Configuraciones
void updateStruct(); // Función para actualizar las variables independientes desde el struct recibido
void updateVars(); // Función para actualizar las variables independientes desde el struct recibido
void rwDataPins(); // Lee y escribe correspondientemente los pines segun las variables globales
void readSoftSerial(); // Enviar datos mediante SoftwareSerial
void sendSoftSerial();// Leer datos recibidos mediante SoftwareSerial
void handleSoftSerial(); // Manejo del Software Serial (envío y recepción)
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void setup() {
  setupInit(); // Configuraciónes iniciales del hardwardware
  setupEnd();  // Configuraciones finales y Mensaje de finalización del setup
}
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
void setupInit(){ // Configuraciónes iniciales del hardwardware
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
void setupHardSerial(){ // Configura el Hardware Serial
  Serial.begin(hardSerialBautRate, SERIAL_8N1); // Inicializa puerto de comunicacion Hardware Serial
  Serial.println(F("Iniciando..."));
  Serial.println(F("Puerto Hardware Serial: Iniciado Correctamente."));
}
void setupSoftSerial(){ // Configura el Software Serial
  pinMode(softRX, INPUT);    // Configura el pin RX como entrada
  pinMode(softTX, OUTPUT);   // Configura el pin TX como salida
  softSerial.begin(softSerialBautRate); // Inicializa puerto de comunicacion Software Serial
  Serial.println(F("Puerto Software Serial: Iniciado Correctamente."));
}
void setupI2C() {  // Inicializa puerto de comunicacion I2C
  Wire.begin(pinSDA, pinSCL);
  Serial.println("Puerto I2C: Iniciado Correctamente.");
}
void setupSPI(){  // Inicializa puerto de comunicacion SPI
  SPI.begin();
  Serial.println("Puerto SPI: Iniciado Correctamente.");
}
void setupFileSystem(){ // Configurar Sistema de Archivos Interno ./LittleFS
  if (!LittleFS.begin()) {
    Serial.println("Fallo el Punto de Montaje ./LittleFS");
    return;
  }
  fileSystemConfig.setAutoFormat(false);
  fileSystem->setConfig(fileSystemConfig);
  fsOK = fileSystem->begin();
  Serial.println(fsOK ? F("Filesystem inicializado.") : F("Filesystem Fallo!"));
}
void setupFileSystemExt(){ // Configurar Sistema de Archivos Externo ./SD
  if (!SD.begin(CS_SD)) {  // Asegúrate de usar el pin correcto para tu módulo SD
    Serial.println("Error al inicializar SD");
    return;
  }
}
void setupConfigPins(){ // Configura los pines como entrada o salida según corresponda
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //gpio17
  Serial.println(F("Inicialización y configuración de pines completada."));  
}
void setupPrintInfoVersion(){ // Imprime Informacion y Detalles del Proyecto
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
  Serial.println(F("|    Count Versions Previous: 30                                               |"));
  Serial.println(F("|    Current Date Version: V. 0.3.1 - 26th January 2025                        |"));
  Serial.println(F("|                                                                              |"));
  Serial.println(F("================================================================================"));
  Serial.println();
  Serial.println();  
}
void setupEnd(){ // Configuraciones finales y Mensaje de finalización del setup

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
void calcularChecksum(DataPacket* paquete) { // Calcula el checksum y lo almacena directamente en el paquete
  uint8_t suma = 0;
  uint8_t* ptr = reinterpret_cast<uint8_t*>(paquete);
  for (size_t i = 0; i < sizeof(DataPacket) - 3; i++) { // Excluye checksum y CRC
    suma += ptr[i];
  }
  paquete->checksum = suma; // Actualiza el campo checksum
}
void calcularCRC(DataPacket* paquete) { // Calcula el CRC y lo almacena directamente en el paquete
  uint16_t crc = 0xFFFF; // Valor inicial
  uint8_t* ptr = reinterpret_cast<uint8_t*>(paquete);
  for (size_t i = 0; i < sizeof(DataPacket) - 2; i++) { // Excluye el campo CRC
    crc ^= (uint16_t)ptr[i] << 8;
    for (uint8_t j = 0; j < 8; j++) {
      if (crc & 0x8000) crc = (crc << 1) ^ 0x8005;
      else crc = crc << 1;
    }
  }
  paquete->crc = crc; // Actualiza el campo CRC
}

void printSending() { // Imprime los datos enviados en varios formatos
  Serial.println(F("Datos enviados:"));
  Serial.print(F("Inicio: ")); Serial.print(dataEnvio.charInit); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.charInit, HEX); Serial.println(F(")"));
  Serial.print(F("SourceID: ")); Serial.print(dataEnvio.sourceID); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.sourceID, HEX); Serial.println(F(")"));
  Serial.print(F("DestinationID: ")); Serial.print(dataEnvio.destinationID); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.destinationID, HEX); Serial.println(F(")"));
  
  Serial.print(F("Estado del Maestro: ")); Serial.println(dataEnvio.varMasterLoadConfig ? "true" : "false");
  Serial.print(F("Estado del Esclavo: ")); Serial.println(dataEnvio.varSlaveLoadConfig ? "true" : "false");
  Serial.print(F("Estado de Reinicio: ")); Serial.println(dataEnvio.varFlagRestart ? "true" : "false");
  
  Serial.println(F("Valores Pines Analogicos: "));
  Serial.print(F("A0 ")); Serial.print(dataEnvio.varPinA0); 
  Serial.print(F(", A1 ")); Serial.print(dataEnvio.varPinA1); 
  Serial.print(F(", A2 ")); Serial.print(dataEnvio.varPinA2); 
  Serial.print(F(", A3 ")); Serial.print(dataEnvio.varPinA3);
  Serial.print(F(", A4 ")); Serial.print(dataEnvio.varPinA4); 
  Serial.print(F(", A5 ")); Serial.print(dataEnvio.varPinA5); 
  Serial.println(F(". ")); 
  
  Serial.println(F("Valores Pines Digitales: "));
  //Serial.print(F("D0 ")); Serial.print(dataEnvio.varPinD0); 
  //Serial.print(F(", D1 ")); Serial.print(dataEnvio.varPinD1); 
  //Serial.print(F(", D2 ")); Serial.print(dataEnvio.varPinD2); 
  Serial.print(F("D3 ")); Serial.print(dataEnvio.varPinD3); 
  //Serial.print(F(", D4 ")); Serial.print(dataEnvio.varPind4);
  Serial.print(F(", D5 ")); Serial.print(dataEnvio.varPinD5); 
  Serial.print(F(", D6 ")); Serial.print(dataEnvio.varPinD6);
  Serial.print(F(", D7 ")); Serial.print(dataEnvio.varPinD7); 
  Serial.print(F(", D8 ")); Serial.print(dataEnvio.varPinD8);
  Serial.print(F(", D9 ")); Serial.print(dataEnvio.varPinD9);
  Serial.print(F(", D10 ")); Serial.print(dataEnvio.varPinD10);
  Serial.print(F(", D11 ")); Serial.print(dataEnvio.varPinD11); 
  Serial.print(F(", D12 ")); Serial.print(dataEnvio.varPinD12); 
  Serial.print(F(", D13 ")); Serial.print(dataEnvio.varPinD13); 
  Serial.println(F(". "));
  
  Serial.print(F("Tamaño del paquete: ")); Serial.print(dataEnvio.structSize); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.structSize, HEX); Serial.println(F(")"));
  Serial.print(F("CheckSum del paquete: ")); Serial.print(dataEnvio.checksum); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.checksum, HEX); Serial.println(F(")"));
  Serial.print(F("CRC del paquete: ")); Serial.print(dataEnvio.crc); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.crc, HEX); Serial.println(F(")"));
  Serial.print(F("Fin: ")); Serial.print(dataEnvio.charEnd); Serial.print(F(" (Hex: 0x")); Serial.print(dataEnvio.charEnd, HEX); Serial.println(F(")"));
  Serial.println(F(" "));
}
void printReceived() { // Imprime los datos recibidos en varios formatos
  Serial.println(F("Datos recibidos:"));
  Serial.print(F("Inicio: ")); Serial.print(dataRecibido.charInit); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.charInit, HEX); Serial.println(F(")"));
  Serial.print(F("SourceID: ")); Serial.print(dataRecibido.sourceID);  Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.sourceID, HEX); Serial.println(F(")"));
  Serial.print(F("DestinationID: ")); Serial.print(dataRecibido.destinationID); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.destinationID, HEX); Serial.println(F(")"));
  
  Serial.print(F("Estado del Maestro: ")); Serial.println(dataRecibido.varMasterLoadConfig ? "true" : "false");
  Serial.print(F("Estado del Esclavo: ")); Serial.println(dataRecibido.varSlaveLoadConfig ? "true" : "false");
  Serial.print(F("Estado de Reinicio: ")); Serial.println(dataRecibido.varFlagRestart ? "true" : "false");
  
  Serial.println(F("Valores Pines Analogicos: "));
  Serial.print(F("A0 ")); Serial.print(dataRecibido.varPinA0); 
  Serial.print(F(", A1 ")); Serial.print(dataRecibido.varPinA1); 
  Serial.print(F(", A2 ")); Serial.print(dataRecibido.varPinA2); 
  Serial.print(F(", A3 ")); Serial.print(dataRecibido.varPinA3);
  Serial.print(F(", A4 ")); Serial.print(dataRecibido.varPinA4); 
  Serial.print(F(", A5 ")); Serial.print(dataRecibido.varPinA5); 
  Serial.println(F(". ")); 
  
  Serial.println(F("Valores Pines Digitales: "));
  //Serial.print(F("D0 ")); Serial.print(dataRecibido.varPinD0); 
  //Serial.print(F(", D1 ")); Serial.print(dataRecibido.varPinD1); 
  //Serial.print(F(", D2 ")); Serial.print(dataRecibido.varPinD2); 
  Serial.print(F("D3 ")); Serial.print(dataRecibido.varPinD3); 
  //Serial.print(F(", D4 ")); Serial.print(dataRecibido.varPind4);
  Serial.print(F(", D5 ")); Serial.print(dataRecibido.varPinD5); 
  Serial.print(F(", D6 ")); Serial.print(dataRecibido.varPinD6);
  Serial.print(F(", D7 ")); Serial.print(dataRecibido.varPinD7); 
  Serial.print(F(", D8 ")); Serial.print(dataRecibido.varPinD8);
  Serial.print(F(", D9 ")); Serial.print(dataRecibido.varPinD9);
  Serial.print(F(", D10 ")); Serial.print(dataRecibido.varPinD10);
  Serial.print(F(", D11 ")); Serial.print(dataRecibido.varPinD11); 
  Serial.print(F(", D12 ")); Serial.print(dataRecibido.varPinD12); 
  Serial.print(F(", D13 ")); Serial.print(dataRecibido.varPinD13); 
  Serial.println(F(". ")); 
  
  Serial.print(F("Tamaño del paquete: ")); Serial.print(dataRecibido.structSize); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.structSize, HEX); Serial.println(F(")"));
  Serial.print(F("CheckSum del paquete: ")); Serial.print(dataRecibido.checksum); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.checksum, HEX); Serial.println(F(")"));
  Serial.print(F("CRC del paquete: ")); Serial.print(dataRecibido.crc); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.crc, HEX); Serial.println(F(")"));
  Serial.print(F("Fin: ")); Serial.print(dataRecibido.charEnd); Serial.print(F(" (Hex: 0x")); Serial.print(dataRecibido.charEnd, HEX); Serial.println(F(")"));
  Serial.println(F(" "));
}
void printVarsInternal() { // Imprime los datos de las variables intenas en varios formatos
  
  Serial.println(F("Datos de Variables Independientes Internas:"));
  Serial.print(F("Inicio: ")); Serial.println(valCharInit);
  Serial.print(F("Estado del Maestro: ")); Serial.println(master_loadConfig ? "true" : "false");
  Serial.print(F("Estado del Esclavo: ")); Serial.println(slave_loadConfig ? "true" : "false");
  Serial.print(F("Estado de Reinicio: ")); Serial.println(flag_restart ? "true" : "false");
  
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
  //Serial.print(F(", D4 ")); Serial.print(valPind4);
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
  Serial.println(F(" "));

}
void printFileConfig() { // Imprime el contenido del archivo de configuración
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

void readSaveConfig() { // Lee el Archivo de Configuraciones
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
      valPinA0 = doc["valPinA0"] | 000.00;
      valPinA1 = doc["valPinA1"] | 000.00;
      valPinA2 = doc["valPinA2"] | 000.00;
      valPinA3 = doc["valPinA3"] | 000.00;
      valPinA4 = doc["valPinA4"] | 000.00;
      valPinA5 = doc["valPinA5"] | 000.00;

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
void writeSaveConfig() { // Escribe el Archivo de Configuraciones
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
void deleteSaveConfig() { // Elimina el Archivo de Configuraciones
  if (LittleFS.remove("/config.txt")) {
    Serial.println(F("Archivo de configuración eliminado."));
  } else {
    Serial.println(F("No se pudo eliminar el archivo de configuración."));
  }
}

void updateStruct() { // Función para actualizar el struct desde las variables independientes

  // Asigna identificadores de origen, destino y tamaño.
  dataEnvio.sourceID = mySlaveID; // El remitente es este dispositivo
  dataEnvio.destinationID = toMasterID; // El destinatario es un Maestro específico
  // dataEnvio.destinationID = broadcastID; // El destinatario es MultiDifusión)

  dataEnvio.varMasterLoadConfig = master_loadConfig;
  dataEnvio.varSlaveLoadConfig = slave_loadConfig;
  dataEnvio.varFlagRestart = flag_restart;

  dataEnvio.varPinA0 = valPinA0;
  dataEnvio.varPinA1 = valPinA1;
  dataEnvio.varPinA2 = valPinA2;
  dataEnvio.varPinA3 = valPinA3;
  dataEnvio.varPinA4 = valPinA4;
  dataEnvio.varPinA5 = valPinA5;

  //dataEnvio.varPinD0 = valPinD0;
  //dataEnvio.varPinD1 = valPinD1;
  //dataEnvio.varPinD2 = valPinD2;
  dataEnvio.varPinD3 = valPinD3;
  //dataEnvio.varPinD4 = valPinD4;
  dataEnvio.varPinD5 = valPinD5;
  dataEnvio.varPinD6 = valPinD6;
  dataEnvio.varPinD7 = valPinD7;
  dataEnvio.varPinD8 = valPinD8;
  dataEnvio.varPinD9 = valPinD9;
  dataEnvio.varPinD10 = valPinD10;
  dataEnvio.varPinD11 = valPinD11;
  dataEnvio.varPinD12 = valPinD12;
  dataEnvio.varPinD13 = valPinD13;

  dataEnvio.structSize = sizeof(dataEnvio); // Actualiza el campo structSize con el tamaño actual del struct
  calcularChecksum(&dataEnvio); // Calcula y actualiza el checksum
  calcularCRC(&dataEnvio);      // Calcula y actualiza el CRC

}
void updateVars() { // Función para actualizar las variables independientes desde el struct recibido
  
  master_loadConfig = dataRecibido.varMasterLoadConfig;  
  slave_loadConfig = dataRecibido.varSlaveLoadConfig;  
  flag_restart = dataRecibido.varFlagRestart;  

  valPinA0 = dataRecibido.varPinA0;  
  valPinA1 = dataRecibido.varPinA1;  
  valPinA2 = dataRecibido.varPinA2;  
  valPinA3 = dataRecibido.varPinA3;  
  valPinA4 = dataRecibido.varPinA4;  
  valPinA5 = dataRecibido.varPinA5;  

  //valPinD0 = dataRecibido.varPinD0;
  //valPinD1 = dataRecibido.varPinD1;
  //valPinD2 = dataRecibido.varPinD2;
  valPinD3 = dataRecibido.varPinD3; 
  //valPinD4 = dataRecibido.varPinD4;
  valPinD5 = dataRecibido.varPinD5;
  valPinD6 = dataRecibido.varPinD6;
  valPinD7 = dataRecibido.varPinD7;
  valPinD8 = dataRecibido.varPinD8;
  valPinD9 = dataRecibido.varPinD9;
  valPinD10 = dataRecibido.varPinD10;
  valPinD11 = dataRecibido.varPinD11;
  valPinD12 = dataRecibido.varPinD12;
  valPinD13 = dataRecibido.varPinD13;

}
void rwDataPins(){ // Lee y escribe correspondientemente los pines segun las variables globales
  
  //gpio17
  writeSaveConfig();
}

void sendSoftSerial() { // Enviar datos mediante SoftwareSerial

  if (millis() >= timeLine0 + 500) { // Comprueba si ha pasado el intervalo de tiempo

    timeLine0 = millis(); // Actualiza el tiempo de referencia

    digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED para indicar envío

    updateStruct(); // Actualiza el struct con las variables antes de enviar

    softSerial.write(reinterpret_cast<uint8_t*>(&dataEnvio), sizeof(dataEnvio)); // Envía el struct como un bloque de bytes

    printSending(); // Imprime los datos de las variables enviadas

    rwDataPins(); // Lee y escribe correspondientemente los pines segun las variables globales

    digitalWrite(LED_BUILTIN, LOW); // Apaga el LED tras el envío

    commSend++;
      Serial.print(F("Envio N° : "));
      Serial.println(commSend);
  }
}
void readSoftSerial() { // Leer datos recibidos mediante SoftwareSerial

  if (softSerial.available() >= sizeof(dataRecibido)) { // Comprueba si hay suficientes datos para leer

    // Lee los bytes del SoftwareSerial al struct
    softSerial.readBytes(reinterpret_cast<uint8_t*>(&dataRecibido), sizeof(dataRecibido));

    // Valida el checksum y el CRC
    uint8_t checksumCalculado;
    uint16_t crcCalculado;

    calcularChecksum(&dataRecibido);
    calcularCRC(&dataRecibido);

    checksumCalculado = dataRecibido.checksum; // Checksum ya calculado
    crcCalculado = dataRecibido.crc;          // CRC ya calculado

    if ((dataRecibido.charInit == '<') && // Primera validación: caracteres de control
        (dataRecibido.charEnd == '>') && // Segunda validación: caracteres de control
        (dataRecibido.structSize == sizeof(dataRecibido)) && // Tercera validación: comparar tamaño declarado con el tamaño real
        (dataRecibido.checksum == checksumCalculado) && // Cuarta validación: calcular Checksum
        (dataRecibido.crc == crcCalculado) &&  // Quinta validación: calcular CRC
        (dataRecibido.destinationID == mySlaveID || dataRecibido.destinationID == broadcastID)) { // Sexta validación: Verificar el destinatario especifico o multidifusion

      printReceived(); // Imprime los datos de las variables recibidas
      updateVars(); // Actualiza las variables independientes después de recibir
      printVarsInternal(); // Imprime los datos de las variables intenas
      rwDataPins(); // Lee y escribe correspondientemente los pines segun las variables globales
      commOk++;
      Serial.print(F("Comunicacion Correcta N° : "));
      Serial.println(commOk);
    } else { // Manejo de Errores.
      if (dataRecibido.charInit != '<') { // Error: Caracteres de control inválido
        Serial.println(F("Error: Caracteres de control inválidos."));
        Serial.print(F("Caracter Inicio Recibido: ")); Serial.println(dataRecibido.charInit);
        Serial.print(F("Bytes Recibidos: ")); Serial.println(dataRecibido.structSize);
        Serial.println(F(" "));
      }
      if (dataRecibido.charEnd != '>') { // Error: Caracteres de control inválido
        Serial.println(F("Error: Caracteres de control inválidos."));
        Serial.print(F("Caracter Fin Recibido: ")); Serial.println(dataRecibido.charEnd);
        Serial.print(F("Bytes Recibidos: ")); Serial.println(dataRecibido.structSize);
        Serial.println(F(" "));
      }
      if (dataRecibido.structSize != sizeof(dataRecibido)) { // Error: Tamaño declarado no coincide con el real
        Serial.println(F("Error: Tamaño del paquete no coincide con el declarado."));
        Serial.print(F("Tamaño Real del Struct: ")); Serial.println(sizeof(dataRecibido));
        Serial.print(F("Tamaño Declarado Recibido: ")); Serial.println(dataRecibido.structSize);
        Serial.print(F("Bytes Recibidos: ")); Serial.println(dataRecibido.structSize);
        Serial.println(F(" "));
      }
      if (dataRecibido.checksum != checksumCalculado) { // Error: Checksum No Corresponde
        Serial.println(F("Error: Checksum incorrecto."));
        Serial.print(F("Checksum Declarado Recibido: ")); Serial.println(dataRecibido.checksum);
        Serial.print(F("Checksum Calculado: ")); Serial.println(checksumCalculado);
        Serial.println(F(" "));
      }
      if (dataRecibido.crc != crcCalculado) { // Error: CRC No Corresponde
        Serial.println(F("Error: CRC incorrecto."));
        Serial.print(F("CRC Declarado Recibido: ")); Serial.println(dataRecibido.crc);
        Serial.print(F("CRC Calculado: ")); Serial.println(crcCalculado);
        Serial.println(F(" "));
      }
      if (dataRecibido.destinationID != mySlaveID &&
          dataRecibido.destinationID != toMasterID &&
          dataRecibido.destinationID != broadcastID &&
          dataRecibido.destinationID != targetID) { // Error: DispositivoID No Reconocido
        Serial.println(F("Error: El ID recibido no está en la lista de IDs válidos."));
        Serial.print(F("ID Recibido: ")); Serial.println(dataRecibido.destinationID);
        Serial.println(F(" "));
      }
      commErr++;
      Serial.print(F("Comunicacion Erronea N° : "));
      Serial.println(commErr);
    }
  }
}

void handleSoftSerial() { // Manejo del Software Serial (envío y recepción)
  sendSoftSerial();
  readSoftSerial();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////////////////////////////////////////////////////////////////////  
