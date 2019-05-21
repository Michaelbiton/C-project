#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
protected:
	string name, lastName;
	int ID;

public:
	Person(string=" ",string=" ",int=0);
	Person(const Person& other);
	~Person();
	virtual void print() =0;
	virtual bool excellent() = 0;
	int getID() const;
	virtual const int getType() const= 0;
	virtual float get_Salary() const= 0;

};
