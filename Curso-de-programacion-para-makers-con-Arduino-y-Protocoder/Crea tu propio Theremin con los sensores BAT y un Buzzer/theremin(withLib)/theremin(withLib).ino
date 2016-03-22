#include "BitbloqUS.h"

int TP1 = 9, EP1 = 8; // Trigger Pin 1, Echo Pin 1
int TP2 = 11, EP2 = 10; // Trigger Pin 2, Echo Pin 2
 
int pinBuzzer = 5;

US bat1, bat2;

void setup() {
 
	bat1.init(TP1,EP1);
	bat2.init(TP2,EP2);
	 
	pinMode(pinBuzzer, OUTPUT);
}

void loop() {
 
	int frec_maxima = 4000; //frecuencia maxima
	 
	int distancia_frecuencia = bat1.read();
	int distancia_tiempo = bat2.read();
	 
	distancia_frecuencia = constrain(distancia_frecuencia, 1, 20);
	distancia_tiempo = constrain(distancia_tiempo, 1, 10); // 1 equivale a 10 ms y 10 a 100ms
	 
	distancia_frecuencia = map(distancia_frecuencia, 1, 20, 1, frec_maxima);
	distancia_tiempo = map(distancia_tiempo, 1, 10, 10, 100); // de (1,10) cm a (10,100)ms
	 
	tone(pinBuzzer, distancia_frecuencia, distancia_tiempo);
	delay(distancia_tiempo);
}

