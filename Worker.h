#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"
#define BASE 4500

class Worker :public Person
{
protected:
	int exp;
public:
	Worker();
	Worker(string, string, int, int);
	Worker(const Worker& other);
	virtual ~Worker();
	virtual int salary() = 0;
	virtual void print() = 0;

	

};