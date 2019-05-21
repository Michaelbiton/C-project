#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Class.h"
#include "Tutor.h"
class Tutor;
class Class;

class Layer
{
private:
	char layerName;
	Class** classs;
	int classNum = 3;

public:
	Layer(char);
	Layer(const Layer& other);
	~Layer();
	void addPupil(int,Pupil*);
	Class* getClass(int);
	char getLayer();
	void addTutor(int,Tutor*);
	bool Tutor_chack(int);
};