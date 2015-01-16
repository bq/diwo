#include <Servo.h> 
 
Servo servo;  
  
void setup() 
{ 
  servo.attach(9); 
  servo.write(40);

} 
 
void loop() 
{ 
 
    servo.write(140);
    delay(1500)
    servo.write(40);
    delay(5000);
} 
