
// to be used in the draw cycle
// pass in flip to display on the RHS
// pass in the input as a value from 0 - 1 to show the level
void bar_gauge(int offsetX, int offsetY, int barCount, int flip, float inputVal){
  int i = 0;
  int barHeight = 6;
  int barBottomMargin = 3;
  int barWidth = 12;
  int barRadius = 2;

  float threshold[] = {0.84, 0.7, 0.56, 0.42, 0.28, 0.14};
  do{
    if(inputVal < threshold[i]){
      u8g.drawRFrame(offsetX, offsetY + i * (barHeight + barBottomMargin), barWidth, barHeight, barRadius);
    }
    else {
      u8g.drawRBox(offsetX, offsetY + i * (barHeight + barBottomMargin), barWidth, barHeight, barRadius);
    }
    i++;

  } while (i < barCount);

}
