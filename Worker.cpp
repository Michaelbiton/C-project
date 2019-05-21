#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"
#include "Worker.h"

Worker::Worker()
{
	exp = 0;
}
Worker::Worker(string n, string l, int id, int e)
{
	name = n;
	lastName = l;
	ID = id;
	exp = e;
}
Worker::Worker(const Worker& other)
{
	this->exp = other.exp;
}
Worker::~Worker()
{

}

