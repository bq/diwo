// Define a function that waits for an input on Serial Port
// returns nothing
void waitForInput(){
	//While there is no data on Serial input
	while(Serial.available()==0){
		delay(500); // wait 500 ms and check again
	}
	
	// hey!! something arrived
	
	// while there is data pending
	while(Serial.available()>0){
		Serial.read(); //read and empty Serial 
	}
	
	// when arrived here, Serial is empty and we have received something
	// that is what we wanted!
}


void setup()
{
	// initialize Serial
	Serial.begin(9600); // baudrate 9600
	Serial.println("Starting..."); //Welcome message, only at the beginning
	
}

void loop()
{
	//Let's test the funcion
	Serial.println("Waiting for input..."); //print this string con Serial
	waitForInput(); //this should stop execution until in send something throug Serial
	Serial.println("Something has been received"); //ack something has been received
	delay(500); //wait 500 ms until new execution of loop
}
