//HC-SR04 test
#include <ESP8266WiFi.h>

#define trigPin 6
#define echoPin 7

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  ESP.wdtDisable();
  ESP.wdtEnable(WDTO_8S);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.print("\n");
  delay(100);
  ESP.wdtFeed();
}
