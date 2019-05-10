#include <Arduino.h>
#include <SDS011.h>

float p10, p25;
int error;

int sound_out=10;

int randi = 100;

int ranvol = 100;

SDS011 my_sds;

void setup() {
	my_sds.begin(3, 2); //RX, TX
	Serial.begin(9600);

	randomSeed(analogRead(0));
	pinMode(sound_out, OUTPUT);
	digitalWrite(sound_out, LOW);
}
int ranNumVol;
int randNumber;
void loop() {
	ranNumVol = random (ranvol);
	digitalWrite(sound_out, ranNumVol);
	randNumber = random(randi);
	delay(randNumber);
	digitalWrite(sound_out, LOW);

	error = my_sds.read(&p25, &p10);
	if (!error) {
		Serial.println("P2.5: " + String(p25));
		Serial.println("P10:  " + String(p10));
	}
	delay(100);
}