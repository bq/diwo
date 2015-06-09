
int pinSonda = A0;
float escala = 100; //100 para voltios, 0.1 para milivoltios
void setup() {

	Serial.begin(19200);

	pinMode(pinSonda, INPUT);

}

void loop() {

	float lectura = analogRead(pinSonda);

	lectura = map(lectura, 0, 1023, 0, 500);

	float voltaje = lectura / escala;

	Serial.println(voltaje);
	delay(500);
}