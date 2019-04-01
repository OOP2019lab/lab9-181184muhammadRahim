#include <iostream>
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	friend ostream& operator<<(ostream& osObject, const Project&);
	//overloaded insertion operator

private:
	char* name;
	int budget;
	int duration; //estimate duration of project in weeks

public:
	Project(char* name, int budget, int duration);
	// an overloaded constructor
	Project(const Project&);
	//copy constructor
	const Project &   operator=(const Project& other);
	//overloaded assignment operator
	void setBudget(int);
	~Project();
};
#endif
