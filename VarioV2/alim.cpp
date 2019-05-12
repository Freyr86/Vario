#include "alim.h"

bool alim::start() {
	bool ret{ true };
	
	// install driver du block Snooz
	config_teensy3x = SnoozeBlock(Sdigital);
	button = Bounce(alim_button, 10);

	//setup des pin
	pinMode(alim_button, INPUT_PULLUP);
	pinMode(alim_inter, OUTPUT);

	//setup pinMode
	Sdigital.pinMode(alim_button, INPUT_PULLUP, FALLING);
	return ret;
}

bool alim::wakeUp() {
	bool ret{ false };
	elapsedMillis timeOut = 0;
	while (timeOut < 6) button.update();

	while (button.duration() < alim_time){
		button.update();
		if (button.read() != 0) {
			ret = true;
		}
	}

	return ret;
}

void alim::set_erreur(String val) {
	if (erreur == "NO") {
		erreur = "";
	}
	erreur += val + "\n";
}

alim::alim()
{
}

alim::~alim()
{
}

bool alim::begin(uint8_t button, uint8_t inter, unsigned int time, uint8_t on) {
	bool ret{ true };

	//verification de l'attribution du button
	if (button > alim_pin_MIN && button < alim_pin_MAX) {
		alim_button = button;
	}
	else {
		ret = false;
		set_erreur("alim::begin : button hors plage");
	}

	//Verficication de l'attribution de la PIN d'intteruption
	if (inter > alim_pin_MIN && inter < alim_pin_MAX) {
		alim_inter = inter;
	}
	else {
		ret = false;
		set_erreur("alim::begin : inter hors plage");
	}

	//verficion  du temps d'appuye ON OFF
	if (time > 1000 && time < 10000) {
		alim_time = time;
	}
	else {
		ret = false;
		set_erreur("alim::begin : time hors plage");
	}

	//verification de l'attribtion de la valeur de PIN ON
	if (on == HIGH) {
		alim_on = HIGH;
		alim_off = LOW;
	}
	else if (on == LOW) {
		alim_on = LOW;
		alim_off = HIGH;
	}
	else {
		ret = false;
		set_erreur("alim::begin : on erreur de valeur");
	}

	//initialisation du module de someil
	if (ret) {
		ret = start();
		if (!ret) {
			set_erreur("alim::begin : erreur de start()");
		}
	}

	alim_init = ret;
	return ret;
}

void alim::sleep() {
	bool bcl{ true };

	//Boucle de remise en marche
	while (bcl) {
		//mise a jour du bouton avant le passage en sleep
		button.update();
		Snooze.deepSleep(config_teensy3x);

		bcl = wakeUp();
	}

}

void alim::on() {
	digitalWrite(alim_inter, alim_on);
}
void alim::off() {
	digitalWrite(alim_inter, alim_off);
}

String alim::get_erreur() {
	String ret;
	if (erreur == "NO") {
		ret = "";
	}
	else {
		ret = erreur;
		erreur = "NO";
	}
	return ret;
}