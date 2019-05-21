#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"
#include "Pupil.h"


Pupil::Pupil(string n, string l, int id, int* g, int num, int c, char h):Person(n,l,id),NumOfGrards(num),clas(c),layer(h)
{
	grades = new int[num];
	for (int j = 0; j < num; ++j)
	{
		grades[j] = g[j];
	}
}
Pupil::Pupil(const Pupil& other)
{
	this->NumOfGrards = other.NumOfGrards;
	this->clas = other.clas;
	this->layer = other.layer;
	this->grades = new int[NumOfGrards];
	for (int i = 0; i < NumOfGrards; ++i)
	{
		this->grades[i] = other.grades[i];
	}
}
Pupil::~Pupil()
{
	delete[]grades;
}
float Pupil::avergeGrade()
{
	float h = 0;
	int sum = 0;
	for (int i = 0; i < NumOfGrards; ++i)
	{
		sum += grades[i];
	}
	h = sum / NumOfGrards;
	return h;
}
bool Pupil::excellent() 
{
	for (int i = 0; i < NumOfGrards; ++i)
	{
		if (grades[i] < 70)
			return false;
	}
	if (avergeGrade() <= 85)
	{
		return false;
	}
	return true;

}
void Pupil::print() 
{
	cout <<"Pupil:" << endl <<"First name:" << name << endl << "Last name:" << lastName << endl << "ID:" << ID << endl;
	cout << "Pupil layer:" << layer << endl << "Pupil class:" << clas << endl;
	cout << "Pupil grades:" << endl;
	for (int i = 0; i < NumOfGrards; ++i)
	{
		cout << "Grade of cours number " << i + 1<<"-";
		cout << grades[i] << endl;
	}
	float a = avergeGrade();
	cout << "The avarage grade is:" << a << endl<<endl;
}