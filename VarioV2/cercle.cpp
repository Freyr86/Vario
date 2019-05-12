#include "cercle.h"

unsigned int cercle::led_relative(unsigned int led_id) {
	unsigned int ret{ 0 };
	ret = led_id + cercle_led_up;
	if (ret >= cercle_n_led) {
		ret = ret - cercle_n_led;
	}
	return ret;
}

void cercle::set_erreur(String val) {
	if (erreur == "NO" && val != "") {
		erreur = "";
	}
	erreur += "\n " + val;
}

cercle::cercle()
{
}
cercle::cercle(unsigned char pin, unsigned int n_led, unsigned int led_up) {
	if (pin >= cercle_pin_MIN && pin <= cercle_pin_MAX) {
		cercle_pin = pin;
	}

	if (n_led >= 0) {
		cercle_n_led = n_led;
	}

	if (led_up >= n_led) {
		cercle_led_up = led_up;
	}
}
cercle::~cercle()
{
}

void cercle::start() {
	circle = new Adafruit_NeoPixel(cercle_n_led, cercle_pin, NEO_GRB + NEO_KHZ800);
	circle->begin();
	circle->clear();
}
void cercle::stop() {
	circle->~Adafruit_NeoPixel();
}
void cercle::clear() {
	circle->clear();
	for (unsigned int bcl = 0; bcl < cercle_n_led; bcl++) {
		circle->setPixelColor(bcl, Color::Noir);
		circle->setBrightness(0);
		circle->show();
	}
}
bool cercle::setLum(uint8_t luminosite) {
	bool ret{ true };
	if (luminosite >= 0 && luminosite <= 254) {
		cercle_lum = luminosite;
		circle->setBrightness(luminosite);
		circle->show();
	}
	else {
		set_erreur("cercle::setLum : luminosite hors plage");
		ret = false;
	}
	return ret;
}
uint8_t cercle::getLum() {
	return cercle_lum;
}
bool cercle::setCol(u_int32_t couleur, unsigned int id_led, bool relative) {
	bool ret{ true };
	unsigned int id{ 0 };
	if (relative) {
		id_led = led_relative(id_led);
	}
	if (id_led < cercle_n_led) {
		circle->setPixelColor(id_led, couleur);
		circle->show();
	}
	else {
		set_erreur("cercle::setCol : id LED erronee");
		ret = false;
	}
}
bool cercle::setCol(Color couleur, unsigned int id_led, bool relative) {
	return setCol(couleur.getColor(), id_led);
}
Color cercle::getCol(unsigned int id_led) {
	Color ret = Color::Noir;
	if (id_led < cercle_n_led) {
		ret = circle->getPixelColor(id_led);
	}
	return ret;
}

bool cercle::setUp(uint8_t led_up) {
	bool ret{ true };
	if (led_up < cercle_n_led) {
		cercle_led_up = led_up;
	}
	else {
		set_erreur("cercle::setUp : Les haute index invalide");
		ret = false;
	}
	return ret;
}

void cercle::test(u_int32_t couleur, uint8_t lum, unsigned int temp) {
	circle->clear();
	this->setLum(lum);
	for (unsigned int bcl = 0; bcl < cercle_n_led; bcl++) {
		circle->setBrightness(cercle_lum);
		this->setCol(couleur, bcl, true);
		delay(temp);
	}
	this->clear();
}
void cercle::test(Color couleur, uint8_t lum, unsigned int temp) {
	this->test(couleur.getColor(), lum, temp);
}

String cercle::get_erreur() {
	String temp{ erreur };
	erreur = "NO";
	return temp;
}