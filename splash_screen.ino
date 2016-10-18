


#define Karmann_Ghia_Logo_width 128
#define Karmann_Ghia_Logo_height 58

int splashScreenFrame = 0;


#define kg_logo_top_width 18
#define kg_logo_top_height 11
#define kg_logo_top_x_offset 56
#define kg_logo_top_y_offset 0
const unsigned char kg_logo_top_bits[] PROGMEM = {
   0x00, 0x80, 0x03, 0x00, 0x60, 0x02, 0x00, 0x18, 0x01, 0x00, 0x84, 0x00,
   0x00, 0x41, 0x00, 0x80, 0x10, 0x00, 0x60, 0x08, 0x00, 0x10, 0x02, 0x00,
   0x08, 0x01, 0x00, 0xc6, 0x00, 0x00, 0x21, 0x00, 0x00 };

#define kg_logo_left_width 47
#define kg_logo_left_height 8
#define kg_logo_left_x_offset 2
#define kg_logo_left_y_offset 11

const unsigned char kg_logo_left_bits[] PROGMEM = {
   0x31, 0x00, 0x30, 0x00, 0x80, 0x07, 0x19, 0x00, 0x70, 0x00, 0x80, 0x04,
   0x0d, 0x00, 0x78, 0x00, 0x80, 0x0c, 0x07, 0x00, 0x58, 0x00, 0x80, 0x07,
   0x07, 0x00, 0xc8, 0x00, 0x80, 0x07, 0x0d, 0x00, 0xfc, 0x00, 0x80, 0x0c,
   0xf9, 0xff, 0xff, 0xff, 0xff, 0x7c, 0xf9, 0xff, 0x87, 0xff, 0xff, 0x78 };

#define kg_logo_middle_merged_width 11
#define kg_logo_middle_merged_height 8
#define kg_logo_middle_merged_x_offset 49
#define kg_logo_middle_merged_y_offset 11
const unsigned char kg_logo_middle_merged_bits[] PROGMEM = {
   0x40, 0x04, 0x20, 0x02, 0x90, 0x00, 0x4c, 0x04, 0x16, 0x04, 0x07, 0x06,
   0xff, 0x07, 0xff, 0x03 };

#define kg_logo_middle_unmerged_width 11
#define kg_logo_middle_unmerged_height 8
#define kg_logo_middle_unmerged_x_offset 49
#define kg_logo_middle_unmerged_y_offset 11
const unsigned char kg_logo_middle_unmerged_bits[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x06,
   0xff, 0x07, 0xff, 0x03 };

#define kg_logo_right_width 67
#define kg_logo_right_height 8
#define kg_logo_right_x_offset 60
#define kg_logo_right_y_offset 11
const unsigned char kg_logo_right_bits[] PROGMEM = {
   0x33, 0x00, 0xc0, 0x00, 0x00, 0x13, 0x00, 0x60, 0x06, 0x33, 0x00, 0xc0,
   0x01, 0x00, 0x13, 0x00, 0x60, 0x06, 0x3f, 0x00, 0xc0, 0x01, 0x00, 0x17,
   0x00, 0xe0, 0x06, 0x7f, 0x00, 0x60, 0x01, 0x00, 0x17, 0x00, 0xe0, 0x06,
   0x6d, 0x00, 0x20, 0x03, 0x00, 0x1d, 0x00, 0xa0, 0x07, 0xcc, 0x00, 0xf0,
   0x03, 0x00, 0x1d, 0x00, 0x20, 0x07, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xf9,
   0xff, 0x3f, 0x07, 0x80, 0xff, 0x1f, 0xfe, 0xff, 0xf9, 0xff, 0x3f, 0x06 };

