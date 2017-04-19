/*
*  Ansteuerung des Hubsystems
*  Dies ist der Ansteuerungscode für die Schrittmotoren, welche den Hub des Prototyps übernehmen.
*  Version 1.0
*  Stand: November 2016
*  Dieser Code wurde im Rahmen einer Bachelorarbeit an der Hochschule München erstellt.
*  Verfasser: Kevin Wayne Wallace
*  Überarbeitet und weiterentwickelt von Markus Gutekunst
*/


//-------Pins-------

//////Motortreiber Pin Belegung//////
unsigned short enabPin1 = 2;			//Pinbbelegung Motortreiber 1
unsigned short miM0Pin1 = 3;
unsigned short miM1Pin1 = 4;
unsigned short miM2Pin1 = 5;
unsigned short rst_Pin1 = 1;
unsigned short slp_Pin1 = 0;
unsigned short stepPin1 = 14;
unsigned short dirnPin1 = 15;

unsigned short enabPin2 = 38;		//Pinbelegung Motortreiber 2
unsigned short miM0Pin2 = 40;
unsigned short miM1Pin2 = 42;
unsigned short miM2Pin2 = 44;
unsigned short rst_Pin2 = 46;
unsigned short slp_Pin2 = 48;
unsigned short stepPin2 = 50;
unsigned short dirnPin2 = 52;

unsigned short enabPin3 = 36;		//Pinbelegung Motortreiber 3
unsigned short miM0Pin3 = 34;
unsigned short miM1Pin3 = 32;
unsigned short miM2Pin3 = 30;
unsigned short rst_Pin3 = 28;
unsigned short slp_Pin3 = 26;
unsigned short stepPin3 = 22;
unsigned short dirnPin3 = 24;

unsigned short enabPin4 = 6;		//Pinbelegung Motortreiber 4
unsigned short miM0Pin4 = 7;
unsigned short miM1Pin4 = 8;
unsigned short miM2Pin4 = 9;
unsigned short rst_Pin4 = 10;
unsigned short slp_Pin4 = 11;
unsigned short stepPin4 = 12;
unsigned short dirnPin4 = 13;

unsigned short enabPin5 = 39;		//Pinbelegung Motortreiber 5
unsigned short miM0Pin5 = 41;
unsigned short miM1Pin5 = 43;
unsigned short miM2Pin5 = 45;
unsigned short rst_Pin5 = 47;
unsigned short slp_Pin5 = 49;
unsigned short stepPin5 = 51;
unsigned short dirnPin5 = 53;

unsigned short enabPin6 = 37;		//Pinbelegung Motortreiber 6
unsigned short miM0Pin6 = 35;
unsigned short miM1Pin6 = 33;
unsigned short miM2Pin6 = 31;
unsigned short rst_Pin6 = 29;
unsigned short slp_Pin6 = 27;
unsigned short stepPin6 = 23;
unsigned short dirnPin6 = 25;

unsigned short enabPin7 = A0;		//Pinbelegung Motortreiber 7
unsigned short miM0Pin7 = A1;
unsigned short miM1Pin7 = A2;
unsigned short miM2Pin7 = A3;
unsigned short rst_Pin7 = A4;
unsigned short slp_Pin7 = A5;
unsigned short stepPin7 = A6;
unsigned short dirnPin7 = A7;

unsigned short enabPin8 = A8;		//Pinbelegung Motortreiber 8
unsigned short miM0Pin8 = A9;
unsigned short miM1Pin8 = A10;
unsigned short miM2Pin8 = A11;
unsigned short rst_Pin8 = A12;
unsigned short slp_Pin8 = A13;
unsigned short stepPin8 = A14;
unsigned short dirnPin8 = A15;





