
// to be used in the draw cycle
// pass in flip to display on the RHS
// pass in the input as a value from 0 - 1 to show the level
void bar_gauge(int offsetX, int offsetY, int barCount, int flip, float inputVal){
  int i = 0;
  int barHeight = 6;
  int barBottomMargin = 3;
  int barWidth[] = {14, 12, 10, 9, 8, 8, 7 };
  int barRadius = 2;
  int barOffsetX = offsetX;
  float threshold[] = {0.84, 0.7, 0.56, 0.42, 0.28, 0.14};
  do{
    if(flip){
      barOffsetX = offsetX - barWidth[i];
    }
    if(inputVal < threshold[i]){
      u8g.drawRFrame(barOffsetX, offsetY + i * (barHeight + barBottomMargin), barWidth[i], barHeight, barRadius);
    }
    else {
      // drawRbox doesn't seem to work correctly, so we'll use a square box :(
      u8g.drawBox(barOffsetX, offsetY + i * (barHeight + barBottomMargin), barWidth[i], barHeight);
    }
    i++;

  } while (i < barCount);

}
