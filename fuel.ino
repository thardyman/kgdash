void readFuel(void){

  int tmp = analogRead(fuelPin);
  //converts raw data into %
  fuel = tmp / 1024;  
 
}