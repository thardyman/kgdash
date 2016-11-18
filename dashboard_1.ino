// Dashboard 1

/*

  ----------------------------------------------------------
|  -----                                              ----- |
|  -----                                              ----- |
|  ----                                                ---- |
|  ----                                                ---- |
|  ---                                                  --- |
|  ---                                                  --- |
|  --                                                    -- |
|  --                                                    -- |
  ----------------------------------------------------------

  ^ fuel                                             temp ^

*/




// init is called once when the screen is switched to dashboard1
void dashboard_1_init() {

}

// prog loop allows us to set any global variables
void dashboard_1_progloop() {

}

// draw loop is should contain all the code to display the screen
void dashboard_1_drawloop() {
  bar_gauge(0, 2, 7, 0, fuel / 100);
  bar_gauge(128, 2, 7, 1, temperature / 40);  // really this should be coolant!
  
  u8g.setPrintPos(20, 0);
  u8g.print("Power: ");
    
  if(digitalRead(powerMonitor) == HIGH){
    u8g.print("HI");
  } else {
    u8g.print("LO");
  }
  if(isPowerCut){
    u8g.print(" (CUT)");
  }

  u8g.setPrintPos(20, 20);
  u8g.print("Temp: "); u8g.print(temperature); u8g.print(" *c");
  u8g.setPrintPos(20, 32);
  u8g.print(voltage);
  u8g.print("v");
  odometer_draw();
}
