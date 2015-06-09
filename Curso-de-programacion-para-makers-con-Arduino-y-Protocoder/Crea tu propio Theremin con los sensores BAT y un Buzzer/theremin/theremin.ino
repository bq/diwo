int TP1 = 9, EP1 = 8; // Trigger Pin 1, Echo Pin 1
int TP2 = 11, EP2 = 10; // Trigger Pin 2, Echo Pin 2

int pinBuzzer = 5;

void setup() {

	// pines bat 1
	pinMode(EP1, INPUT;)
	pinMode(TP1, OUTPUT);

	// pines bat 2
	pinMode(EP2, INPUT);
	pinMode(TP2, OUTPUT);

	pinMode(pinBuzzer, OUTPUT);
}

void loop() {


	int frec_maxima = 4000; //frecuencia maxima

	int distancia_frecuencia = distance(TP1, EP1);
	int distancia_tiempo = distance(TP2, EP2);

	distancia_frecuencia = constrain(distancia_frecuencia, 1, 20);
	distancia_tiempo = constrain(distancia_tiempo, 1, 10); // 1 equivale a 10 ms y 10 a 100ms

	distancia_frecuencia = map(distancia_frecuencia, 1, 20, 0, frec_maxima);
	distancia_tiempo = map(distancia_tiempo, 1, 10, 10, 100); // de (1,10) cm a (10,100) ms

	tone(pinBuzzer, distancia_frecuencia, distancia_tiempo);
	delay(distancia_tiempo);
}

long TP_init(int TP, int EP) {

	digitalWrite( TP , LOW);
	delayMicroseconds(2);
	digitalWrite( TP , HIGH);
	delayMicroseconds(10);
	digitalWrite( TP , LOW);
	long microseconds = pulseIn( EP , HIGH);
	return microseconds;
}

long distance(int TP, int EP) {

	long microseconds = TP_init(TP, EP);
	int distancia = 	microseconds / 29 / 2; // Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
	//                                                     = ((Duration of high level)*(Sonic :0.034 cm/us))/2
	//                                                     = ((Duration of high level)/(Sonic :29.4 cm/us))/2
	return distancia;
}
