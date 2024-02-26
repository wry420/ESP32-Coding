#include <Arduino.h>
#include <Wifi.h>
#define SSID "ssid here"
#define PASS "password here"

// NON BLOCKING WIFI: (you can run other tasks while wifi is connecting)
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(SSID, PASS);
  Serial.println("starting...");

  // ESP.restart();
}

bool isConnected = false;

void loop()
{
  if (WiFi.status() == WL_CONNECTED && !isConnected)
  {
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(500);
    isConnected = false;
  }
}
