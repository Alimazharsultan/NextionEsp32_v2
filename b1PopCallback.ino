//Button b1 component popcallback function
// When OFF button is released the LED turns OFF and the state text changes
void b1PopCallback(void *ptr) {
  t0.setText ("Conveyor 1 Status: OFF");
  conveyor1status = "Conveyor 1 Status: OFF";
  digitalWrite(led, LOW);
  digitalWrite(out1, HIGH);
  count++;
  n0.setValue(count);
}
