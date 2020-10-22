void updateWebDisplay(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /conveyor1on") >= 0) {
              conveyor1status = "Conveyor 1 Status: ON";
              t0.setText ("Conveyor 1 Status: On");
              digitalWrite(out1, LOW);
            } else if (header.indexOf("GET /conveyor1off") >= 0) {
              conveyor1status = "Conveyor 1 Status: OFF";
              t0.setText ("Conveyor 1 Status: oFF");
              digitalWrite(out1, HIGH);
              count++;
            }
            if (header.indexOf("GET /conveyor2on") >= 0) {
              conveyor2status = "Conveyor 2 Status: ON";
              t1.setText ("Conveyor 2 Status: On");
              digitalWrite(out2, LOW);
            } else if (header.indexOf("GET /conveyor2off") >= 0) {
              t1.setText ("Conveyor 2 Status: Off");
              conveyor2status = "Conveyor 2 Status: Off";
              digitalWrite(out2, HIGH);
            }

            if (header.indexOf("GET /shotdown") >= 0) {
              p0.show();
              digitalWrite(out1, LOW);
              digitalWrite(out2, HIGH);
              conveyor1status = "Conveyor 1 Status: Off";
              conveyor1status = "Conveyor 2 Status: Off";
              fillingstatus = "Filling Status = 0";
              cappingstatus = "Capping Status=0";
              count = 0;
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>Automatic Bottle filling System</h1>");
            client.println("<p><a href=\"/conveyor1on\"><button class=\"button\">Conveyor 1 On</button></a></p>");
            client.println("<p><a href=\"/conveyor1off\"><button class=\"button button2\">Conveyor 1 OFF</button></a></p>");
            client.println("<p><a href=\"/conveyor2on\"><button class=\"button\">Conveyor 2 On</button></a></p>");
            client.println("<p><a href=\"/conveyor2off\"><button class=\"button button2\">Conveyor 2 OFF</button></a></p>");
            client.println("<p><a href=\"/shutdown\"><button class=\"button\">Shutdown</button></a></p>");
            client.println("<p>" + systemstatus + "</p>");

            client.println("<p>" + conveyor1status + "</p>");
            client.println("<p>" + conveyor2status + "</p>");
            client.println("<p>" + fillingstatus + "</p>");
            client.println("<p>" + cappingstatus + "</p>");
            if (count == 0) {
              client.println("<p> Bottle status: 0</p>");
            }
            if (count == 1) {
              client.println("<p> Bottle status: 1</p>");
            } if (count == 2) {
              client.println("<p> Bottle status: 2</p>");
            } if (count == 3) {
              client.println("<p> Bottle status: 3</p>");
            } if (count == 4) {
              client.println("<p> Bottle status: 4</p>");
            } if (count == 5) {
              client.println("<p> Bottle status: 5</p>");
            }
            if (count == 1) {
              client.println("<p> Bottle status: 1</p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    //    client.stop();
    //  Serial.println("Client disconnected.");
    //Serial.println("");
  }  
  }
