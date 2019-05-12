#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

#include "BST.hpp"
#include "Movie.hpp"
#include "Person.hpp"
#include "Essentials.hpp"


class Builder {
private:
	BST<Movie> movies;
	BST<Person> people;
	Essentials components;

public:
	// Default constructor.
	Builder();

	// Builder for BST of movies and people
	Builder(BST<Movie> &movies, BST<Person> &people);

	// Getting the movies
	BST<Movie> getMovies();

	// Getting the people
	BST<Person> getPeople();

	// Setting the movies
	void setMovies(BST<Movie> &movies);

	// Setting the people
	void setPeople(BST<Person> &people);

	// adding a movie
	void addMovie();

	// adding a person
	void addPerson();

	// listing movies
	void listMovies();

	// listing people
	void listPeople();

	// finding the movie
	void findMovie();

	// Function the person
	void findPerson();

	// deleting a movie
	void deleteMovie();

	// deleting a person
	void deletePerson();
};
#endif
