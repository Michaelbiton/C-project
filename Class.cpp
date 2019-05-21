#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Pupil.h"
#include "Class.h"
#include "Tutor.h"
#include "Layer.h"

Class::Class()
{
	layer = 'a';
	classNum = 0;
	pupilNum = 0;
	Pupill=new Pupil*[0];
}
Class::Class(int c, char ln)
{
	classNum = c;
	layer = ln;
	Tutorr = NULL;
}
Class::Class(const Class& other)
{
	this->layer = other.layer;
	this->classNum = other.classNum;
	this->pupilNum = other.pupilNum;
	this->Tutorr = other.Tutorr;
	this->Pupill = new Pupil*[pupilNum];
	for (int i = 0; i < pupilNum; ++i)
	{
		this->Pupill[i] = other.Pupill[i];
	}
}
Class::~Class()
{
	for (int i = 0; i < pupilNum; ++i)
	{
		delete[]Pupill[i];
	}
	delete[]Pupill;
	delete[]Tutorr;
}
void Class::AddPupil(Pupil* p)
{
	Pupil **temp;
	temp = new Pupil*[pupilNum];
	for (int i = 0; i < pupilNum; ++i)
	{
		temp[i] = Pupill[i];
	}
	pupilNum++;
	Pupill = new Pupil*[pupilNum];
	for (int i = 0; i < pupilNum; ++i)
	{
		Pupill[i]= temp[i];
	}
	Pupill[pupilNum - 1] = p;
	delete[]temp;
}
Pupil* Class::getPupil(int p)
{
	return Pupill[p];
}
bool Class::excellent_class()
{
	int c = 0;
	for (int i = 0; i < pupilNum; ++i)
	{
		if (Pupill[i]->excellent() == true)
			c++;
	}
	return c >= pupilNum*0.6;
}
void Class::print()const
{
	cout << "Pupil name list:" << endl;
	for (int i = 0; i < pupilNum; ++i)
	{
		Pupill[i]->print();
		if (Pupill[i]->excellent()==true)
		{
			cout << "excellent pupil!" << endl;
		}
		cout << endl;
	}
}
void Class::addTutor(Tutor* t)
{
	Tutorr = t;
}
bool Class::tutor_chack()
{
	if (Tutorr==NULL)
		return false;
	return true;
}
int Class::getclass()
{
	return classNum;
}
char Class::getlayer()
{
	return layer;
}