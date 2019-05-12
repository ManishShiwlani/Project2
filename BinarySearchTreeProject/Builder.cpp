#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "pch.h"

#include "Movie.hpp"
#include "Person.hpp"
#include "BST.hpp"
#include "Builder.hpp"


Builder::Builder() {
	this->movies = BST<Movie>();
	this->people = BST<Person>();
}

Builder::Builder(BST<Movie> &movies, BST<Person> &people) {
	this->movies = movies;
	this->people = people;
}

BST<Movie> Builder::getMovies() {
	return this->movies;
}

BST<Person> Builder::getPeople() {
	return this->people;
}

void Builder::setMovies(BST<Movie> &movies) {
	this->movies = movies;
}

void Builder::setPeople(BST<Person> &people) {
	this->people = people;
}

void Builder::addMovie() {
	string title, mpaa, ratio;
	int runtime, year;
	bool color;

	title = components.readStringInput("Title: ");
	runtime = components.readIntInput("Runtime (min): ");
	mpaa = components.readStringInput("MPAA rating: ");
	color = components.getMovieColor();
	ratio = components.readStringInput("Aspect ratio: ");
	year = components.readIntInput("Release year: ");

	movies.insert(Movie(title, runtime, mpaa, color, ratio, year));
}

void Builder::addPerson() {
	string name, gender;
	int birthYear, deathYear;

	name = components.readStringInput("Name: ");
	birthYear = components.getBirthDate("Birth year: ");
	deathYear = components.getDeathDate(birthYear);
	gender = components.readStringInput("Gender: ");

	people.insert(Person(name, birthYear, deathYear, gender));
}

void Builder::listMovies() {
	if (movies.isEmpty()) {
		cout << "No Movies!" << endl;
		return;
	}
	else {
		movies.print();
	}
}

void Builder::listPeople() {
	if (people.isEmpty()) {
		cout << "There are no people!" << endl;
		return;
	}
	else {
		people.print();
	}
}

void Builder::deleteMovie() {
	string title = components.readStringInput("Title: ");
	Movie temp(title);

	movies.removeItem(temp);
}

void Builder::deletePerson() {
	string title = components.readStringInput("Name: ");
	Person temp(title);

	people.removeItem(temp);
}

void Builder::findMovie() {
	string title = components.readStringInput("Title: ");
	Movie temp(title);

	movies.search(temp);
}

void Builder::findPerson() {
	string title = components.readStringInput("Name: ");
	Person temp(title);

	people.search(temp);
}


