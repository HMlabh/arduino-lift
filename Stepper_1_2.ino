/*
   Funktionen Anheben und Absenken f�r Schrittmotorenp 1 und 2.
   Sie wurden ausgelagert um die �bersichtlichkeit zu gew�hrleisten.
   Version 1.0
Stand: November 2016
Dieser Coder wurde im Rahmen einer Bachelorarbeit an der Hochschule M�nchen erstellt.
Verfasser: Kevin Wayne Wallace
 */

unsigned short a = 1000;	//Anzahl der Schritte, welche der Schrittmotor fahren soll
unsigned short x = 0;		//Ausgangsbasis der Schrittzählung

void ANHEBEN_1()            //Funktion um die Räder anzuheben
{
	digitalWrite(dirnPin1, LOW);    //Drehung im Uhrzeigersinn(Spannung  5V)
	digitalWrite(dirnPin2, LOW);

	while (x < a)           //Schritte von 0 bis a
	{
		digitalWrite(stepPin1, HIGH); //Schrittmotor 1
		delayMicroseconds(40);
		digitalWrite(stepPin1, LOW);
		delayMicroseconds(40);

		digitalWrite(stepPin2, HIGH); //Schrittmotor 2
		delayMicroseconds(40);
		digitalWrite(stepPin2, LOW);
		delayMicroseconds(40);

		x++;              //Erhöhung von x 
	}
	x = 0;                //Zurücksetzung von x auf Null
}


void ABSENKEN1()            //Funktion um die Räder abzzusenken
{
	digitalWrite(dirnPin1, HIGH);   
	digitalWrite(dirnPin2, HIGH);

	while (x < a)           
	{
		digitalWrite(stepPin1, HIGH); 
		delayMicroseconds(40);
		digitalWrite(stepPin1, LOW);
		delayMicroseconds(40);

		digitalWrite(stepPin2, HIGH); 
		delayMicroseconds(40);
		digitalWrite(stepPin2, LOW);
		delayMicroseconds(40);

		x++;              
	}
	x = 0;                
}
