/*
 * Simple Temperature uses the lm35 in the basic centigrade temperature configuration
*/

void readTemperature(void){
  //gets the raw data from the lm35
  int temp = analogRead(tempPin);

  //converts raw data into degrees celsius
  // 500mV/1024=.48828125
  temperature = temp * 0.48828125; 
}

