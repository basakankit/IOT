#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
#include <WiFiClient.h>

WiFiClient wifiClient;
const char* ssid = "IOT_DEVICES";
const char* password = "iot_lab_devices";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(wifiClient, "http://13.232.181.16/items/light");  // Specify the full URL here

    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.println("HTTP request failed");
    }
    
    http.end();
  } else {
    Serial.println("Not connected to WiFi");
  }

  delay(5000);  // Wait for a while before making the next request
}
