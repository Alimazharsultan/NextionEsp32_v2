#include <Nextion.h>
#define out1 5
#define out2 18
#define sense 25
#define sense2 33
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "Ali, Zaki";
const char* password = "verygood";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;
String conveyor1status;
String conveyor2status;
String fillingstatus;
String cappingstatus;
String systemstatus;
String s;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
const int led = 2;
int count = 0;
uint32_t next = 0;
void setup(void) {
  nexInit();
  Serial.begin(115200);
  //Register the pop event callback function of the components
  b0.attachPop(b0PopCallback, &b0);
  b1.attachPop(b1PopCallback, &b1);
  b2.attachPop(b2PopCallback, &b2);
  b3.attachPop(b3PopCallback, &b3);
  b4.attachPop(b4PopCallback, &b4);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(out1, OUTPUT);
  digitalWrite(out1, HIGH);
  pinMode(out2, OUTPUT);
  digitalWrite(out2, HIGH);
  pinMode(sense, INPUT);
  pinMode(sense2, INPUT);
  next = millis();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  nexLoop(nex_listen_list);
  if (millis() >= next) {
    next = millis() + 500;
    updateNextionDisplay();
    updateWebDisplay();
  }
}
