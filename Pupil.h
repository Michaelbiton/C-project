#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"

class Pupil :public Person
{
protected:
	int* grades;
	int NumOfGrards, clas;
	char layer;

public:
	Pupil(string, string, int, int*, int, int, char);
	Pupil(const Pupil& other);
	~Pupil();
	float avergeGrade();
	bool excellent();
	void print();
	virtual const int getType() const {return 1;}
	virtual float get_Salary() const { return -1; }



};