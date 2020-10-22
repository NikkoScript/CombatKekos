#pragma once
#include <degat.h>
class coefDegPhys
{
private :
	float *coef;
	float* resmagique;
public : 
	// int *res : tableau des resistance ( int[dmagiquetaille] )
	// armure : sum armure ( pour initiliser le coef armure ) 
	coefDegPhys(classeArmure c, int *res,int armure);
	float* getcoef() const;
	//multiplication de coef* degat
	float multDeg(degat d);

};

