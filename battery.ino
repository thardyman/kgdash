

void readBattery(void){

  int tmp = analogRead(voltagePin);
  //converts raw data into v
  // Voltage divider 10kohm / 1 kohm
  // voltage = tmp * 0.05814; 
  voltage = tmp * 0.0049 * 11;
  if(voltage < 2){
    power_cut();
  }
}

void battery_init() {
}

void battery_loop() {
  readBattery();
}

void power_cut() {
//  digitalWrite(gpsPower, LOW);
//  digitalWrite(displayPower, LOW);
//  odometerStore();
  isPowerCut = true;

}
