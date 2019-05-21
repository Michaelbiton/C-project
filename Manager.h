#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager();
	Manager(string, string, int, int);

	~Manager();
	float getSalary() const;
	bool excellent();
	void print();
	int salary() override { float salary = (BASE * 3 + exp * 500); return 0; };
	virtual const int getType() const { return 4; }
	virtual float get_Salary() const { return getSalary(); }

};