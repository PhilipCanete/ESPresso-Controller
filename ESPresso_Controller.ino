#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "definitions.h"

//Initialize tft library, pins defined in definitions.h
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

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

  tft.fillScreen(BLACK);
  

  
  //Eventually will be saved to eeprom
  uint16_t setTemp = 1111;
  uint16_t realTemp = 1000;
  uint16_t timer = 10;
  
  //Set temp
          //Draw border, label, and value
            tft.drawRect(2, 2, tft.width()-4, (tft.height()/3)-2, GREEN);
            drawLabel(18, "Set");
            drawValue(Y_SETTEMP_VALUE, GREEN, setTemp);



  //Real temp
        //Draw border, label, and value
          tft.drawRect(2 , 2+tft.height()/3, tft.width()-4, (tft.height()/3)-2, RED);
          drawLabel(62, "Real");
          drawValue(Y_REALTEMP_VALUE, RED, setTemp);

  
  //Timer
        //Draw border, label, and value
          tft.drawRect(2, 2+2*(tft.height()/3), tft.width()-4, (tft.height()/3)-2, WHITE);
          drawLabel(104, "Timer");
          drawValue(100, WHITE, timer);
  
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

void drawValue(byte y, uint16_t color, uint16_t value) {
  tft.setCursor(X_VALUE, y);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.println(String(value));
}

///////////////todo //////////////
//4. Connect rotary encoder
//5. Figure out eeprom shit
//6. Create FSM for pushbutton logic
//7. Connect pusbutton
//8. Create screen updating logic
//9. Figure out wheatstone bridge
