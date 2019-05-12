/*
Nom			Color.h
Version		V2.00
Date		01.01.2018
Auteur		Ludovic Aymon
Info		Classe de gestion des couleurs en 32 bits et RVB

Maj			10.01.2018
			Modification du nom de la méthode retrour ret en getColor
			plus parlant et plus universel

*/

#pragma once
#include <Arduino.h>

class Color
{

private:
	int Vrouge;
	int Vvert;
	int Vbleu;

public:
	Color(int r = 0, int v = 0, int b = 0);
	~Color();
	uint32_t getColor(void);
	uint32_t getColor(int r, int v, int b);
	bool setRouge(int val);
	bool setVert(int val);
	bool setBleu(int val);

	int getRouge(void);
	int getVert(void);
	int getBleu(void);

	static const uint32_t Blanc{ 0xFFFFFF };
	static const uint32_t Noir{ 0x0 };
	static const uint32_t Bleu{ 0xFF };
	static const uint32_t Vert{ 0xFF00 };
	static const uint32_t Rouge{ 0xFF0000 };
	static const uint32_t Rose{ 0xFA58F4 };
	static const uint32_t Orange{ 0xFF8000 };
	static const uint32_t Jaune{ 0xFFFF00 };
	static const uint32_t Violet{ 0x800080 };

	static const uint32_t vEM{ 0xFF00 };
	static const uint32_t rEM{ 0xFF0000 };
};

