#include "Country.h"

Country* createCountry(char* name, char* continent, double population){
    Country* p= malloc(sizeof(Country));
    if (p == NULL)
    {
        return NULL;
    }
    p->name = malloc(sizeof(char) * (strlen(name) + 1));
    p->continent = malloc(sizeof(char) * (strlen(continent) + 1));
    if (p->name == NULL || p->continent == NULL)
    {
        return NULL;
    }
    strcpy(p->name, name);
    strcpy(p->continent, continent);
    p->population = population;

    return p;
}

void destroyCountry(Country *p){
    if (p == NULL){
        return;
    }
    free(p->continent);
    free(p->name);
    free(p);
}

char* getName(Country* p){
    if (p == NULL)
        return NULL;
    return p->name;
}

char* getContinent(Country* p)
{
    if (p == NULL)
        return NULL;
    return p->continent;
}

double getPopulation(Country* p)
{
    if(p==NULL)
        return -1;
    return p->population;
}

void toString(Country* p, char str[])
{
    sprintf(str, "Country %s is from continent %s and its country population is %.2lf.", p->name, p->continent, p->population);
}

Country* copyPlanet(Country* p) {
    if (p == NULL)
        return NULL;
    return createCountry(p->name, p->continent, p->population);
}

void testCountry()
{
    Country* c = createCountry("Ukraine", "Europe", 12.5);
    assert(strcmp(c->name, "Ukraine")==0);
    assert(strcmp(c->continent, "Europe")==0);
    assert(c->population==12.5);
    destroyCountry(c);
}