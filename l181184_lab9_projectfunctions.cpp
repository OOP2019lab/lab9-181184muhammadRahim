#include"l181184_lab9_project.h"
Project::Project(char* name, int budget, int duration)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->budget = budget;
	this->duration = duration;
}
Project::Project(const Project& a)
{
	this->name = new char[strlen(a.name)];
	strcpy(this->name, a.name);
	this->budget = a.budget;
	this->duration = a.duration;
}
ostream& operator<<(ostream& osObject, const Project& a)
{
	osObject << "project name=" << a.name << endl << "budget=" << a.budget << endl << "duration=" << a.duration << endl;
	return osObject;
}
const Project & Project::operator=(const Project & other)
{
	delete this->name;
	this->name = new char[strlen(other.name)];
	strcpy(this->name, other.name);
	budget = other.budget;
	duration = other.duration;
	return *this;
}
void Project::setBudget(int a)
{
	this->budget = a;
}
Project::~Project()
{
	delete this->name;
}
