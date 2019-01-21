#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const String link_download = "http://YOUR_IP_OR_DOMAIN:3901/download/test.bin";

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  
  WiFi.forceSleepWake();
  delay(1);
  WiFi.persistent(false);
  WiFi.mode( WIFI_STA );
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(100);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address");
  Serial.println(WiFi.localIP());

}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    t_httpUpdate_return ret = ESPhttpUpdate.update(link_download);

    switch (ret) {
      case HTTP_UPDATE_FAILED:
        Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
        break;

      case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

      case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OK");
        break;
    }
  }
}

