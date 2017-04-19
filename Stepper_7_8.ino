/*
Funktionen Anheben und Absenken f�r Schrittmotoren 7 und 8.
Sie wurden ausgelagert um die �bersichtlichkeit zu gew�hrleisten.
Version 1.0
Stand: November 2016
Dieser Coder wurde im Rahmen einer Bachelorarbeit an der Hochschule M�nchen erstellt.
Verfasser: Kevin Wayne Wallace
*/

unsigned short d = 1000;        //Anzahl der Schritte welche die Schrittmotoren fahren sollen

void ANHEBEN_4()            //Funktion um die R�der anzuuheben
{
  digitalWrite(dirnPin7, LOW);    //Drehung im Uhrzeigersinn(Spannung  5V)
  digitalWrite(dirnPin8, LOW);

  while (x < d)           //Schritte von 0 bis d
  {
    digitalWrite(stepPin7, HIGH); //Schrittmotor 7
    delayMicroseconds(40);
    digitalWrite(stepPin7, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin8, HIGH); //Schrittmotor 8
    delayMicroseconds(40);
    digitalWrite(stepPin8, LOW);
    delayMicroseconds(40);

    x++;              //Erh�hung von x 
  }
  x = 0;                //Zur�cksetzung von x auf Null
}


void ABSENKEN4()            //Funktion um die R�der abzzusenken
{
  digitalWrite(dirnPin7, HIGH);   
  digitalWrite(dirnPin8, HIGH);

  while (x < d)           
  {
    digitalWrite(stepPin7, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin7, LOW);
    delayMicroseconds(40);

    digitalWrite(stepPin8, HIGH); 
    delayMicroseconds(40);
    digitalWrite(stepPin8, LOW);
    delayMicroseconds(40);

    x++;               
  }
  x = 0;                
}
