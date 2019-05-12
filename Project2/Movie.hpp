#ifndef __MOVIE_HPP__
#define __MOVIE_HPP__

#include <string>
#include <fstream>

using namespace std;

class Movie {
private:

	string title;
	int runtime;
	string mpaa;
	bool color;
	string ratio;
	int year;

public:

	//Default constructor
	Movie();

	//Title of the movie
	Movie(string title);

	//Movie Constructor
	Movie(string title, int runtime, string mpaa, bool color, string ratio, int year);

	//Destructor
	~Movie();

	//printing headers
	void printHeaders();

	//printing movie object
	void print();

	//printing to file
	void printRaw(ofstream &file);

	//getters
	string getTitle();
	string getMpaa();
	string getRatio();

	int getRuntime();
	int getYear();

	bool getColor();
	bool operator>(Movie &m);
	bool operator<(Movie &m);
	bool operator==(Movie &m);
};

#endif