#include <HTS221.h>
#include <HTS221_Registers.h>

#include "Wire.h"

HTS221 hts221;
/*
Vcc to 5V
GND to GND
SCL to A5
SDA to A4
*/


float h = 0.0, t = 0.0;

bool debug = false;
int sampleTime = 1000;

//Relay Variables
int relay1Pin = 2;
unsigned long nextTime; //NEW

void setup() {

  Serial.begin(19200);

  pinMode(relay1Pin, OUTPUT);

  Wire.begin();
  hts221.begin();
  if (hts221.checkConnection()) {
    Serial.println("Error checking HTS221 connection");
  } else {
    Serial.println("HTS221 connected");
  }
}

void loop() {
  checkIncomming();
  getTH();
  checkAuto();
}

void getTH() {
  float aux;

  h = hts221.getHumidity();
  t = hts221.getTemperature();

  if (debug) {
    Serial.println(h);
    Serial.println(t);
  }

  h = int(h * 100);
  t = int(t * 100);

  aux = h * 10000 + t;
  Serial.println(aux);

  delay(sampleTime);
}
/* NEW */
boolean isOn = false;
void checkAuto() {
  if (millis() > nextTime && !isOn) {
    digitalWrite(relay1Pin, LOW);
  }
}
/* /NEW*/
void checkIncomming() {
  int data, flag;
  if (Serial.available() > 0) {
    flag = Serial.parseInt();
    data = Serial.parseInt();

    if (Serial.read() == '\n') {
      switch (flag) {
      case 1: //1 for changing sample time
        sampleTime = data;
        break;
      /*NEW*/
      case 2: // 2 for change the state of the relay1
        if (data == 0) {
          isOn = false;
          digitalWrite(relay1Pin, LOW);
        } else if (data == 1) {
          isOn = true;
          digitalWrite(relay1Pin, HIGH);
        }
        break;
      case 3:
        nextTime = data * 60000 + millis() ;
        digitalWrite(relay1Pin, HIGH);
        break;
      }
      /* /NEW*/
    }
  }
}