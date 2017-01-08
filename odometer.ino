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

char rawGPS;
unsigned long gpsStatsChars;
unsigned short gpsStatsSentances, gpsStatsFailedChecksum;


void odometer_draw() {
  float miles = odometer / 1609.34;
  int size = 1000000;

  u8g.setPrintPos(90, 0);
  u8g.print(rawGPS);

  u8g.setPrintPos(20, 10);
  u8g.print("CH:");
  u8g.print(gpsStatsChars);  
  u8g.print(" S:");  
  u8g.print(gpsStatsSentances);  
  u8g.print(" F:");  
  u8g.print(gpsStatsFailedChecksum);  
//  u8g.print("Lat: ");
//  u8g.print(lastPositionLat);

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
    rawGPS = ss.read();
    gps.encode(rawGPS);
  }
}

void readOdometer(){
  float distanceTravelled, flat, flong;
  unsigned long age;

  int year;
  byte month, day, hour, minutes, second, hundredths;
 
  gps.f_get_position(&flat, &flong, &age);
  gps.stats(&gpsStatsChars, &gpsStatsSentances, &gpsStatsFailedChecksum);
  
  if (flat != TinyGPS::GPS_INVALID_F_ANGLE && flong != TinyGPS::GPS_INVALID_F_ANGLE){

   gps.crack_datetime(&year, &month, &day,
    &hour, &minutes, &second, &hundredths, &age);

   lastFixTime = String(hour) + ":" + String(minutes);
    
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
