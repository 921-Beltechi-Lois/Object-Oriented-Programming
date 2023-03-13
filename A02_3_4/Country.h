#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
    char* name;
    char* continent;
    double population;
}Country;


/*
* Creates a new Planet and returns a pointer to it.
* Input: - name - array of characters
*		 - type - array of characters
*		 - dist - double
* Output: p - pointer to the created planet
*/
Country* createCountry(char* name, char* continent, double population);


/*
* Deallocates the memory occupied by the given planet.
* Input: p - pointer to planet
* Output: - deallocation
*/
void destroyCountry(Country* p);

char* getName(Country* p);
char* getContinent(Country* p);
double getPopulation(Country* p);

void toString(Country* p, char str[]);

Country* copyPlanet(Country* p);

void testCountry();

