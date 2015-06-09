//Incluimos la libreria Servo
#include <Servo.h>

//Creamos un objeto servo, podemos crear los que queramos,
//solo tenemos que cambiar el nombre.
Servo miServo;

int pinPot = A0;  //Pin analógico al que está conectado el potenciómetro
int aktValue, nextValue;   // Variable en la que almacenamos los valores del potenciómetro

void setup() {

	//Iniciamos la librería Serial para comunicarnos con la placa
	Serial.begin(9600);
	pinMode(pinPot, INPUT);
	miServo.attach(9);  //Indica en que pin está conectado el servo
	Serial.println("¡Listo!");
}

void loop() {

	nextValue = analogRead(pinPot);            // Leemos el valor del potenciómetro (entre 0-1023)
	nextValue = map(nextValue, 0, 1023, 0, 180);     // Escalamos al rango de valores del servo (0-180)

	//imprimimos el valor en grados de la posición del servo
	Serial.print("Angulo = ");
	Serial.print(nextValue);
	Serial.println("º");

	/*
	Distinguimos dos casos:
		En el primer caso la siguiente posición es mayor que la posición actual,
		por lo que aumentamos el valor

		En el segundo caso la siguiente posición es menor que la posición actual,
		por lo que disminuimos el valor
	*/
	if (nextValue > aktValue) {
		for (int i = aktValue; i <= nextValue; i++) {
			miServo.write(i); //utilizamos la función especifica de la librería servo para escribir el valor
			delay(10); // y esperamos a que el valor llegue.
		}
	} else if (nextValue < aktValue) {
		for (int i = aktValue; i >= nextValue; i--) {
			miServo.write(i);
			delay(10);
		}
	}

	aktValue = miServo.read();
	delay(1000);
}
