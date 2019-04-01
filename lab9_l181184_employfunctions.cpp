#include"l181184_lab9_employe.h"
Employee::Employee(char *name, const Address& b)
{
	this->emp_name = new char[strlen(name)];
	strcpy(emp_name, name);
	a = new Address(b);
	projects = nullptr;
}
Employee::Employee(const Employee &b)
{
	this->emp_name = new char[strlen(b.emp_name)];
	strcpy(emp_name, b.emp_name);
	a = new Address(*b.a);
	if (b.projects == nullptr)
	{
		this->projects = nullptr;
	}
	else
	{
		int count = 0;
		for (int i = 0; b.projects[i] != nullptr; i++)
		{
			count++;
		}
		projects = new Project*[count];
		for (int i = 0; b.projects[i] != nullptr; i++)
		{
			projects[i] = new Project(*b.projects[i]);
		}
	}
}
ostream& operator<<(ostream& osObject, const Employee&d)
{
	osObject << d.emp_name << endl << "Address" << *d.a <<"no. of projects="<< endl;
	if (d.projects == nullptr)
	{
		osObject << "no projects" << endl;
	}
	for (int i = 0; d.projects[i] != nullptr; i++)
	{
		osObject << *d.projects[i];
	}
	osObject << endl;
	osObject << endl;
	return osObject;
}
const Employee &Employee::operator=(const Employee& other)
{
	delete this->emp_name;
	delete this->a;
	for (int i = 0; other.projects[i] != nullptr; i++)
	{
		delete projects[i];
	}
	if (other.projects == nullptr)
	{
		this->projects = nullptr;
	}
	else
	{
		int count = 0;
		for (int i = 0; other.projects[i] != nullptr; i++)
		{
			count++;
		}
		projects = new Project*[count];
		for (int i = 0; other.projects[i] != nullptr; i++)
		{
			projects[i] = new Project(*other.projects[i]);
		}
	}
	
	a = new Address(*other.a);
	this->emp_name = new char[strlen(other.emp_name)];
	strcpy(emp_name, other.emp_name);
	return *this;
}
void Employee::addProject(Project const *a)
{
	int count = 0;
	bool found = false;
	if (this->projects != nullptr)
	{
		for (int i = 0; projects[i] != nullptr && found == false; i++)
		{
			if (strcmp(a->name, this->projects[i]->name) == 0)
			{
				found = true;
			}
		}
	}
	if (found == true)
	{
		cout << "project already exist" << endl;
	}
	else if(found==false)
	{
		if (projects != nullptr)
		{
			for (int i = 0; this->projects[i] != nullptr; i++)
			{
				count++;
			}
		}
		else
		{
			count = 0;
		}
		if (count < 2)
		{
			if (count == 0)
			{
				projects = new Project*[2];
				projects[0] = new Project(*a);
				projects[1] = nullptr;
				cout << "saved succesfully" << endl;
			}
			else
			{
				projects[count] = new Project(*a);
				projects[count + 1] = nullptr;
				cout << "saved successfully" << endl;
			}
		}
		else if (count >= 2)
		{
			cout << "not enough space" << endl;
		}
	}
}
void Employee::removeProject(const Project *a)
{
	bool found = false;
	int index = 0;
	if (this->projects != nullptr)
	{
		for (int i = 0; projects[i] != nullptr && found == false; i++)
		{
			if (strcmp(a->name, this->projects[i]->name) == 0)
			{
				found = true;
				index = i;
			}
		}
	}
	if (found == false)
	{
		cout << "project do not exist" << endl;
	}
	for (int i = index; projects[i] != nullptr; i++)
	{
		if (projects[i + 1] == nullptr)
		{
			projects[i] = nullptr;
		}
		else
		{
			projects[i + 1] = projects[i];
		}
	}
}
Employee::~Employee()
{
	delete this->emp_name;
	delete this->a;
	for (int i = 0; projects[i] != nullptr; i++)
	{
		delete this->projects[i];
	}
}
