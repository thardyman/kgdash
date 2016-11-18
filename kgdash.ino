/*

  Karmann Ghia Dashboard
  v0.0.0

  Author: Tim Hardyman

  Power sensor / regulator circuit idea...
  http://forum.arduino.cc/index.php?topic=121654.0

  N.b. I think I'll use a simplified version where the input is analog
  and used for the volt meter

  // TODO:

  - debug mode, to show raw data
  - Display coolant in gauge
  - Calibrate coolant gauge
  - Calibrate fuel gauge

  // Ideas:
  - Sense power cut and write to EEPROM
  - Add power supply control for GPS & Screen
  - Cut power to GPS / screen during power down to give more time for EEPROM write
  - display clock
  - adjust UTC to BST if necessary
  - display odometer reading on start up
  - make gauge display an object - to support memory / change animation etc
  - Add multiple dashboard layouts, switchable by button?
  - Add trip meter with reset option
  - Sense refuelling, and monitior miles since last refuel
  - Low tank warning light
  - High coolant temp warning light
  - monitor internal and external temperatures

*/


#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send AC

const long interval = 1000;  // interval at which to redraw dashboard
const int splashTime = 0; // how long to display the splash logo


int screenMode = 0;
unsigned long previousMillis = 0;
float temperature;
float fuel;
float voltage;
int isPowerCut = false;

// Analog input pins
int tempPin = 0;    // temperature
int coolantPin = 1; // coolant temperature
int fuelPin = 2;    // fuel level
int voltagePin = 3; // voltage


// digital output pins
int gpsPower = 5;  // GPS power
int displayPower = 6; // power to display

// digital input pins
int powerMonitor = 2;


void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}


void draw(void) {
  u8g_prepare();
  switch (screenMode) {
    case 1: dashboard_1_drawloop(); break;
  }
}


void setup(void) {
  pinMode(gpsPower, OUTPUT);
  pinMode(displayPower, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(powerMonitor, INPUT_PULLUP);
  digitalWrite(gpsPower, HIGH);
  digitalWrite(displayPower, HIGH);
  odometer_setup();
  attachInterrupt(digitalPinToInterrupt(powerMonitor), power_cut, RISING);
}

void readSensors() {
  // on each display cycle read all the sensors
  readTemperature();
  readFuel();
  readOdometer();
}

void loop(void) {
  unsigned long currentMillis = millis();
  odometer_loop();
  battery_loop();
  if (screenMode == 0) {
    drawSplashScreen();
    screenMode = 1;
    dashboard_1_init();
  } else {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      readSensors();
      switch (screenMode) {
        case 1: dashboard_1_progloop(); break;
      }

      u8g.firstPage();
      do {
        draw();
      } while ( u8g.nextPage() );
    }
  }
}

