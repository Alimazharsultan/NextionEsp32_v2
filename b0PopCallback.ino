//Button b0 component popcallback function
// When ON button is Released the LED turns ON and the state text changes


void b0PopCallback(void *ptr) {
  t0.setText ("Conveyor 1 Status: On");
  conveyor1status = "Conveyor 1 Status: ON";
  systemstatus = "System Status = On";
  Serial.println("Button");
  digitalWrite(led, HIGH);
  digitalWrite(out1, LOW);
}
