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
float aux;

bool debug = false;
int sampleTime = 1000;

void setup() {
  Serial.begin(19200); 
 
  Wire.begin();
  hts221.begin();
  if(hts221.checkConnection()){
  	 Serial.println("Error checking HTS221 connection");
  }else{
  	 Serial.println("HTS221 connected");
  }

}

void loop(){

  h = hts221.getHumidity();
  t = hts221.getTemperature();

  if (debug){
    Serial.println(h);
    Serial.println(t);
  }

  h = int(h*100);
  t = int(t*100);

  aux = h *10000 + t;
  Serial.println(aux);

  delay(sampleTime);
}