#include <Arduino.h>
#include <NeoPixelConnect.h>
#include <Wire.h>
#include <DS3231.h>


#define PIN_SDA 6 
#define PIN_SCL 7 
#define PIN_RGB 9 

NeoPixelConnect* neoPix;
DS3231* ds3231;

uint second = 1; 

void setup() 
{

  Serial.begin(115200);
  while (!Serial);             // wait for serial monitor
     Serial.println("Start");

// init NeoPix
  neoPix = new NeoPixelConnect(9, (uint16_t)256);   

// init DS3231
  Wire1.setSDA(6);
  Wire1.setSCL(7);
  Wire1.begin();
  ds3231 = new DS3231(Wire1);
}

void loop()
{

   int x = ds3231->getSecond();

   Serial.println(x);

  neoPix->neoPixelClear();
  delay(1);
  neoPix->neoPixelSetValue(x, 0, 10, 10);
  neoPix->neoPixelShow();

  delay(1000);

}




v