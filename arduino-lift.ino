/*
*  Ansteuerung des Hubsystems
*  Dies ist der Ansteuerungscode für die Schrittmotoren, welche den Hub des Prototyps übernehmen.
*  Version 1.0
*  Stand: November 2016
*  Dieser Code wurde im Rahmen einer Bachelorarbeit an der Hochschule München erstellt.
*  Verfasser: Kevin Wayne Wallace
*  Überarbeitet und weiterentwickelt von Markus Gutekunst
*/
//Motor-Driver: https://www.pololu.com/product/2132
// Timer1 Libary: http://playground.arduino.cc/Code/Timer1

#define IRRemote

#include <TimerOne.h>

#ifdef IRRemote
#include <IRremote.h>        //Eingliederung der IR Bibliothek 

unsigned short receiver = 21;       //Das digitale Signal wird vom angegebenen Pin abgegriffen 
IRrecv irrecv(receiver);      //Definierung des Objekts welches die Signale der Fernbedienung ausliest 
decode_results results;        //Ergebnisse werden decodiert und unter "results" abgespeichert 

#endif // IRRemote


#define timertime 500

//-------Variables-------
namespace motor 
{
	int8_t microstep = 1;
	int16_t delay = 500;
}


//-------Pins-------
namespace pin
{
	uint8_t enable[8]		= { 2,38,36,6,39,37,A0,A8 };
	uint8_t microstep0[8]	= { 3,40,34,7,41,35,A1,A9 };
	uint8_t microstep1[8]	= { 4,42,32,8,43,33,A2,A10 };
	uint8_t microstep2[8]	= { 5,44,30,9,45,31,A3,A11 };
	uint8_t reset[8]			= { 1,46,28,10,47,29,A4,A12 };
	uint8_t sleep[8]			= { 0,48,26,11,49,27,A5,A13 };
	uint8_t step[8]			= { 14,50,22,12,51,23,A6,A14 };
	uint8_t direction[8]		= { 15,52,24,13,53,25,A7,A15 };
}


//////Motortreiber Pin Belegung//////
//unsigned short enabPin1 = 2;			//Pinbbelegung Motortreiber 1
//unsigned short miM0Pin1 = 3;
//unsigned short miM1Pin1 = 4;
//unsigned short miM2Pin1 = 5;
//unsigned short rst_Pin1 = 1;
//unsigned short slp_Pin1 = 0;
//unsigned short stepPin1 = 14;
//unsigned short dirnPin1 = 15;
//unsigned short enabPin2 = 38;		//Pinbelegung Motortreiber 2
//unsigned short miM0Pin2 = 40;
//unsigned short miM1Pin2 = 42;
//unsigned short miM2Pin2 = 44;
//unsigned short rst_Pin2 = 46;
//unsigned short slp_Pin2 = 48;
//unsigned short stepPin2 = 50;
//unsigned short dirnPin2 = 52;
//unsigned short enabPin3 = 36;		//Pinbelegung Motortreiber 3
//unsigned short miM0Pin3 = 34;
//unsigned short miM1Pin3 = 32;
//unsigned short miM2Pin3 = 30;
//unsigned short rst_Pin3 = 28;
//unsigned short slp_Pin3 = 26;
//unsigned short stepPin3 = 22;
//unsigned short dirnPin3 = 24;
//unsigned short enabPin4 = 6;		//Pinbelegung Motortreiber 4
// short miM0Pin4 = 7;
//unsigned short miM1Pin4 = 8;
//unsigned short miM2Pin4 = 9;
//unsigned short rst_Pin4 = 10;
//unsigned short slp_Pin4 = 11;
//unsigned short stepPin4 = 12;
//unsigned short dirnPin4 = 13;
//unsigned short enabPin5 = 39;		//Pinbelegung Motortreiber 5
//unsigned short miM0Pin5 = 41;
//unsigned short miM1Pin5 = 43;
//unsigned short miM2Pin5 = 45;
//unsigned short rst_Pin5 = 47;
//unsigned short slp_Pin5 = 49;
//unsigned short stepPin5 = 51;
//unsigned short dirnPin5 = 53;
//unsigned short enabPin6 = 37;		//Pinbelegung Motortreiber 6
//unsigned short miM0Pin6 = 35;
//unsigned short miM1Pin6 = 33;
//unsigned short miM2Pin6 = 31;
//unsigned short rst_Pin6 = 29;
//unsigned short slp_Pin6 = 27;
//unsigned short stepPin6 = 23;
//unsigned short dirnPin6 = 25;
//unsigned short enabPin7 = A0;		//Pinbelegung Motortreiber 7
//unsigned short miM0Pin7 = A1;
//unsigned short miM1Pin7 = A2;
//unsigned short miM2Pin7 = A3;
//unsigned short rst_Pin7 = A4;
//unsigned short slp_Pin7 = A5;
//unsigned short stepPin7 = A6;
//unsigned short dirnPin7 = A7;
//unsigned short enabPin8 = A8;		//Pinbelegung Motortreiber 8
//unsigned short miM0Pin8 = A9;
//unsigned short miM1Pin8 = A10;
//unsigned short miM2Pin8 = A11;
//unsigned short rst_Pin8 = A12;
//unsigned short slp_Pin8 = A13;
//unsigned short stepPin8 = A14;
//unsigned short dirnPin8 = A15;

