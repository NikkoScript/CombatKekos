#include "RNGClasse.h"
#include <stdlib.h>
#include <time.h>

bool RNGClasse::singleinstance = false;

RNGClasse::RNGClasse()
{
	if (!singleinstance) {
		srand(time(NULL));
		singleinstance = true;
	}
}

RNGClasse::~RNGClasse()
{
	singleinstance = false;
}

int RNGClasse::getRNGInt(int modulo)
{
	return rand() % modulo;
}

float RNGClasse::getfloat()
{
	return static_cast<float>(rand())/static_cast<float>(RAND_MAX);
}
