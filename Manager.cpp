#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Manager.h"
Manager::Manager()
{

}
Manager::Manager(string n, string l, int id, int e)
{
	name = n;
	lastName = l;
	ID = id;
	exp = e;
}

Manager::~Manager()
{

}
float Manager::getSalary()const
{
	return (BASE * 3 + exp * 500);
}
bool Manager::excellent()
{
	if (exp > 4)
		return true;
	return false;
}
void Manager::print()
{
	cout << "Manager:" << endl;
	cout << "First name:" << name << endl << "Last name:" << lastName << endl << "ID:" << ID << endl;
	cout << "salary is:" << getSalary() <<endl<< "expirience is:" << exp << endl<<endl;
}
