#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Class.h"
#include "Layer.h"
#include "Person.h"

class School
{
private:
	Layer** layer;
	int layerNum = 6,personNum;
	Person** person;
	bool manager;

public:
	School();
	void manu();
};
