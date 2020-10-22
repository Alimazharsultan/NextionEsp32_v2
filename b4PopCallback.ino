void b4PopCallback(void *ptr) {
  Serial.println("Shutdown");
  p0.show();
  digitalWrite(out1, HIGH);
  digitalWrite(out2, HIGH);
  systemstatus = "System Status = Off";
  fillingstatus = "Filling Status: OFF";
  cappingstatus = "Capping Status: OFF";
  conveyor1status = "Conveyor 1  Status: OFF";
  conveyor2status = "Conveyor 2 Status: OFF";
}
