#pragma once
#include "Heure.h"

class DateH : public Heure
{ private:
	int jour, mois, annee;
public :
	DateH(int h, int min, int sec, int j, int m, int a);
	bool is_bissec() const;
	int max_Jour() const;
	void Affichage() const;
	bool operator>(const DateH& D) const;
	int Convert_to_Jour() const;
	~DateH();
};
