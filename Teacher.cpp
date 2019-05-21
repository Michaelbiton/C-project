#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Teacher.h"
Teacher::Teacher()
{
	nameOfCourses = NULL;
	numOfCourses = 0;
}
Teacher::Teacher(string n, string l, int id, int e, string* na, int num)
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
}
Teacher::Teacher(const Teacher& other)
{
	this->numOfCourses = other.numOfCourses;
	this->nameOfCourses = new string[numOfCourses];
	for (int i = 0; i < numOfCourses; ++i)
	{
		this->nameOfCourses[i] = other.nameOfCourses[i];
	}
}
Teacher::~Teacher()
{
	delete[]nameOfCourses;
}
float Teacher::getSalary ()const
{
	float salary = BASE * (1 + numOfCourses / 10) + 200 * exp;
	return salary;
}
bool Teacher::excellent()
{
	if (numOfCourses > 5)
		return true;
	return false;
}
void Teacher::printCourses()const
{
	cout << "The name of the courses:" << endl;
	for (int i = 0; i < numOfCourses; ++i)
	{
		cout << nameOfCourses[i] << endl;
	}
}
void Teacher::print()
{
	cout <<"Teacher:" << endl<<"First name:" << name << endl << "Last name:" << lastName << endl << "ID:" << ID << endl;
	printCourses();
	cout << "salary is:"<<getSalary() <<endl<< "expirience is:"<<exp<<endl<<endl;
}
