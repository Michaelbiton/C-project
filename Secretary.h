#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"

class Secretary :public Worker
{
protected:
	int child;

public:
	Secretary();
	Secretary(string, string, int, int, int);
	Secretary(const Secretary& other);
	~Secretary();
	float getSalary()const;
	bool excellent();
	void print();
	int salary() override { float salary = (BASE + child * 250); return 0; };
	virtual const int getType() const { return 5; }
	virtual float get_Salary() const { return getSalary(); }
};