#define kg_logo_bottom_x_offset 30
#define kg_logo_bottom_y_offset 19
#define kg_logo_bottom_width 68
#define kg_logo_bottom_height 39
const unsigned char kg_logo_bottom_bits[] PROGMEM = {
   0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x08, 0x00, 0x00,
   0x00, 0x00, 0x0c, 0x00, 0x60, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x00, 0x30, 0x00, 0x04, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x18, 0x00,
   0x06, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x0c, 0x00, 0x03, 0x0c, 0x1c,
   0x00, 0x30, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x19, 0x00, 0x0c, 0x00,
   0x00, 0x06, 0x80, 0x01, 0x86, 0x0c, 0x00, 0x03, 0x00, 0x00, 0x03, 0x80,
   0x10, 0x63, 0x0c, 0x60, 0x00, 0x00, 0x80, 0x01, 0xc0, 0x18, 0x21, 0x06,
   0x18, 0x00, 0x00, 0x80, 0x00, 0x60, 0x8e, 0x11, 0x03, 0x03, 0x00, 0x00,
   0xc0, 0x00, 0x23, 0xc7, 0x98, 0x73, 0x00, 0x00, 0x00, 0x40, 0x80, 0xb1,
   0xe6, 0x38, 0x06, 0x00, 0x00, 0x00, 0x60, 0xc0, 0x58, 0x63, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x20, 0xe0, 0x3c, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x30, 0x70, 0x1d, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xb8, 0x0c,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x74, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00 };


void drawSplashScreenFrame(int offset_x, int offset_y){
  if(splashScreenFrame >= 10 && splashScreenFrame <= 17) {
    
    // draw KARMANN bitmap (no Ghia) - 8px high
    // rising out of baseline

    int yPos = kg_logo_left_y_offset + 17 - splashScreenFrame + offset_y;
    // karmann script rising from baseline
    u8g.drawXBMP( kg_logo_left_x_offset + offset_x, yPos, kg_logo_left_width, kg_logo_left_height, kg_logo_left_bits);
    u8g.drawXBMP( kg_logo_middle_unmerged_x_offset + offset_x, yPos, kg_logo_middle_unmerged_width, kg_logo_middle_unmerged_height, kg_logo_middle_unmerged_bits);
    u8g.drawXBMP( kg_logo_right_x_offset + offset_x, yPos, kg_logo_right_width, kg_logo_right_height, kg_logo_right_bits);
  }

  
  if(splashScreenFrame <= 16){
    // animated dot -> line -> baseline
    // displayed before logo, becomes baseline for KARMANN animation
    u8g.drawBox( offset_x + 60 - 6 * splashScreenFrame, 18 + offset_y, 12 * splashScreenFrame + 2, 2);

    // add mask below the line so that none of the KARMANN bleeds 
    u8g.setColorIndex(0);
    u8g.drawBox(offset_x,20 + offset_y,128, 8);
    u8g.setColorIndex(1);
  }
  
  if(splashScreenFrame > 17){
    // draw full logo
    
    u8g.drawXBMP( kg_logo_top_x_offset + offset_x, kg_logo_top_y_offset + offset_y, kg_logo_top_width, kg_logo_top_height, kg_logo_top_bits);
    u8g.drawXBMP( kg_logo_left_x_offset + offset_x, kg_logo_left_y_offset + offset_y, kg_logo_left_width, kg_logo_left_height, kg_logo_left_bits);
    u8g.drawXBMP( kg_logo_middle_merged_x_offset + offset_x, kg_logo_middle_merged_y_offset + offset_y, kg_logo_middle_merged_width, kg_logo_middle_merged_height, kg_logo_middle_merged_bits);
    u8g.drawXBMP( kg_logo_right_x_offset + offset_x, kg_logo_right_y_offset + offset_y, kg_logo_right_width, kg_logo_right_height, kg_logo_right_bits);
    u8g.drawXBMP( kg_logo_bottom_x_offset + offset_x, kg_logo_bottom_y_offset + offset_y, kg_logo_bottom_width, kg_logo_bottom_height, kg_logo_bottom_bits);
  }

}

void splashScreenController(void){
  u8g.firstPage();  
  do {
    drawSplashScreenFrame(0,3);
  } while( u8g.nextPage() );
}

void drawSplashScreen(void){

  // build up animation
  do {
    splashScreenController();
    splashScreenFrame ++;
  } while( splashScreenFrame < 60);

  // pause on full logo
  delay(500);

  // tear down animation
  do {
    splashScreenController();
    splashScreenFrame ++;
  } while( splashScreenFrame < 100);

}
