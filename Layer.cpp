#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Pupil.h"
#include "Class.h"
#include "Layer.h"

Layer::Layer(char ln)
{
	layerName = ln;
	classs = new Class*[3];
	for (int i = 0; i < classNum; ++i)
	{
		classs[i] = new Class(Class(i+1,ln));
	}

}
Layer::Layer(const Layer& other)
{
	this->layerName = other.layerName;
	this->classNum = other.classNum;
	this->classs = new Class*[classNum];
	for (int i = 0; i < classNum; ++i)
	{
		this->classs[i] = other.classs[i];
	}

}
Layer::~Layer()
{
	for (int i = 0; i < classNum; ++i)
	{
		delete[]classs[i];
	}
	delete[]classs;
}
void Layer::addPupil(int i,Pupil* p)
{
	classs[i]->AddPupil(p);
}
Class* Layer::getClass(int i)
{
	return classs[i-1];
}
char Layer::getLayer()
{
	return layerName;
}
void Layer::addTutor(int c,Tutor* t)
{
	classs[c]->addTutor(t);
}
bool Layer::Tutor_chack(int i)
{
	return classs[i]->tutor_chack();
}