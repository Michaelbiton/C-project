#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"

class Teacher :public Worker
{
protected:
	string* nameOfCourses;
	int numOfCourses;
public:
	Teacher();
	Teacher(string, string, int, int, string*, int);
	Teacher(const Teacher& other);
	~Teacher();
	float getSalary() const;
	bool excellent();
	void printCourses() const;
	void print();
	int salary() override { float salary = BASE * (1 + numOfCourses / 10) + 200 * exp; return 0; };
	virtual const int getType() const { return 2; }
	virtual float get_Salary() const { return getSalary(); }

};