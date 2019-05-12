#include <iostream>
#include "pch.h"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

#include "Movie.hpp"
#include "Person.hpp"
#include "BST.hpp"
#include "Builder.hpp"

using namespace std;

void printInfo();

void printHelp();

void readMovies(const string &movieFileName, BST<Movie> &movies);

void readPeople(const string &personFileName, BST<Person> &people);

void writeMovies(const string &movieFileName, BST<Movie> &movies);

void writePeople(const string &personFileName, BST<Person> &people);

int main(int argCount, char *argValues[]) {

	// Print out some greeting text.
	cout << "Welcome the the People & Movie Application." << endl;
	cout << "Please enter a command: " << endl;

	BST<Person> people;
	BST<Movie> movies;

	readMovies("../movies.txt", movies);
	readPeople("../people.txt", people);

	Builder build(movies, people);

	char command = 0, flag = 0;

	while (command != 'x') {
		cout << "> ";
		cin >> command;
		command = tolower(command);

		switch (command) {
		case 'a':
			cin >> flag;
			flag = tolower(flag);
			switch (flag) {
			case 'm':
				build.addMovie();
				break;
			case 'p':
				build.addPerson();
				break;
			default:
				cout << "Invalid flag" << endl;
				break;
			}
			break;
		case 'l':
			cin >> flag;
			flag = tolower(flag);
			switch (flag) {
			case 'm':
				build.listMovies();
				break;
			case 'p':
				build.listPeople();
				break;
			default:
				cout << "Invalid flag" << endl;
				break;
			}
			break;
		case 'r':
			cin >> flag;
			flag = tolower(flag);
			switch (flag) {
			case 'm':
				build.deleteMovie();
				break;
			case 'p':
				build.deletePerson();
				break;
			default:
				cout << "Invalid flag" << endl;
				break;
			}
			break;
		case 'f':
			cin >> flag;
			flag = tolower(flag);
			switch (flag) {
			case 'm':
				build.findMovie();
				break;
			case 'p':
				build.findPerson();
				break;
			default:
				cout << "Invalid flag" << endl;
				break;
			}
			break;
		case 'i':
			printInfo();
			break;
		case 'h':
			printHelp();
			break;
		case 'w':
			writeMovies("../movies.txt", movies);
			writePeople("../people.txt", people);
			break;
		case 'x':
			break;
		default:
			cout << "Invalid command" << endl;
			break;
		}
	}

	// Write the new movies & people to a new text file.
	cout << "Exiting program & saving..." << endl;

	writeMovies("../newMovies.txt", movies);
	writePeople("../newPeople.txt", people);

	return EXIT_SUCCESS;
}

//print function.
void printInfo() {
	cout << endl;
	cout << left << setw(18) << "Program Version: " << setw(15) << "2.0" << endl;
	cout << left << setw(18) << "Author: " << setw(15) << "Manish Shiwlani" << endl;
	cout << endl;
}

//help command
void printHelp() {
	auto printHelp = [](string a, string b) {
		cout << left << setw(15) << a << setw(30) << b << endl;
	};

	cout << endl;
	printHelp("Command (flag)", "Description");
	printHelp("a (m/p)", "Add a movie or person to the list");
	printHelp("l (m/p)", "Print all of the movies or people in list");
	printHelp("r (m/p)", "Remove a movie or person from the list");
	printHelp("f (m/p)", "Find a movie or person in the list");
	printHelp("w", "Write movies & people to movies.txt & people.txt");
	printHelp("i", "Information about this program");
	printHelp("h", "This section of help you are currently viewing");
	printHelp("x", "Exit the program & save the data");
	cout << endl;
}

//Function to read movies from a file
void readMovies(const string &movieFileName, BST<Movie> &movies) {
	ifstream movieFile;
	movieFile.open(movieFileName);

	string title, mpaa, ratio;
	int runtime, year, colorOption;
	bool color;

	while (getline(movieFile, title) && !title.empty()) {
		movieFile >> runtime;
		movieFile.ignore();
		getline(movieFile, mpaa);
		movieFile >> colorOption;
		movieFile.ignore();
		getline(movieFile, ratio);
		movieFile >> year;
		movieFile.ignore();
		color = colorOption == 1;
		movies.insert(Movie(title, runtime, mpaa, color, ratio, year));
	}

	movieFile.close();
}

//Function to read people from a file
void readPeople(string personFileName, BST<Person> &people) {
	ifstream personFile;

	personFile.open(personFileName);

	string name, gender;
	int birthYear, deathYear;

	while (getline(personFile, name) && !name.empty()) {
		personFile >> birthYear;
		personFile.ignore();
		personFile >> deathYear;
		personFile.ignore();
		getline(personFile, gender);
		people.insert(Person(name, birthYear, deathYear, gender));
	}

	personFile.close();
}

//write movies to a file
void writeMovies(const string &movieFileName, BST<Movie> &movies) {
	ofstream movieFile;
	movieFile.open(movieFileName);

	movies.write(movieFile);

	movieFile.close();
}

//Write people to a file
void writePeople(const string &personFileName, BST<Person> &people) {
	ofstream personFile;
	personFile.open(personFileName);

	people.write(personFile);

	personFile.close();
}