void setup()
{

	//-------Pinset-------
	pinMode(enabPin1, OUTPUT);		//Motortreiber 1
	pinMode(miM0Pin1, OUTPUT);
	pinMode(miM1Pin1, OUTPUT);
	pinMode(miM2Pin1, OUTPUT);
	pinMode(rst_Pin1, OUTPUT);
	pinMode(slp_Pin1, OUTPUT);
	pinMode(stepPin1, OUTPUT);
	pinMode(dirnPin1, OUTPUT);

	pinMode(enabPin2, OUTPUT);		//Motortreiber 2
	pinMode(miM0Pin2, OUTPUT);
	pinMode(miM1Pin2, OUTPUT);
	pinMode(miM2Pin2, OUTPUT);
	pinMode(rst_Pin2, OUTPUT);
	pinMode(slp_Pin2, OUTPUT);
	pinMode(stepPin2, OUTPUT);
	pinMode(dirnPin2, OUTPUT);

	pinMode(enabPin3, OUTPUT);		//Motortreiber 3
	pinMode(miM0Pin3, OUTPUT);
	pinMode(miM1Pin3, OUTPUT);
	pinMode(miM2Pin3, OUTPUT);
	pinMode(rst_Pin3, OUTPUT);
	pinMode(slp_Pin3, OUTPUT);
	pinMode(stepPin3, OUTPUT);
	pinMode(dirnPin3, OUTPUT);

	pinMode(enabPin4, OUTPUT);		//Motortreiber 4
	pinMode(miM0Pin4, OUTPUT);
	pinMode(miM1Pin4, OUTPUT);
	pinMode(miM2Pin4, OUTPUT);
	pinMode(rst_Pin4, OUTPUT);
	pinMode(slp_Pin4, OUTPUT);
	pinMode(stepPin4, OUTPUT);
	pinMode(dirnPin4, OUTPUT);

	pinMode(enabPin5, OUTPUT);		//Motortreiber 5
	pinMode(miM0Pin5, OUTPUT);
	pinMode(miM1Pin5, OUTPUT);
	pinMode(miM2Pin5, OUTPUT);
	pinMode(rst_Pin5, OUTPUT);
	pinMode(slp_Pin5, OUTPUT);
	pinMode(stepPin5, OUTPUT);
	pinMode(dirnPin5, OUTPUT);

	pinMode(enabPin6, OUTPUT);		//Motortreiber 6
	pinMode(miM0Pin6, OUTPUT);
	pinMode(miM1Pin6, OUTPUT);
	pinMode(miM2Pin6, OUTPUT);
	pinMode(rst_Pin6, OUTPUT);
	pinMode(slp_Pin6, OUTPUT);
	pinMode(stepPin6, OUTPUT);
	pinMode(dirnPin6, OUTPUT);

	pinMode(enabPin7, OUTPUT);		//Motortreiber 7
	pinMode(miM0Pin7, OUTPUT);
	pinMode(miM1Pin7, OUTPUT);
	pinMode(miM2Pin7, OUTPUT);
	pinMode(rst_Pin7, OUTPUT);
	pinMode(slp_Pin7, OUTPUT);
	pinMode(stepPin7, OUTPUT);
	pinMode(dirnPin7, OUTPUT);

	pinMode(enabPin8, OUTPUT);		//Motortreiber 8
	pinMode(miM0Pin8, OUTPUT);
	pinMode(miM1Pin8, OUTPUT);
	pinMode(miM2Pin8, OUTPUT);
	pinMode(rst_Pin8, OUTPUT);
	pinMode(slp_Pin8, OUTPUT);
	pinMode(stepPin8, OUTPUT);
	pinMode(dirnPin8, OUTPUT);

	//Einstellung der Pins an einzelnen Motortreibern:
	digitalWrite(enabPin1, LOW);	//Motortreiber 1
	digitalWrite(miM0Pin1, HIGH);
	digitalWrite(miM1Pin1, HIGH);
	digitalWrite(miM2Pin1, HIGH);
	digitalWrite(rst_Pin1, HIGH);
	digitalWrite(slp_Pin1, HIGH);

	digitalWrite(enabPin2, LOW);	//Motortreiber 2
	digitalWrite(miM0Pin2, HIGH);
	digitalWrite(miM1Pin2, HIGH);
	digitalWrite(miM2Pin2, HIGH);
	digitalWrite(rst_Pin2, HIGH);
	digitalWrite(slp_Pin2, HIGH);

	digitalWrite(enabPin3, LOW);	//Motortreiber 3
	digitalWrite(miM0Pin3, HIGH);
	digitalWrite(miM1Pin3, HIGH);
	digitalWrite(miM2Pin3, HIGH);
	digitalWrite(rst_Pin3, HIGH);
	digitalWrite(slp_Pin3, HIGH);

	digitalWrite(enabPin4, LOW);	//Motortreiber 4
	digitalWrite(miM0Pin4, HIGH);
	digitalWrite(miM1Pin4, HIGH);
	digitalWrite(miM2Pin4, HIGH);
	digitalWrite(rst_Pin4, HIGH);
	digitalWrite(slp_Pin4, HIGH);

	digitalWrite(enabPin5, LOW);	//Motortreiber 5
	digitalWrite(miM0Pin5, HIGH);
	digitalWrite(miM1Pin5, HIGH);
	digitalWrite(miM2Pin5, HIGH);
	digitalWrite(rst_Pin5, HIGH);
	digitalWrite(slp_Pin5, HIGH);

	digitalWrite(enabPin6, LOW);	//Motortreiber 6
	digitalWrite(miM0Pin6, HIGH);
	digitalWrite(miM1Pin6, HIGH);
	digitalWrite(miM2Pin6, HIGH);
	digitalWrite(rst_Pin6, HIGH);
	digitalWrite(slp_Pin6, HIGH);

	digitalWrite(enabPin7, LOW);	//Motortreiber 7
	digitalWrite(miM0Pin7, HIGH);
	digitalWrite(miM1Pin7, HIGH);
	digitalWrite(miM2Pin7, HIGH);
	digitalWrite(rst_Pin7, HIGH);
	digitalWrite(slp_Pin7, HIGH);

	digitalWrite(enabPin8, LOW);	//Motortreiber 8
	digitalWrite(miM0Pin8, HIGH);
	digitalWrite(miM1Pin8, HIGH);
	digitalWrite(miM2Pin8, HIGH);
	digitalWrite(rst_Pin8, HIGH);
	digitalWrite(slp_Pin8, HIGH);

}

void loop()
{

  /* add main program code here */

}
