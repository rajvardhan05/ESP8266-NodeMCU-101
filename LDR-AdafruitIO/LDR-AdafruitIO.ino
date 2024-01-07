#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *******************************/
#define WLAN_SSID       "SSID NAME" //Enter you SSID NAME
#define WLAN_PASS       "PASSWORD" //Enter you PASSWORD

/************************* Adafruit.io Setup *******************************/
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   
#define AIO_USERNAME    "Adafruit-username" //Enter you username
#define AIO_KEY         "Adafruit-api-key" //Enter you api-key

/************************* LDR Pin *******************************/
#define LDR_PIN A0 // Change this to the pin where your LDR is connected

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Setup the feed you're publishing to
Adafruit_MQTT_Publish ldrFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/light"); //Enter you feed

void setup() {
  Serial.begin(115200);
  delay(10);
  
  Serial.println(F("Connecting to WiFi"));
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println(F("WiFi connected"));

  mqtt.connect();
}

void loop() {
  // Read LDR value
  int ldrValue = analogRead(LDR_PIN);

  // Publish LDR value to Adafruit IO
  if (mqtt.connected()) {
    ldrFeed.publish(ldrValue);

    // Print LDR value to Serial Monitor
    Serial.print(F("LDR Value: "));
    Serial.println(ldrValue);
  }

  delay(2000); // Publish data every 5 seconds (adjust as needed)
}
