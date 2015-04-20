//-----------------------------------------------
//--  (C) Alvaro Ferran.  March-2015
//--  (C) Juan Gonzalez (Obijuan)
//-----------------------------------------------
//-- BQ  Human rights to Technology
//--     Tienes derecho a la tecnologia
//-----------------------------------------------
//-- GPL License
//-----------------------------------------------
//-- Example of moving an object in FreeCAD using
//-- an external potentiometer connected to A0
//-- When the program running in the PC sends a
//-- character (any), the current potentiometer value
//-- is returned (in the range 0 - 1023)
//-----------------------------------------------

void setup() 
{
  //-- Configure the serial port  
  Serial.begin(19200);
}
 
void loop()
{
  //-- Wait for a caracter to be received
  if (Serial.available()) {
    Serial.read();
    
    //-- Send the potentiometer value
    Serial.println( analogRead(0));
  }
}


