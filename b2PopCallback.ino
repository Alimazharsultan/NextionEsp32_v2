
void b2PopCallback(void *ptr) {
  t1.setText ("Conveyor 2 Status: On");
  conveyor2status = "Conveyor 2 Status: On";
  digitalWrite(out2, LOW);
  String systemstatus = ("System Status = On");
}
