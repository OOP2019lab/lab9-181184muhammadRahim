#include"l181184_lab9_address.h"
Address::Address(char* House_Number, char* Street_Name, char * City, char* County)
{
	house_Number = new char[strlen(House_Number)];
	street_Name = new char[strlen(Street_Name)];
	this->city = new char[strlen(City)];
	this->county = new char[strlen(County)];
	strcpy(this->house_Number, House_Number);
	strcpy(this->street_Name, Street_Name);
	strcpy(this->city, City);
	strcpy(this->county, County);
}
Address::Address(const Address& a)
{
	house_Number = new char[strlen(a.house_Number)];
	street_Name = new char[strlen(a.street_Name)];
	this->city = new char[strlen(a.city)];
	this->county = new char[strlen(a.county)];
	strcpy(this->house_Number, a.house_Number);
	strcpy(this->street_Name, a.street_Name);
	strcpy(this->city, a.city);
	strcpy(this->county, a.county);
}
ostream& operator<<(ostream& osObject, const Address& a)
{
	osObject << a.house_Number << " " << a.street_Name << " " << a.county << " " << a.city << endl;
	return osObject;
}
const Address & Address::operator=(const Address& other)
{
	delete this->house_Number;
	delete this->city;
	delete this->county;
	delete this->street_Name;
	this->house_Number = new char[strlen(other.house_Number)];
	this->street_Name = new char[strlen(other.street_Name)];
	this->city = new char[strlen(other.city)];
	this->county = new char[strlen(other.county)];
	strcpy(this->house_Number, other.house_Number);
	strcpy(this->street_Name, other.street_Name);
	strcpy(this->city, other.city);
	strcpy(this->county, other.county);
	return *this;
}
Address::~Address()
{
	delete this->house_Number;
	delete this->city;
	delete this->county;
	delete this->street_Name;
}