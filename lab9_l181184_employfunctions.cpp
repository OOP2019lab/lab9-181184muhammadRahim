#include"l181184_lab9_employe.h"
Employee::Employee(char *name, const Address& b)
{
	this->emp_name=new char[strlen(name)];
	strcpy(emp_name, name);
	a = new Address(b);
}
Employee::Employee(const Employee &b)
{
	this->emp_name = new char[strlen(b.emp_name)];
	strcpy(emp_name, b.emp_name);
	a = new Address(*b.a);
}
ostream& operator<<(ostream& osObject, const Employee&d)
{
	osObject << d.emp_name <<endl<<"Address"<< *d.a << endl;
	osObject << endl;
	return osObject;
}
const Employee &Employee::operator=(const Employee& other)
{
	delete this->emp_name;
	delete this->a;
	a = new Address(*other.a);
	this->emp_name = new char[strlen(other.emp_name)];
	strcpy(emp_name, other.emp_name);

}
