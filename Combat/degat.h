#pragma once
enum class dphysique{perforant,impact,tranchant};
const int dphysiquetaille = 3;
enum class dmagique{feu,eau,terre,vent,ombre,lumiere};
const int dmagiquetaille = 6;
enum class classeArmure { lourde, moyenne, legere };

class degat
{ 
private : 
	int degatphysique[dphysiquetaille];
	int degatmagique[dmagiquetaille];

public :
	degat();
	degat(int, int, int);
	degat(int, int, int, int, int, int);
	degat(int, int, int, int, int, int, int, int, int);
	int getdegatphysique(dphysique) const;
	int getdegatmagique(dmagique) const;
	degat& adddegat(degat const&);
	degat multphysique(float value);
	degat multmagique(float value);
	degat& operator+=(degat const& a);

};

degat operator+(degat const&, degat const&);

