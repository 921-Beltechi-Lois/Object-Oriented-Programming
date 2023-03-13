#pragma once
#include "Country.h"
#include "DynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

//typedef struct
//{
//    Country* arr[100];
//    int size;
//} CountryRepo; // old one

typedef struct
{
    DynamicArray* countries;
} CountryRepo;


/// Creates a PlanetRepo.
CountryRepo* createRepo();

/// Destroys a given planet repository. The memory is freed.
void destroyRepo(CountryRepo* v);

/// Finds the planet with the given name.
/// </summary>
/// <param name="v">Pointer to the PlanetRepo.</param>
/// <param name = "name">A string, the name to search for.</param>
/// <returns>pos - the position on which the planet with the given name is in the PlanetRepo; -1 - if the planet does not exist.</returns>
int find(CountryRepo* v, char name[]);


/*
	Adds a planet to the repository of planets.
	Input:	- v - pointer to the PlanetRepo
			- p - planet
	Output: 1 - if the planet was sucessfully added
			0 - if the planet could not be added, as another planet with the same name already exists in the PlanetRepo.
*/
CountryRepo* find_name(CountryRepo* v, CountryRepo* res, char name[]);
CountryRepo* find_continent(CountryRepo* v, CountryRepo* res, char name[], double given_value_of_population);
int add(CountryRepo* v, Country* p);

int removeCountryRepo(CountryRepo* v, char name[]);

int update(CountryRepo* v, char name[], double quantity, int option);

int getLength(CountryRepo* v);

/*
	Returns the planet on the given position in the planet vector.
	Input:	v - the planet repository;
			pos - integer, the position;
	Output: the planet on the given potision, or an "empty" planet.
*/
Country* getCountryOnPos(CountryRepo* v, int pos);

Country* findByName(CountryRepo* repo, char* name);

void testsCountryRepo();