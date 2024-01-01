#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include "landing.h"

ESP8266WebServer server;
Servo servo;

const uint8_t pin_led = 16;
const uint8_t pin_servo = 5;

const char* ssid = "wifi";
const char* password = "password";

void setup() {
  Serial.begin(115200);

  pinMode(pin_led, OUTPUT);

  servo.attach(pin_servo, 500, 2500); 
  servo.write(0);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", landingPage);
  server.on("/on", on);
  server.on("/off", off);
  server.begin();
}

void loop() {
  server.handleClient();
}

void on() {
  digitalWrite(pin_led, !digitalRead(pin_led));
  servo.write(180);
  delay(2000);
  servo.write(0);
  server.send(204,"");
}

void off() {
  digitalWrite(pin_led, !digitalRead(pin_led));
  servo.write(180);
  delay(2000);
  servo.write(0);
  server.send(204,"");
}

void landingPage() {
  server.send_P(200, "text/html", landing_html);
}
