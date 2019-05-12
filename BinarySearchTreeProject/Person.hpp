#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <string>
#include <fstream>

using namespace std;

class Person {
private:

	string name;
	int birthYear;
	int deathYear;
	string status;
	string gender;

public:

	//Default constructor
	Person();

	//new person object
	Person(string title);

	//construct a new person object
	Person(string name, int birthYear, int deathYear, string gender);

	//destructor
	~Person();

	//printing headers
	void printHeaders();

	void print();

	//printing to file
	void printRaw(ofstream &file);

	//getters
	string getName();
	int getBirthYear();
	int getDeathYear();
	string getGender();

	//return boolean value
	bool operator>(Person &p);

	//return boolean value
	bool operator<(Person &p);

	//return boolean after the comparison
	bool operator==(Person &p);
};

#endif
