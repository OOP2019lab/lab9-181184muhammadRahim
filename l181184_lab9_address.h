//Address.h
#include <iostream>
using namespace std;


#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	friend ostream& operator<<(ostream& osObject, const Address&);
	//overloaded insertion operator
private:
	char* house_Number;
	char* street_Name;
	char * city;
	char* county;

public:
	Address(char* House_Number, char* Street_Name, char * City, char* County);
	// an overloaded constructor
	Address(const Address&);
	//copy constructor
	
	const Address &   operator=(const Address& other);
	//overloaded assignment operator
	~Address();
};
#endif
