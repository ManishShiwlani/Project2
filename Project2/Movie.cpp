#include "pch.h"
#include "Movie.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Movie::Movie() {
	this->title = "Name!";
	this->runtime = 100;
	this->mpaa = "PG-13";
	this->color = true;
	this->ratio = "16:20";
	this->year = 2013;
}

Movie::Movie(string title) {
	this->title = title;
	this->runtime = 100;
	this->mpaa = "PG-13";
	this->color = true;
	this->ratio = "16:20";
	this->year = 2013;
}

Movie::Movie(string title, int runtime, string mpaa, bool color, string ratio, int year) {
	this->title = title;
	this->runtime = runtime;
	this->mpaa = mpaa;
	this->color = color;
	this->ratio = ratio;
	this->year = year;
}

Movie::~Movie() {
	this->title = "";
	this->runtime = -1;
	this->mpaa = "";
	this->color = false;
	this->ratio = "";
	this->year = -1;
}

void Movie::printHeaders() {
	cout << left
		<< setw(20) << "Title"
		<< setw(9) << "Runtime"
		<< setw(13) << "MPAA Rating"
		<< setw(10) << "In Color"
		<< setw(14) << "Aspect Ratio"
		<< setw(12) << "Year Released"
		<< endl;
}

void Movie::print() {
	string color = this->color ? "Yes" : "No";

	cout << left
		<< setw(20) << this->title
		<< setw(9) << this->runtime
		<< setw(13) << this->mpaa
		<< setw(10) << color
		<< setw(14) << this->ratio
		<< setw(12) << this->year
		<< endl;
}

void Movie::printRaw(ofstream &file) {
	file << this->title << endl;
	file << this->runtime << endl;
	file << this->mpaa << endl;
	file << this->color << endl;
	file << this->ratio << endl;
	file << this->year << endl;
}

//getters
string Movie::getTitle() {
	return this->title;
}

int Movie::getRuntime() {
	return this->runtime;
}

string Movie::getMpaa() {
	return this->mpaa;
}

bool Movie::getColor() {
	return this->color;
}

string Movie::getRatio() {
	return this->ratio;
}

int Movie::getYear() {
	return this->year;
}

//boolean values for comparison
bool Movie::operator>(Movie &m) {
	return this->getTitle() > m.getTitle();
}

bool Movie::operator<(Movie &m) {
	return this->getTitle() < m.getTitle();
}

bool Movie::operator==(Movie &m) {
	return this->getTitle() == m.getTitle();
}

