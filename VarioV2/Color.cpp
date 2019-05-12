#include "Color.h"



Color::Color(int r, int v, int b)
{
	if (r >= 0 && r <= 255) {
		Vrouge = r;
	}

	if (v >= 0 && v <= 255) {
		Vvert = v;
	}

	if (b >= 0 && b <= 255) {
		Vbleu = b;
	}
}

Color::~Color()
{
}

uint32_t Color::getColor() {
	uint32_t retour;
	retour = ((65536 * Vrouge) + (256 * Vvert) + Vbleu);
	return retour;
}

uint32_t Color::getColor(int r, int v, int b) {
	uint32_t retour;
	retour = ((65536 * Vrouge) + (256 * Vvert) + Vbleu);
	return retour;
}

bool Color::setRouge(int val) {
	if (val >= 0 && val <= 255) {
		Vrouge = val;
		return true;
	}
	else {
		return false;
	}
}

bool Color::setVert(int val) {
	if (val >= 0 && val <= 255) {
		Vvert = val;
		return true;
	}
	else {
		return false;
	}
}

bool Color::setBleu(int val) {
	if (val >= 0 && val <= 255) {
		Vbleu = val;
		return true;
	}
	else {
		return false;
	}
}

int Color::getRouge() {
	return Vrouge;
}

int Color::getVert() {
	return Vvert;
}

int Color::getBleu() {
	return Vbleu;
}

