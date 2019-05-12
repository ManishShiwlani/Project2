#ifndef FINAL_ESSENTIALS_HPP
#define FINAL_ESSENTIALS_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Essentials {
public:

	//Message for bad input
	int readIntInput(const string &msg) {
		int var;
		cout << msg;
		while (!(cin >> var)) {
			cout << "Bad input, please try again: " << msg;
			cin.clear();
		}
		return var;
	}

	//Function to read an input
	const string readStringInput(const string &msg) {
		string var;
		cout << msg;
		cin.ignore();
		getline(cin, var);
		return var;
	}

	//Function for getting movie color
	bool getMovieColor() {
		char answer;
		cout << "Is the movie in color? (y/n) ";
		cin >> answer;
		switch (answer) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "Please try again, ";
			return getMovieColor();
		}
	}

	//Date of Birth for a person
	int getBirthDate(const string &msg) {
		int year;
		year = readIntInput(msg);

		if (year < 1800) {
			cout << "Sorry, they cannot be born before 1800, please try again." << endl;
			return getBirthDate(msg);
		}
		else {
			return year;
		}
	}

	//Date of death for a person
	int getDeathDate(int birthDate) {
		char cmd;
		int year;
		cout << "Are they still alive? (y/n) ";
		cin >> cmd;
		switch (cmd) {
		case 'y':
			return -1;
		case 'n':
			year = readIntInput("When did they die (year)? ");
			if (year < birthDate) {
				cout << "Sorry, death date was before birth date." << endl;
			}
			else {
				return year;
			}
		default:
			cout << "Try again, ";
			return getDeathDate(birthDate);
		}
	}
};

#endif
