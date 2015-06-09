int pinButton = 5, led = 3; //Declaración de las variables

void setup() {

  Serial.begin(9600); // Iniciamos la comunicación serie a 9600 bauds
  pinMode(pinButton, INPUT); // Establecemos el pin que tiene conectado el botón como entrada
  pinMode(led, OUTPUT); // Establecemos el pin que tiene conectado el LED como salida
}

void loop() {
  boolean firstTime = false; // Inicializamos la variable firstTime de tipo Boolean con el valor false

  do { // Inicio del bucle do while

    if (firstTime == false) { // Si la variable firstTime es falsa, entonces entrará aquí
      firstTime = true;
    } else { // Si la variable firstTime es verdadera, entonces entrará aquí.
      firstTime = false;
    }

    // Serial.println("Inside of do-while"); // Indica por medio de un mensaje que se esta ejecutando el bucle do while

    if (firstTime) { // if lee el valor almacenado en la variable firstTime. Si es true (verdadero) o 1 entonces entra aquí
      blinky(1, 1000); // Llamada a la función blinky con los parámetros times = 1 y delay_led = 1000
    } else { // if lee el valor almacenado en la variable. Si es false (falso) o 0 entonces entra aquí
      blinky(20, 50); //Llamada a la función blinky con los parámetros times = 20 y delay_led = 50
    }

  } while (digitalRead(pinButton)); // Lectura de la condición de repetición del bucle do while. Si el botón esta pulsado, volverá
                                    // a repetir el código dentro del do while.

  //Serial.println("Outside of do-while"); // Indica por medio de un mensaje que ya se ha ejecutado el bucle do while.
}

/*
Declaración de la función de tipo void (no devuelve resultado) de nombre blinky.
Tiene dos parámetros:
  times (variable de tipo entero) que determina el número de veces que se producirá el parpadeo.
  delay_led (variable de tipo entero) que determina el tiempo que habrá entre los dos estados del led:
       Determina la frecuencia del parpadeo.
Nota: La función enciende el led y lo apaga, por lo que la variable times representa el número
de ciclos de encendido y apagado (times = n encenderá y apagará el led n veces)
*/

void blinky(int times, int delay_led) { 

  for (int i = 0; i &lt; times; i++) { //Bucle for y declaración de la variable i. El bucle se ejecuta desde i hasta times - 1
    Serial.print("iteration "); // Imprime junto a la siguiente línea información sobre el número de veces que se ejecuta for.
    Serial.println(i); // imprime el número de veces que se ejecuta el bucle for  
    digitalWrite(led, HIGH); // Activa el pin al que esté conectado el LED
    delay(delay_led); // Espera el tiempo que se ha indicado al llamar a la función con el parámetro delay_led
    digitalWrite(led, LOW); // Desactiva el pin al que esté conectado el LED
    delay(delay_led); // Espera el tiempo que se ha indicado al llamar a la función con el parámetro delay_led
  }
}
