/*
Nom			cerle
Version		V1.00
Date		26.12.2017
Auteur		Ludovic Aymon
Info		Classe de gestion d'un néopixel circle
			Permet l'affichage et la modification de position

Maj			-

*/

#pragma once
#include <Arduino.h>
#include "Color.h"
#include <Adafruit_NeoPixel.h>

#define cercle_pin_MIN 0
#define cercle_pin_MAX 30


class cercle
{
private:
	unsigned char cercle_pin{ 0 };
	unsigned int cercle_n_led{ 0 };
	unsigned int cercle_led_up{ 0 };
	u_int8_t cercle_lum{ 10 };

	Adafruit_NeoPixel *circle;

	String erreur{ "NO" };

	//permet de recupérer l'id materiel par rapport a la position relative
	unsigned int led_relative(unsigned int led_id);

	void set_erreur(String val);
public:
	cercle();
	/*
	cretion de l'objet cercle
	pin:	N de la pin ou est brancher le cercle
	n_led:	Nombre de LEDs sur le cercle
	*/
	cercle(unsigned char pin, unsigned int n_led, unsigned int led_up = 0);
	~cercle();

	//fonctions basique
	//démarage du cercle de LEDs
	void start(void);
	//arete le cercle
	void stop(void);
	//nettoyage du cercle de LEDs
	void clear(void);
	/*
	modification de la luminosité
	luminosite:	Luminosité du cercle
	*/
	bool setLum(uint8_t luminosite);
	uint8_t getLum(void);
	/*
	modification de la couleur d'une LED
	couleur:	couleur de la LED
	id_led:		id de la LED
	relative:	permet de modifier la couelur relativement a la position du cercle
	*/
	bool setCol(u_int32_t couleur, unsigned int id_led, bool relative = true);
	bool setCol(Color couleur, unsigned int id_led, bool relative = true);
	Color getCol(unsigned int id_led);
	/*
	Modification de la LED qui est vers le eau
	id_led:		id de la LED qui est en haut
	*/
	bool setUp(uint8_t led_up);

	/*
	Test des leds
	couleur:	couleur pour le test
	lum:		Luminosité des LEDs
	temp:		temps d'attente entre chaque LEDs em ms
	*/
	void test(u_int32_t couleur = Color::Vert, uint8_t lum = 10, unsigned int temp = 300);
	void test(Color couleur, uint8_t lum = 10, unsigned int temp = 300);

	String get_erreur(void);
};

