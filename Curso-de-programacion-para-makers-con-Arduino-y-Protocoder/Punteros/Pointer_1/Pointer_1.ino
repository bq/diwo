void setup() {
  Serial.begin(9600);
}

void loop() {
  int a = 100;
  int * puntero_a = &a;
  
  Serial.print("Valor contenido en a: ");
  Serial.println(a, BIN);
  Serial.println(a);
  Serial.print("Direccion de memoria de la variable a: ");
   Serial.println((unsigned int)(&a),BIN);
  Serial.println((unsigned int)(&a));
  Serial.print("El valor contenido en la direccion de memoria apuntada por el puntero_a: ");
  Serial.println(*puntero_a,BIN);
  Serial.println(*puntero_a);
  Serial.print("La direccion contenida en el puntero: ");
  Serial.println((unsigned int)(puntero_a),BIN);
  Serial.println((unsigned int)(puntero_a));
  Serial.print("La direccion del puntero: ");
  Serial.println((unsigned int)(&puntero_a),BIN);
  Serial.println((unsigned int)(&puntero_a));
  Serial.println();

  delay(3000);
}
