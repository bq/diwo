#include <Servo.h>

Servo servo;

void setup(){
   servo.attach(9);
   servo.write(60);
}


void loop(){
     for (int i=30;i<110;i+=10){
       servo.write(i);
       delay(random(10,80));
     }
     for (int i=110;i>30;i-=10){
       servo.write(i);
       delay(random(10,80));
     }
}
