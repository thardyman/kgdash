#include "U8glib.h"
#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial ss(4, 3);

float lastPositionLat = TinyGPS::GPS_INVALID_F_ANGLE;
float lastPositionLong = TinyGPS::GPS_INVALID_F_ANGLE;
float odometer = 0; // metres

const long recordingThreshold = 20; // metres

void odometer_draw() {
  u8g.setPrintPos(40, 56); 
  u8g.print("00000");
  u8g.print(odometer / 1609.34);
}

void odometer_setup() {
  ss.begin(9600);
}

void odometer_loop() {
  float distanceTravelled, flat, flong;
  unsigned long age;
  
  while (ss.available()){
    gps.encode(ss.read());
  }

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
}
