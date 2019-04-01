#define PROJECT_H
class Project
{
	char* name;
	int budget;
	int duration; //estimate duration of project in weeks
	friend class Employee;
public:
	Project(char* name, int budget, int duration);
	// an overloaded constructor
	Project(const Project&);
	//copy constructor
	const Project &   operator=(const Project& other);
	//overloaded assignment operator
	friend ostream& operator<<(ostream& osObject, const Project&);
	//overloaded insertion operator
	void setBudget(int);
	~Project();
};
#endif
