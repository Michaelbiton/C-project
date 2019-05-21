#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Teacher.h"
#include "Tutor.h"
#include "Class.h"
Tutor::Tutor()
{
	c = NULL;
}
Tutor::Tutor(string n, string l, int id, int e, string* na, int num, Class* c1)
{
	name = n;
	lastName = l;
	ID = id;
	exp = e;
	nameOfCourses = new string[num];
	for (int j = 0; j < num; ++j)
	{
		nameOfCourses[j] = na[j];
	}
	numOfCourses = num;
	c = c1;
}
Tutor::Tutor(const Tutor& other)
{
	this->c = new Class;
	this->c = other.c;
}
Tutor::~Tutor()
{
	c = NULL;
}
float Tutor::getSalary()const
{
	return (Teacher::getSalary() + 1200);
}
bool Tutor::excellent()
{
	return c->excellent_class();
}
void Tutor::print_pupil()
{
	c->print();
}
void Tutor::print()
{

	cout << "Tutor:"<<endl<<"First name:" << name << endl << "Last name:" << lastName << endl << "ID:" << ID << endl;
	cout << "The layer :" << c->getlayer() << endl << "The class number is:" << c->getclass() << endl;
	cout << "salary is:" << getSalary() << endl<<"expirience is:" << exp << endl;
	c->print();
}