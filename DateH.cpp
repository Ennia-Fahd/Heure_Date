#include "DateH.h"
#include <iostream>

using namespace std;

DateH::DateH(int h, int min, int sec, int j, int m, int a): Heure(h,min,sec)
{
	this->annee = (a > 0) ? a : 1;
	this->mois = (m > 0 && m <= 12) ? m : 1;
	this->jour = (j>0 && j<=this->max_Jour()) ? j :1 ;

}

bool DateH::is_bissec() const
{
	if (this->annee % 4 == 0) { return true; }
	return false;
}

int DateH::max_Jour() const
{
	if (this->mois == 2) {
		return (this->is_bissec()) ? 29 : 28;
	}
	else {

		if ((this->mois < 7 && this->mois % 2 == 0) || (this->mois > 7 && this->mois % 2 != 0)) {
			return 30;
		}
		else { return 31; }
	}
}

void DateH::Affichage() const
{
	cout << "Year " << this->annee << " : Month " << this->mois << " : Jour " << this->jour << "\t";
	this->Heure::Affichage();
}

bool DateH::operator>(const DateH& D) const
{
	int J1 = this->Convert_to_Jour(), J2 = D.Convert_to_Jour();
	if (J1 > J2) { return true; }
	else if ( J1<J2 ) { return false; } 
	else {
		return this->Heure::operator>(D);
	}


}

int DateH::Convert_to_Jour() const
{
	if (this->is_bissec()) {
		return this->annee * 366 + this->jour + this->mois * this->max_Jour();
	}
	else { return this->annee * 365 + this->jour + this->mois * this->max_Jour(); }
	
}

DateH::~DateH()
{
	cout << "La class DateH est entrain de se détruire ...." << endl;
}
