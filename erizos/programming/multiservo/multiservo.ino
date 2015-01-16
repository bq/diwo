#include <Servo.h>
#include "pasos.h"

void musica(){
  Serial.begin(9600);
  Serial.flush(); 
  Serial.print("play");
  Serial.print("\n");
  Serial.end();
}

void servos(){

   for(int x=0;x<4;x++)tutupa(160);
   for(int x=0;x<2;x++)snake(160);
   for(int x=0;x<4;x++)agua();
   ola_4();
   for(int x=0;x<4;x++)snake(80);
   for(int x=0;x<6;x++)tutupa(80);
   for(int x=0;x<2;x++)snake(20);
   bq_spam();




}

void setup(){
    pinMode(2,INPUT_PULLUP);
    for (int i=0; i<DOF; i++) servo[i].attach(22+i);
    for (int i=0; i<DOF; i++) servo[i].write(60);
}


void loop(){
    if (digitalRead(2)==LOW){
      musica();
      double dilei=millis();
      while(millis()<dilei+tempo*8);
      servos();
    } 
}
