#pragma once
#include <fstream>
#include <iostream>
#include "Armurie.h"
#include "CloneEnnemy.h"
class ConfigFile
{
private:
	std::ifstream fileLecture;
	Armurie* armory;
	CloneEnnemy* clone;
public:
	ConfigFile(Armurie* armo, CloneEnnemy* cl,std::string nom);
	void Lecturefichier();
	void LectureArme();
	void LectureArmure();
	void LecturePerso();



};

