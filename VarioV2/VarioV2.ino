/*
 Name:		VarioV2.ino
 Created:	07/01/2018 14:34:09
 Author:	Ludovic Aymon
 Version:	2.00
 Info:		Gestion du variomètre avec led et son 
*/
#include "alim.h"
#include "cercle.h"
#include "Color.h"

#include <Wire.h>

#define ON digitalWrite(13,HIGH);
#define OFF digitalWrite(13,LOW);

alim test;
//cercle circl(14,12);

void setup() {
	pinMode(13, OUTPUT);
	test.begin(21, 12, 3000, HIGH);
	Serial.begin(9600);
	Wire.begin();
}


void loop() {
	
	tone(2, 5000, 100);
	Serial.println("Done");
	delay(200);
}