int8_t step[8] = { 0 };			// 1 = normal actice;0=STOP




void setup()
{
	//Pinset
	for (int i = 0; i < 8; i++)
	{
		pinMode(pin::enable[i], OUTPUT);
		pinMode(pin::microstep0[i], OUTPUT);
		pinMode(pin::microstep1[i], OUTPUT);
		pinMode(pin::microstep2[i], OUTPUT);
		pinMode(pin::reset[i], OUTPUT);
		pinMode(pin::sleep[i], OUTPUT);
		pinMode(pin::step[i], OUTPUT);
		pinMode(pin::direction[i], OUTPUT);
	}

	//Pininit
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(pin::enable[i], HIGH);		// Driver disabled
		digitalWrite(pin::microstep0[i], LOW);	// ->
		digitalWrite(pin::microstep1[i], LOW);	// Full Step	
		digitalWrite(pin::microstep2[i], LOW);	// <-
		digitalWrite(pin::reset[i], HIGH);		// no Reset
		digitalWrite(pin::sleep[i], HIGH);		// no Sleep
		digitalWrite(pin::step[i], LOW);			// default: LOW
		digitalWrite(pin::direction[i], LOW);	// default: LOW
	}

	//USB-Serial (115200 Baus)
	Serial.begin(115200);
	while (!Serial) {
		; // wait for serial port to connect
	}
	Serial.write("init");

#ifdef IRRemote
	irrecv.enableIRIn();            //Der IR Empfänger wird initialisiert. 
#endif // IRRemote

	//Timer
	Timer1.initialize(timertime);         // initialize timer1, 500us Period
	Timer1.attachInterrupt(tick);  // attaches tick() as a timer overflow interrupt

	setmicrosteps();
	enableallmotors();
}



//enable all motors
void enableallmotors()
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(pin::enable[i], LOW);		// Driver enabled
	}
}

//disable all motors
void disableallmotors()
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(pin::enable[i], HIGH);		// Driver disabled
	}
}

//set all microsteps
void setmicrosteps()
{
	switch (motor::microstep)
	{
	case 1:		//full step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], LOW);
			digitalWrite(pin::microstep1[i], LOW);
			digitalWrite(pin::microstep2[i], LOW);
		}
		break;
	case 2:		//half step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], HIGH);
			digitalWrite(pin::microstep1[i], LOW);
			digitalWrite(pin::microstep2[i], LOW);
		}
		break;
	case 4:		//quater step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], LOW);
			digitalWrite(pin::microstep1[i], HIGH);
			digitalWrite(pin::microstep2[i], LOW);
		}
		break;
	case 8:		// 1/8-step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], HIGH);
			digitalWrite(pin::microstep1[i], HIGH);
			digitalWrite(pin::microstep2[i], LOW);
		}
		break;
	case 16:		// 1/16-step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], LOW);
			digitalWrite(pin::microstep1[i], LOW);
			digitalWrite(pin::microstep2[i], HIGH);
		}
		break;
	case 32:		// 1/32-step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], HIGH);
			digitalWrite(pin::microstep1[i], HIGH);
			digitalWrite(pin::microstep2[i], HIGH);
		}
		break;
	default:		//full step
		for (int i = 0; i < 8; i++)
		{
			digitalWrite(pin::microstep0[i], LOW);
			digitalWrite(pin::microstep1[i], LOW);
			digitalWrite(pin::microstep2[i], LOW);
		}
		break;
	}
}

void setdir(uint8_t motor, int8_t direction)
{
	switch (direction)
	{
	case 0:
		digitalWrite(pin::direction[motor], LOW);
		break;
	case 1:
		digitalWrite(pin::direction[motor], HIGH);
		break;
	default:
		break;
	}
}

//-----------INTERRUPTS------------
void tick()
{
	Serial.write("a");
	for (int i = 0; i < 8; i++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (step[i])
			{
			digitalWrite(pin::step[i], HIGH);
			}
		}

	}

	delayMicroseconds(2);

	for (int i = 0; i < 8; i++)
	{
		digitalWrite(pin::step[i], LOW);
	}
}


void loop()
{

#ifdef IRRemote
	if (irrecv.decode(&results))
	{
		switch (results.value)          //Switch Case Anweisung um die verschiedenen Motoren anzusteuern. 
		{
		case 16724175:  //Taste: 1 
			setdir(1, 0);
			step[1] = 1;
			break;   
		case 16718055:  //Taste: 2 
			setdir(1, 1);
			step[1] = 1;
			break;     
		case 16743045:  //Taste: 3
			step[1] = 0;
			break;    
		case 16716015:  //Taste: 4 
			
			break;   
		case 16726215:  //Taste: 5
			
			break;    
		case 16734885:  //Taste: 6 
			
			break;   
		case 16728765:  //Taste: 7 
			
			break;   
		case 16730805:  //Taste: 8
			
			break;    
		}
		irrecv.resume();            //Neustart des Receivers 
	}
#endif // IRRemote

}
