#include "Servo.h"

Servo servoR, servoL;
Servo servoBat;

int TP = 4, EP = 5; // TP = trig pin, EP = Echo pin Sensor Bat

int ldrIzq = A2, ldrDrch = A3; //pines ldr
int irIzq = 2, irDrch = 3; // pines infrarrojos

//Delays
int defaultDelay = 200, lineasDelay = 0;
int giro_180 = 1028, giro_90 = 514, giro_45 = 257, giro_30 = 200; //Delays para diferentes ángulos

int pinBuz = 12;

String inString = ""; // String para lectura/escritura desde Protocoder

void setup() {


  Serial.begin(19200); //NO MODIFICAR!!!!!!!!!!!
  Serial.flush();

  servoL.attach(6);
  servoR.attach(9);
  servoBat.attach(11);

  servoR.write(90);
  servoL.write(90);
  servoBat.write(90);

  //pines bat
  pinMode(EP, INPUT);
  pinMode(TP, OUTPUT);

  //pines ldr
  pinMode(ldrDrch, INPUT);
  pinMode(ldrIzq, INPUT);

  //pines ir
  pinMode(irDrch, INPUT);
  pinMode(irIzq, INPUT);


}

//Funciones lectura/escritura desde Protocoder
void readFromAndroid() {
  char inChar;
  while (Serial.available() > 0) {
    inChar = (char) Serial.read();
    Serial.flush();
    if (inChar == '=')
      inString = "";
    else if (inChar != '+')
      inString += inChar;
  }
}
void writeData() {
  if (inString == "avanzar") {
    avanzar();
  }
  if (inString == "retroceder") {
    retroceder();
  }
  if (inString == "izquierda") {
    izquierda();
    delay(defaultDelay);
    parar();
    inString = "";
  }
  if (inString == "derecha") {
    derecha();
    delay(defaultDelay);
    parar();
    inString = "";
  }
  if (inString == "parar") {
    parar();
  }
  if (inString == "obstaculos") {
    obstaculos();
  }
  if (inString == "siguelineas") {
    sigueLineas();
  }
  if (inString == "sigueluz") {
    sigueLuz();
  }
  if (inString == "180") {
    giro_180_grados();
    inString = "";
  }
  if (inString == "autodestruccion") {
    destroySelf();
    inString = "";
  }

}
//Funciones de movimiento
void avanzar () {
  Serial.println("Avanzar!");
  servoR.write(180);
  servoL.write(0);
}

void retroceder() {
  servoR.write(0);
  servoL.write(180);
}
void parar() {
  servoR.write(90);
  servoL.write(90);
}
void izquierda() {
  servoR.write(180);
  servoL.write(180);
}
void derecha() {
  servoR.write(0);
  servoL.write(0);
}

void giro_180_grados() {
  servoR.write(180);
  servoL.write(180);
  delay(giro_180);
  parar();
}

void izquierdaLineas() {
  servoR.write(180);
  servoL.write(90);
  delay(lineasDelay);
  parar();
}

void derechaLineas() {
  servoR.write(90);
  servoL.write(0);
  delay(lineasDelay);
  parar();
}

void destroySelf() {

  int nextTime, intervale = 10000;

  nextTime = millis() + intervale;

  do {
    if ( (nextTime - millis() )> 4000) {
      izquierda();
      delay(giro_30/2);
      parar();
      tone(pinBuz, 329, 500);
      delay(1000);
      derecha();
      delay(giro_30/2);
    } else {
      avanzar();
      delay(giro_30/2);
      parar();
      tone(pinBuz, 329, 200);
      retroceder();
      delay(giro_30/2);
      parar();
      delay(400);
      
    }

  } while (millis() < nextTime);

}
//Funciones obstaculos
void obstaculos() {

  int izq = 140, drch = 50, cent = 90;

  // Comprueba si hay obstaculos
  boolean obsIzq = buscaObstaculo(izq); //Devuelve true si hay obstaculo
  if (obsIzq) {
    parar();
  }

  boolean obsCent = buscaObstaculo(cent);
  if (obsCent) {
    parar();
  }

  boolean obsDrch = buscaObstaculo(drch);
  if (obsDrch) {
    parar();
  }

  //Se mueve si no hay obstaculos
  if (!obsCent) {
    avanzar();
  } else if (!obsDrch) {
    derecha();
    delay(giro_45);
    parar();
  } else if (!obsIzq) {
    izquierda();
    delay(giro_45);
    parar();
  } else {
    retroceder();
    delay(giro_30);
    giro_180_grados();
  }
}

boolean buscaObstaculo(int angulo) {

  int distancia_max = 25;
  int distancia;

  servoBat.write(angulo);
  delay(200);

  distancia = Distance();

  if (distancia != 0 && distancia < distancia_max) {
    tone(pinBuz, 261, 100);
    return true;
  } else {
    return false;
  }
}

long TP_init() {

  digitalWrite( TP , LOW);
  delayMicroseconds(2);
  digitalWrite( TP , HIGH);
  delayMicroseconds(10);
  digitalWrite( TP , LOW);
  long microseconds = pulseIn( EP , HIGH);
  return microseconds;
}
long Distance() {
  long microseconds = TP_init();
  int distancia =   microseconds / 29 / 2; // Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
  //                                                     = ((Duration of high level)*(Sonic :0.034 cm/us))/2
  //                                                     = ((Duration of high level)/(Sonic :29.4 cm/us))/2
  return distancia;
}

//Funciones sigueLuz
void sigueLuz() {

  int lecturaIzq = analogRead(ldrIzq);
  int lecturaDrch = analogRead(ldrDrch);

  if (lecturaIzq > lecturaDrch) {
    izquierda();
    delay(250);
    avanzar();
    delay(1000);
  } else {
    derecha();
    delay(250);
    avanzar();
    delay(1000);
  }
}

//Funciones sigueLineas
void sigueLineas() {

  int lecturaIzq = digitalRead(irIzq);
  int lecturaDrch = digitalRead(irDrch);

  if (lecturaIzq == 1 && lecturaDrch == 1) {
    parar();
  } else if (lecturaIzq == 0 && lecturaDrch == 1) {
    izquierdaLineas();
  } else if (lecturaIzq == 1 && lecturaDrch == 0) {
    derechaLineas();
  } else if (lecturaIzq == 0 && lecturaDrch == 0) {
    avanzar();
  }
}
//Funciones sigue luz
void loop() {
  if (Serial.available() > 0) {
    readFromAndroid();
  }
  writeData();
}