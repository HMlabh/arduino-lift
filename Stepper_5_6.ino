/*
Funktionen Anheben und Absenken f�r Schrittmotoren 5 und 6.
Sie wurden ausgelagert um die �bersichtlichkeit zu gew�hrleisten.
Version 1.0
Stand: November 2016
Dieser Coder wurde im Rahmen einer Bachelorarbeit an der Hochschule M�nchen erstellt.
Verfasser: Kevin Wayne Wallace
*/

unsigned short c = 1000;        //Anzahl der Schritte welche die Schrittmotoren fahren sollen

void ANHEBEN_3()            //Funktion um die R�der anzuuheben
{
  digitalWrite(dirnPin5, LOW);    //Drehung im Uhrzeigersinn(Spannung  5V)
  digitalWrite(dirnPin6, LOW);

  while (x < c)           //Schritte von 0 bis c
  {
    digitalWrite(stepPin5, HIGH); //Schrittmotor 5
    delayMicroseconds(40);
    digitalWrite(stepPin5, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin6, HIGH); //Schrittmotor 6
    delayMicroseconds(40);
    digitalWrite(stepPin6, LOW);
    delayMicroseconds(40);

    x++;              //Erh�hung von x 
  }
  x = 0;                //Zur�cksetzung von x auf Null
}


void ABSENKEN3()            //Funktion um die R�der abzzusenken
{
  digitalWrite(dirnPin5, HIGH);   
  digitalWrite(dirnPin6, HIGH);

  while (x < c)           
  {
    digitalWrite(stepPin5, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin5, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin6, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin6, LOW);
    delayMicroseconds(40);

    x++;              
  }
  x = 0;                
}
