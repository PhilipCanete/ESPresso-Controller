#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "definitions.h"

// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));

  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab


  Serial.println(F("Initialized"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  //rotate screen
  tft.setRotation(1);

  Serial.println("done");
  delay(1000);

  tft.fillScreen(BLACK);
  
  #define X_LABEL 12
  #define X_VALUE 75

  //Set temp
        //Draw border
         tft.drawRect(2, 2, tft.width()-4, (tft.height()/3)-2, GREEN);
    
        //Draw label
            drawLabel(18, "Set Temp");
    
        //Draw number
            drawValue(14, RED, "42.0");



  //Real temp
          //Draw border
          tft.drawRect(2 , 2+tft.height()/3, tft.width()-4, (tft.height()/3)-2, RED);
    
          //Draw label
              drawLabel(62, "Real Temp");
    
          //Draw number
              drawValue(58, GREEN, "42.0");

  
  //Timer
          //Draw border
          tft.drawRect(2, 2+2*(tft.height()/3), tft.width()-4, (tft.height()/3)-2, WHITE);
    
          //Draw label
              drawLabel(104, "Timer");
    
          //Draw number
              drawValue(100, WHITE, "42.0");
  
  Serial.println("done setup");
}


void loop() {

}



void drawLabel(byte y, String text){
  tft.setCursor(X_LABEL, y);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println(text);
}

void drawValue(byte y, uint16_t color,String text) {
  tft.setCursor(X_VALUE, y);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.println("42.0");
}



///////////////todo //////////////
//1. Turn text write blocks into functions
//2. FIgure out how to define shit in other classes
//3. Figure out hardware spi
