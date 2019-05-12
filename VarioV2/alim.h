/*Name:		alim.h
 Created:	07/01/2018 14:34:09
 Author:	Ludovic Aymon
 Version:	1.00
 Info:		Gestion de l'alimentation Teensy 3.2
 */

#pragma once
#include <Arduino.h>
#include <Bounce/Bounce.h>
#include <Snooze/Snooze.h>

#define alim_pin_MIN 0
#define alim_pin_MAX 30

class alim
{
private:
	//variable physique
	uint8_t alim_button{ 0 };
	uint8_t alim_inter{ 0 };
	unsigned int alim_time{ 2000 };
	uint8_t alim_on{ HIGH };
	uint8_t alim_off{ LOW };
	bool alim_init{ false };

	//variable de sleep
	SnoozeDigital Sdigital;
	Snoozelc5vBuffer lc5vBuffer;
	SnoozeBlock config_teensy3x;
	Bounce button = Bounce(alim_button, 10);

	//variable d'erreur
	String erreur{ "NO" };

	//initialisation du mode slep
	bool start(void);

	//procédure de réveil
	bool wakeUp(void);

	void set_erreur(String val);

public:
	alim();
	~alim();

	/*
	initialisation de la gestion d'allimutation
	button:	Bouton d'allumage et d'extinction
	inter:	Pin de sortie de la commande du reste du materiel
	time:	Temps d'appuie ON--OFF en ms
	on:		Valeur a donner à la PIN inter
	*/
	bool begin(uint8_t button, uint8_t inter, unsigned int time, uint8_t on = HIGH);

	//Entré dans le mode sleep
	void sleep(void);

	//Allumage et extinction des module extèrnes
	void on(void);
	void off(void);

	//Retourne les erreurs du module si il y en as
	String get_erreur(void);
};

