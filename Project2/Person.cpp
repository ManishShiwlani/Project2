#include "pch.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Person.hpp"

using namespace std;

Person::Person() {
	this->name = "Robbin Williams";
	this->birthYear = -1;
	this->deathYear = -1;
	this->gender = "Unknown";
	this->status = "Unknown";
}

Person::Person(string name) {
	this->name = name;
	this->birthYear = -1;
	this->deathYear = -1;
	this->gender = "Unknown";
	this->status = "Unknown";
}

Person::Person(string name, int birthYear, int deathYear, string gender) {
	this->name = name;
	this->birthYear = birthYear;
	this->deathYear = deathYear;
	this->gender = gender;

	if (this->deathYear < 0) {
		this->status = "Still alive";
	}
	else {
		stringstream str;
		str << "Died in " << deathYear;
		this->status = str.str();
	}
}

Person::~Person() {
	this->name = "";
	this->birthYear = 0;
	this->deathYear = 0;
	this->gender = "";
	this->status = "";
}

void Person::printHeaders() {
	cout << left
		<< setw(20) << "Name"
		<< setw(14) << "Birth Year"
		<< setw(14) << "Status"
		<< setw(15) << "Gender"
		<< endl;
}

void Person::print() {
	cout << left
		<< setw(20) << this->name
		<< setw(14) << this->birthYear
		<< setw(14) << this->status
		<< setw(15) << this->gender
		<< endl;
}

void Person::printRaw(ofstream &file) {
	file << this->name << endl;
	file << this->birthYear << endl;
	file << this->deathYear << endl;
	file << this->gender << endl;
}

string Person::getName() {
	return this->name;
}

int Person::getBirthYear() {
	return this->birthYear;
}

int Person::getDeathYear() {
	return this->deathYear;
}

string Person::getGender() {
	return this->gender;
}

bool Person::operator>(Person &p) {
	return this->getName() > p.getName();
}

bool Person::operator<(Person &p) {
	return this->getName() < p.getName();
}

bool Person::operator==(Person &p) {
	return this->getName() == p.getName();
}