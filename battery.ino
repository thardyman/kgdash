

void readBattery(void){

  int tmp = analogRead(voltagePin);
  //converts raw data into v
  // Voltage dividor 9.8kohm / 1 kohm
  voltage = tmp * 0.05814; //0.0049; // * 10.8;  
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
  digitalWrite(gpsPower, LOW);
  digitalWrite(displayPower, LOW);
  odometerStore();

  // dying flicker
  do{
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  } while( true );
}
