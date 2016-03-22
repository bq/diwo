#include "BitbloqLiquidCrystal.h"

LiquidCrystal lcd(0); 
void setup (){
  lcd.begin(16, 2); 
  lcd.clear(); 
  Serial.begin(9600);
}

void loop() {
  int a = 100;
  int * p_a = &a;

  lcdShow(String("Valor de a: ") , String(a));
  lcdShow(String("Direccion de a: "), String((unsigned int)(&a)));
  lcdShow(String("Valor apunta p_a: "), String(*p_a));
  lcdShow(String("Dir guardada p_a: "), String((unsigned int)(p_a)));
  lcdShow(String("Direccion p_a: "), String((unsigned int)(&p_a)));
}

void lcdShow (String message, String value)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(message);
  lcd.setCursor(0,1);
  lcd.print(value);
  delay(2000);  

}

