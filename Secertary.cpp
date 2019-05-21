#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Secretary.h"


Secretary::Secretary()
{

}
Secretary::Secretary(string n, string l, int id, int e, int c)
{
	name = n;
	lastName = l;
	ID = id;
	exp = e;
	child = c;
}
Secretary::Secretary(const Secretary& other)
{
	this->child = other.child;
}
Secretary::~Secretary()
{

}
float Secretary::getSalary()const
{
	return (BASE + child * 250);
}
bool Secretary::excellent()
{
	if (exp > 15)
		return true;
	return false;
}
void Secretary::print()
{
	cout << "First name:" << name << endl << "Last name:" << lastName << endl << "ID:" << ID << endl;
	cout << "salary is:" << getSalary() <<endl<< "expirience is:" << exp << endl<<endl;
}