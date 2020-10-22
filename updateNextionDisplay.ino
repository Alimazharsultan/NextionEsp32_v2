void updateNextionDisplay(){
  Serial.println("Sensor value check");
  int sensorvalue = digitalRead(sense);
  Serial.println(sensorvalue);
  if (sensorvalue == 0) {
    Serial.println("filling on");
    t3.setText ("Filling Status: ON");
    fillingstatus = "Filling Status: ON";
  } else {
    t3.setText ("Filling Status: OFF");
    fillingstatus = "Filling Status: OFF";
  }
  int sensorvalue2 = digitalRead(sense2);
  Serial.println(sensorvalue2);
  if (sensorvalue2 == 0) {
    Serial.println("filling on");
    t4.setText ("Capping Status: ON");
    cappingstatus = "Capping Status: ON";
  } else {
    t4.setText ("Capping Status: OFF");
    cappingstatus = "Capping Status: OFF";
  }
  }
