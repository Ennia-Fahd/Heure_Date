#pragma once
class Heure
{ private:
	int h, min, sec;
public:
	Heure(int h, int min , int sec);
	void Affichage() const;
	int Convert_to_Sec() const;
	bool operator>(const Heure& H) const;
	~Heure();
};
