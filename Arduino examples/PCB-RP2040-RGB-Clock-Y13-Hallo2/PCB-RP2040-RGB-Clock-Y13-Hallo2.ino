// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <DS3231.h>
#include <Fonts\Picopixel.h>
#include <pio_encoder.h>



#define RGB_PIN1 9
#define RGB_PIN2 8
#define RGB_ONBOARD_PIN 16
#define PIN_SDA 12
#define PIN_SCL 13
#define PIN_ENCODER 27
#define PIN_KEY 26 


PioEncoder encoder(PIN_ENCODER, false, 0, COUNT_4X, pio1); 

//PioEncoder(const uint8_t pin, const bool flip = false, const int zero_offset = 0, const uint8_t count_mode = COUNT_4X,
//                   PIO pio = pio0, const uint sm = -1, const int max_step_rate = 0);


// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(24, 8, RGB_PIN1,
  NEO_MATRIX_BOTTOM        + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS    + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB               + NEO_KHZ800);



Adafruit_NeoPixel pixels(1 , RGB_ONBOARD_PIN, NEO_GRB + NEO_KHZ800);

DS3231 ds3231 = DS3231(Wire);

void setup() {

  Serial.begin(115200);
  while (!Serial);             // wait for serial monitor
     Serial.println("Start");


// init matrix RGB

  matrix.begin();
  matrix.setFont(&Picopixel);
  matrix.setTextWrap(false);  
  matrix.setBrightness(10);
  matrix.setTextColor(matrix.Color(10, 0, 0));

// init DS3231
  Wire.setSDA(PIN_SDA);
  Wire.setSCL(PIN_SCL);
  Wire.begin();  

// encoder  

  encoder.begin();

// encoder KEY
  pinMode(PIN_KEY, INPUT);

}

int colorRgb2 = 0;

void loop() {

  bool h12Flag;
  bool pmFlag;
  int second = ds3231.getSecond();
  int minute = ds3231.getMinute();
  int hour   = ds3231.getHour(h12Flag, pmFlag);

  Serial.print("Time = "); 
  Serial.print(hour);   Serial.print(":");
  Serial.print(minute); Serial.print(":");
  Serial.println(second);

  Serial.print("Encoder = "); Serial.println(encoder.getCount());

	if (digitalRead(PIN_KEY) == 0)
  {
    Serial.println("Key pressed ");
  }

  matrix.fillScreen(0);  
  matrix.setTextColor(matrix.Color(255, 0, 0));

  matrix.setCursor(0, 5);
  matrix.print(hour);

  matrix.setCursor(8, 5);
  matrix.print(minute);

  matrix.setCursor(16, 5);
  matrix.print(second);

  matrix.show();



  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(100-colorRgb2, colorRgb2, 0));

  colorRgb2 = colorRgb2 + 10;
  
  if (colorRgb2 > 100)
      colorRgb2 = 1;

  pixels.show();   // Send the updated pixel colors to the hardware.
  
  delay(500);
}
