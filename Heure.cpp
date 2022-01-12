#include "Heure.h"
#include <iostream>
using namespace std;
Heure::Heure(int h, int min, int sec)
{
	this->h = h > 0 && h < 24 ? h : 0;
	this->min = min > 0 && min < 60 ? min : 0;
	this->sec = sec > 0 && sec < 60 ? sec : 0;
}

void Heure::Affichage() const
{
	cout << this->h << ":" << this->min << ":" << this->sec << "." << endl;
}

int Heure::Convert_to_Sec() const
{
	return this->h*3600 + this->min*60 + this->sec;
}

bool Heure::operator>(const Heure& H) const
{
	int Sec1 = this->Convert_to_Sec(), Sec2 = H.Convert_to_Sec();
	if (Sec1 > Sec2) { return true; }
	return false;
}

Heure::~Heure()
{
	cout << "Destruction class Heure..." << endl;
}
