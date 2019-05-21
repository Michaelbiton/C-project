#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Teacher.h"
#include "Class.h"
class Class;
class Tutor :public Teacher
{
protected:
	Class* c;

public:
	Tutor();
	Tutor(string, string, int, int, string*, int,Class*);
	Tutor(const Tutor& other);
	~Tutor();
	float getSalary()const;
	bool excellent();
	void print_pupil();
	void print();
	virtual const int getType() const { return 3; }
	virtual float get_Salary() const { return getSalary(); }

};