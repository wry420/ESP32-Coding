#include <Arduino.h>
#include <WifiMulti.h>
#define SSID "ssid"
#define PASS "password"

// BLOCKING CONNECTION: (it won't execute any other operations until it connects)
WiFiMulti wifi;
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    Serial.println("Hello from setup");
    wifi.addAP(SSID, PASS);
    while (wifi.run() != WL_CONNECTED)
    {
        delay(100);
    }
    Serial.println("CONNECTED");

    // ESP.restart();
}

void loop()
{
    digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
}
