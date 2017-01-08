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
  bar_gauge(0, 2, 7, 0, map(fuel, 0, 1023, 0, 7));
  bar_gauge(127, 2, 7, 1, map(coolant, 0, 1023, 0, 7));

  u8g.setPrintPos(45, 0);
  u8g.print(lastFixTime);


  u8g.setPrintPos(20, 20);
  u8g.print("Temp: "); u8g.print(temperature); u8g.print(" *c");
  u8g.setPrintPos(20, 32);
  u8g.print(voltage);
  u8g.print("v");
  odometer_draw();
}
