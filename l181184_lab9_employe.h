#include <iostream>
#include "l181184_lab9_address.h"
#include "l181184_lab9_project.h"
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	friend ostream& operator<<(ostream& osObject, const Employee&);
	//overloaded insertion operator
private:
	char* emp_name;
	//Add Data Members here
	Address *a;
	Project** projects;
public:
	Employee(char* name, const Address&);
	//overloaded constructor
	Employee(const Employee&);
	//copy constructor
	const Employee &   operator=(const Employee& other);
	//overloaded assignment operator
	void addProject(Project const *);
	void removeProject(Project const *);
	~Employee();

};
#endif
