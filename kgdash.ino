/*

 Karmann Ghia Dashboard
 v0.0.0

 Author: Tim Hardyman
*/


#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send AC

const long interval = 1000;  // interval at which to redraw
const int splashTime = 4000; // how long to display the splash logo


int screenMode = 0;
unsigned long previousMillis = 0;


void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}


void showDashboard() {
  u8g.drawStr( 0, 0, "Dashboard init");
}


void draw(void) {
  u8g_prepare();
  switch(screenMode) {
    case 0: showSplashScreen(); break;
    case 1: showDashboard(); break;
  }
}


void setup(void) {

}

void loop(void) {
  unsigned long currentMillis = millis();
  if(screenMode == 0 && millis() > splashTime){
    screenMode++;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    u8g.firstPage();  
    do {
      draw();
    } while( u8g.nextPage() );
  
  }
}

