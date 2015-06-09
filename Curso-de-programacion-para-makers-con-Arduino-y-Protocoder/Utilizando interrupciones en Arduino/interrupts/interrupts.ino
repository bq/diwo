int interrupcion = 0;
// Interrupt 0 se encuentra en el pin digital 2
// Interrupt 1 se encuentra en el pin digital 3

/*  Creamos la variable con el calificador volatile
	para asegurar que la variable será accesible desde el
	flujo normal del programa y desde la interrupcion.
*/

volatile int numInterrupt = 0;

void setup() {

	Serial.begin(9600);

	// Sintaxis interrupciones:
	// attachInterrupt(numero_interrupt,función_a_ejecutar,modo);
	// Modos LOW,CHANGE,RISING,FALLING

	attachInterrupt(interrupcion, funcionInterrupcion, FALLING);
}

void loop() {

	/*Simulamos una tarea que requiera tiempo.
	Utilizamos While(true) ya que siempre se cumplirá la
	condición y nunca dejará de ejecutar el código incluido.
	*/
	while (true) {
		Serial.print(".");
	}
}

void funcionInterrupcion() {
	Serial.print("Interrupt numero ");
	Serial.println(numInterrupt);
	numInterrupt++; // Aumentamos el número almacenado en numInterrupt en una unidad.
}
