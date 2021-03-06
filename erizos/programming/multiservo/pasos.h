#ifndef pasos_h
#define pasos_h

#include <Arduino.h>
#include <Servo.h>

#define DOF 32                                                                                                                                                                  
#define INTERVALTIME 10.0 

Servo servo[DOF];
int oldPosition[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

          //  1   2   3  4   5   6  7   8 9  10 11  12  13  14  15  16  17  18  19  20 21 22 23  24 25 26 27 28 29 30 31 32
int trim[]={-16,-12,-10,-10,-14,-7,+2,-22,0,-19,-3,-20,-20,-21,-24,-22,-16,-10,-16,+15,-5,-1,0, -3,-10,10,-2,0,-8,-20,-7,0,};

//BUEN TEMPO
int tempo=160;
unsigned long final_time;
unsigned long interval_time;
int oneTime;
int iteration;
float increment[DOF];  


//FROM MYOD PROJECT
void moveNServos(int time, int  newPosition[]){
  
  for(int i=0;i<DOF;i++)	increment[i] = ((newPosition[i]+trim[i])-oldPosition[i])/(time/INTERVALTIME);
  
  final_time =  millis() + time; 
  
  iteration = 1; 
  while(millis() < final_time){ //Javi del futuro cambia esto  
      interval_time = millis()+INTERVALTIME;  
      
      oneTime=0;      
      while(millis()<interval_time){	  
          if(oneTime<1){ 
              for(int i=0;i<DOF;i++){
                  servo[i].write(oldPosition[i] + (iteration * increment[i]));
              }			
              iteration++;
              oneTime++;
          }
      }     
  }   

  for(int i=0;i<DOF;i++){	
    oldPosition[i] = newPosition[i]+trim[i];
  }   
}

//85 pasa a ser 120 y 60 a 60


void ola_1(){
  moveNServos(tempo, (int[]){  120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

                               
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});
                               
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});
                                                                
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60});
                               
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120,
                               60, 60, 60, 60});                               
                                    
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 120, 120, 120});                              
}

void bq_spam(){
  moveNServos(tempo*8, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 60, 60, 60,
                                 120, 60, 60, 120,
                                 120, 60, 60, 120,
                                 60, 60, 60, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});
                            
}


void agua(){
  moveNServos(tempo*2, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 60, 60, 120,
                                 120, 60, 60, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});

  moveNServos(tempo*2, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 60, 60, 120,
                                 60, 120, 120, 60,
                                 60, 120, 120, 60,
                                 120, 60, 60, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});

  moveNServos(tempo*2, (int[]){  120, 120, 120, 120,
                                 120, 60, 60, 120,
                                 60, 120, 120, 60,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 60, 120, 120, 60,
                                 120, 60, 60, 120,
                                 120, 120, 120, 120});

  moveNServos(tempo*2, (int[]){  120, 60, 60, 120,
                                 60, 120, 120, 60,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 60, 120, 120, 60,
                                 120, 60, 60, 120});

}



void ola_4(){
  moveNServos(tempo*4, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 60, 120, 120, 120,
                                 60, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});
                                 
  moveNServos(tempo*4, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 60, 120, 120, 120,
                                 60, 60, 120, 120,
                                 60, 60, 120, 120,
                                 60, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});
                                 
  moveNServos(tempo*4, (int[]){  120, 120, 120, 120,
                                 60, 120, 120, 120,
                                 60, 60, 120, 120,
                                 60, 60, 60, 120,
                                 60, 60, 60, 120,
                                 60, 60, 120, 120,
                                 60, 120, 120, 120,
                                 120, 120, 120, 120});
                                 
  moveNServos(tempo*4, (int[]){  60, 120, 120, 120,
                                 60, 60, 120, 120,
                                 60, 60, 60, 120,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 120,
                                 60, 60, 120, 120,
                                 60, 120, 120, 120});
                                 
  moveNServos(tempo*4, (int[]){  60, 60, 120, 120,
                                 60, 60, 60, 120,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 120,
                                 60, 60, 120, 120});
                                 
  moveNServos(tempo*4, (int[]){  60, 60, 60, 120,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 120});
                                 
  moveNServos(tempo*4, (int[]){  60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60,
                                 60, 60, 60, 60});
                                 
  moveNServos(tempo*4, (int[]){  120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120,
                                 120, 120, 120, 120});
                                 
}


void snake(int t){
  tempo=t;
  moveNServos(tempo, (int[]){  120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120});
                               
   moveNServos(tempo, (int[]){ 60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60});

   moveNServos(tempo, (int[]){ 60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120,
                               60, 60, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 120, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 120});                           
                             
   moveNServos(tempo, (int[]){ 60, 120, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 120, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 60, 60});                           
                             
   moveNServos(tempo, (int[]){ 60, 60, 60, 120,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               120, 60, 60, 60});  
      tempo=160;                         
                             
}


void tutupa(int t){
   tempo=t;
   double dilei;
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});      
                         
   dilei=millis();
   while(millis()<dilei+3*tempo);

   moveNServos(tempo, (int[]){ 120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120});      
                         
   dilei=millis();
   while(millis()<dilei+2*tempo);
   
   moveNServos(tempo, (int[]){ 120, 120, 120, 120,
                               60, 120, 120, 60,
                               60, 120, 120, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 120, 120, 60,
                               60, 120, 120, 60,
                               120, 120, 120, 120});;  
                               
   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               120, 60, 60, 120,
                               120, 60, 60, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 60, 60, 120,
                               120, 60, 60, 120,
                               60, 60, 60, 60});
                                
                               
   dilei=millis();
   while(millis()<dilei+3*tempo);

   moveNServos(tempo, (int[]){ 60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60,
                               60, 60, 60, 60});
                               
   moveNServos(tempo*3, (int[]){ 120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120,
                               120, 120, 120, 120});
tempo=t;

}

#endif
