#include <Servo.h>
Servo trigger;
int power = 8;
char bluetooth;
long currenttime;
long previoustime;
int tofeed = 1;
long intervals;
String a;
String b;
int buzzer=10;

void setup() {
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);
  pinMode(buzzer,OUTPUT);
  trigger.attach(9);
  Serial.begin(9600);
  trigger.write(180);
}

void loop() {
  currenttime = millis();
  if (Serial.available() > 0) {
    bluetooth = Serial.read();
    Serial.println(bluetooth);
    if (bluetooth == 'F') {
      feed();
    }
    if (bluetooth == '1') {
      tofeed = 1;
    }
    if (bluetooth == '2') {
      tofeed = 2;
    }
    if (bluetooth == '3') {
      tofeed = 3;
    }
    if (bluetooth == '4') {
      tofeed = 4;
    }
    if (bluetooth == '5') {
      tofeed = 5;
    }
    if (bluetooth == '6') {
      tofeed = 6;
    }
    if (bluetooth == '7') {
      tofeed = 7;
    }
    if (bluetooth == '8') {
      tofeed = 8;
    }
    if (bluetooth == '9') {
      tofeed = 9;
    }
  }
  periodicfeed();
}

void feed() {
  trigger.write(150);
  delay(1000);
  trigger.write(180);
  delay(1000);
  trigger.write(150);
  delay(1000);
  trigger.write(180);
  delay(1000);
  trigger.write(150);
  delay(1000);
  trigger.write(180);
  delay(1000);
  trigger.write(150);
  delay(1000);
  trigger.write(180);
  delay(1000);
  trigger.write(150);
  delay(1000);
  trigger.write(180);
  digitalWrite(buzzer,HIGH);
  delay(20000);
  digitalWrite(buzzer,LOW);
}
void periodicfeed() {
  intervals = 86400000 / tofeed;
  if (currenttime-previoustime>=intervals) {
    previoustime=currenttime;
    feed();
  }
}
