
/*
Funktionen Anheben und Absenken f�r Schrittmotoren 3 und 4.
Sie wurden ausgelagert um die �bersichtlichkeit zu gew�hrleisten.
Version 1.0
Stand: November 2016
Dieser Coder wurde im Rahmen einer Bachelorarbeit an der Hochschule M�nchen erstellt.
Verfasser: Kevin Wayne Wallace
*/

unsigned short b = 1000;        //Anzahl der Schritte welcher der Schrittmotor fahren soll

void ANHEBEN_2()            //Funktion um die R�der anzuuheben
{
  digitalWrite(dirnPin3, LOW);    //Drehung im Uhrzeigersinn(Spannung  5V)
  digitalWrite(dirnPin4, LOW);

  while (x < b)           //Schritte von 0 bis b
  {
    digitalWrite(stepPin3, HIGH); //Schrittmotor 3
    delayMicroseconds(40);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin4, HIGH); //Schrittmotor 4
    delayMicroseconds(40);
    digitalWrite(stepPin4, LOW);
    delayMicroseconds(40);

    x++;              //Erh�hung von x 
  }
  x = 0;                //Zur�cksetzung von x auf Null
}


void ABSENKEN2()            //Funktion um die R�der abzzusenken
{
  digitalWrite(dirnPin3, HIGH);   
  digitalWrite(dirnPin4, HIGH);

  while (x < b)           
  {
    digitalWrite(stepPin3, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin3, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin4, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin4, LOW);
    delayMicroseconds(40);

    x++;               
  }
  x = 0;                
}
