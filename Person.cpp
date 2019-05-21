#include "Person.h"

Person::Person(string n, string l, int i) :name(n), lastName(l), ID(i)
{
	
}
Person::Person(const Person& other)
{
	this->name = other.name;
	this->lastName = other.lastName;
	this->ID = other.ID;
}
Person::~Person()
{

}

int Person::getID() const
{
	return ID;
}