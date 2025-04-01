#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"

const char* softAPSSID = "ESP32_Provisioning";
AsyncWebServer server(80);
String wifiSSID, wifiPassword;

void connectToWiFi() {
  WiFi.softAPdisconnect();
  WiFi.begin(wifiSSID.c_str(), wifiPassword.c_str());
  Serial.print("Connecting");
  
  for (int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
    delay(1000);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi Connected! IP: " + WiFi.localIP().toString());
    server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(200, "text/html", "<h1>Connected to " + wifiSSID + "</h1>");
    });
  } else {
    Serial.println("\nConnection Failed! Restarting SoftAP...");
    WiFi.softAP(softAPSSID);
    server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(200, "text/html", "<h1>Connection Failed</h1>");
    });
  }
}

void setupServer() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    LittleFS.exists("/index.html") ? request->send(LittleFS, "/index.html", "text/html")
                                   : request->send(404, "text/plain", "File Not Found");
  });

  server.on("/connect", HTTP_POST, [](AsyncWebServerRequest *request) {
    wifiSSID = request->arg("ssid"), wifiPassword = request->arg("password");
    Serial.println("SSID: " + wifiSSID + " | Password: " + wifiPassword);
    connectToWiFi();
  });

  server.begin();
}

void setup() {
  Serial.begin(115200);
  if (!LittleFS.begin()) return;
  WiFi.softAP(softAPSSID);
  Serial.println("SoftAP IP: " + WiFi.softAPIP().toString());
  setupServer();
}

void loop() {}
