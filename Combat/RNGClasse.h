#pragma once
class RNGClasse
{
private:
	static bool singleinstance;
public : 
	//intiliasation seed lors de l'appel du constructeur
	RNGClasse();
	~RNGClasse();
	int getRNGInt(int);
	float getfloat();


};

