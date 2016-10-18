/*

 Karmann Ghia Dashboard
 v0.0.0

 Author: Tim Hardyman

 Power sensor / regulator...
 http://forum.arduino.cc/index.php?topic=121654.0
*/


#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send AC

const long interval = 1000;  // interval at which to redraw dashboard
const int splashTime = 0; // how long to display the splash logo


int screenMode = 0;
unsigned long previousMillis = 0;
float temperature;
float fuel;

int tempPin = 0;    // analog input pin for temperature
int coolantPin = 1; // analog input pin for coolant temperature
int fuelPin = 2;    // analog input pin for fuel level
int voltagePin = 3; // analog input pin for voltage



void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}


void draw(void) {
  u8g_prepare();
  switch(screenMode) {
    case 1: dashboard_1_drawloop(); break;
  }
}


void setup(void) {

}

void readSensors(){
  // on each display cycle read all the sensors
  readTemperature();  
  readFuel();
}

void loop(void) {
  unsigned long currentMillis = millis();

  if(screenMode == 0){
    drawSplashScreen();
    screenMode = 1;
    dashboard_1_init();
  } else {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      readSensors();
      switch(screenMode) {
        case 1: dashboard_1_progloop(); break;
      }
      
      u8g.firstPage();  
      do {
        draw();
      } while( u8g.nextPage() );
    }
  }
}

