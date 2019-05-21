#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Pupil.h"
#include "Tutor.h"
#include "Layer.h"
class Tutor;
class Class
{
protected:
	char layer;
	int classNum,pupilNum;
	Pupil **Pupill;
	Tutor *Tutorr;
	
public:
	Class();
	Class(int,char);
	Class(const Class& other);
	~Class();
	void AddPupil(Pupil*);
	Pupil* getPupil(int);
	void addTutor(Tutor*);
	bool excellent_class();
	void print() const;
	bool tutor_chack();
	int getclass();
	char getlayer();

};