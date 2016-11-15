#include "U8glib.h"
#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

TinyGPS gps;
SoftwareSerial ss(4, 3);

float lastPositionLat = TinyGPS::GPS_INVALID_F_ANGLE;
float lastPositionLong = TinyGPS::GPS_INVALID_F_ANGLE;
float odometer = 0; // metres

int eepromAddress = 0;
float storedOdometer = 0;
const long recordingThreshold = 20; // metres
const long eepromThreshold = 500; // metres

void odometer_draw() {
  float miles = odometer / 1609.34;
  int size = 1000000;

  u8g.setPrintPos(20, 41);
  u8g.print("lng: ");
  u8g.print(lastPositionLong);

  u8g.setFont(u8g_font_9x18);

  u8g.setPrintPos(20, 64); 
  while(miles < size){
    u8g.print("0");
    size = size / 10;
  }
  u8g.print(miles);
}

void odometer_setup() {
  ss.begin(9600);
  EEPROM.get(eepromAddress, storedOdometer);
  if(storedOdometer != storedOdometer){ // check for NaN
    storedOdometer = 0;    
  }
  odometer = storedOdometer;
}

void odometer_loop() {
  while (ss.available()){
    gps.encode(ss.read());
  }
}

void readOdometer(){
  float distanceTravelled, flat, flong;
  unsigned long age;
  
  gps.f_get_position(&flat, &flong, &age);

  if (flat != TinyGPS::GPS_INVALID_F_ANGLE && flong != TinyGPS::GPS_INVALID_F_ANGLE){
    if(lastPositionLat == TinyGPS::GPS_INVALID_F_ANGLE){
      // first fix
      lastPositionLat = flat;
      lastPositionLong = flong;
    } else {
      distanceTravelled = TinyGPS::distance_between(lastPositionLat, lastPositionLong, flat, flong);
      if(distanceTravelled > recordingThreshold){
        // only record larger distances to avoid adding all minor GPS deviations
        odometer = odometer + distanceTravelled;
        lastPositionLat = flat;
        lastPositionLong = flong;
      }
    }
  }

  if(odometer - storedOdometer > eepromThreshold){
    odometerStore();  
  }
}

void odometerStore(){
  EEPROM.put(eepromAddress, odometer);
  storedOdometer = odometer;
}
