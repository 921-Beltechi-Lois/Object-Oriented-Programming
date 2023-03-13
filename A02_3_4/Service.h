#pragma once
#include "CountryRepository.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
    CountryRepo* repo;
    DynamicArray* undoStack;
    DynamicArray* redoStack;
} Service;

Service* createService(CountryRepo* repo);
void destroyService(Service* s);

/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="s">Pointer to the Service.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "type">A string, the planet's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the planet to Earth, in light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same name already exists.</returns>
int addCountry(Service* s, char* name, char* continent, double population);

int removeCountry(Service* s, char* name);

int updateCountry(Service* s, char name[], double quantity, int option);

CountryRepo* getRepo(Service* s);


/// <summary>
/// Searches for the planets containing a given type.
/// </summary>
/// <param name="s">Pointer to the Service.</param>
/// <param name = "symbols">A string, the searched type; "null" - for all the planets.</param>
/// <returns>A pointer to a repository of planets, that have the given type.</returns>

CountryRepo* filter(Service* s, char type[], int option, double given_value_of_population);

CountryRepo* sort(Service* s, CountryRepo* res);
int undo(Service* s);
int redo(Service* s);

void test_undo_redo();