#include "CountryRepository.h"



CountryRepo* createRepo()
{
    // old: Country* arr[100], int size;  allocating size for the struct & setting size to 0 only

//    CountryRepo* v = malloc(sizeof(CountryRepo));
//    if(v==NULL)
//        return NULL;
//    v->size=0;
//    return v;
    CountryRepo* v = (CountryRepo*)malloc(sizeof(CountryRepo));
    if (v == NULL)
        return NULL;
    v->countries = createDynamicArray(CAPACITY, &destroyCountry);

    return v;
}
void destroyRepo(CountryRepo* v)
{
    /// old: Country* arr[100], int size;  free(each country) of the array (statically allocated), and then for v (the structure)
//    if(v==NULL)
//        return;
//    for(int i=0; i< v->size;i++)
//        destroyCountry(v->arr[i]); //free all countries that have been created and added to repo (from service eg)
//    free(v);

// !!! If the dynamic vector takes responsibility of these planets, then the memory can be deallocated in the function "destroy" in DynamicArray.c.
    // Otherwise, the repository should deallocate the memory for the planets.
    /*for (int i = 0; i < getLength(v->planets); i++)
    {
        Planet* p = get(v->planets, i);
        destroyPlanet(p);
    }*/                  // before!

    if (v==NULL)
        return;

    // then destroy the dynamic array
    destroy(v->countries);
    free(v);
}

int find(CountryRepo* v, char* name) {
    // find or search for a given name in the CountryRepo; RETURN position of it if found, otherwise -1
    char p[30];
    for (int i = 0; i < v->countries->length; i++) {
        //char* p =getName(v->arr[i]);
        strcpy(p, getName(v->countries->elems[i]));
        if (strcmp(p, name) == 0) {
            return i;                           // there is such a country, return position
        }
    }
    return -1;                                  // name is unique
}

CountryRepo* find_name(CountryRepo* v, CountryRepo* res, char name[]){
    // We'll go through the initial Repo and if the substring matches the name, we'll save a copy in the new REPO
    // return : the filtered new repo or an empty repo (if there isn't such a substring)
    char p[30];
    char* ret;                  // v->size
    for (int i = 0; i < v->countries->length; i++) {
        //strcpy(p, getName(v->arr[i]));
        strcpy(p, getName(v->countries->elems[i]));
        ret=strstr(p,name);
        if (ret!=NULL){
            //res->arr[res->size++]= v->arr[i];
            int size = getLength_dynamic_array(res->countries);
            res->countries->elems[size] = copyPlanet(v->countries->elems[i]);
            setLength_dynamic_array(res->countries);
        }
    }
    return res;
}
CountryRepo* find_continent(CountryRepo* v, CountryRepo* res, char name[], double given_value_of_population){
    // We'll go through the initial Repo and if the substring matches the name, we'll save a copy in the new REPO
    // return : the filtered new repo or an empty repo (if there isn't such a substring)
    char p[30];
    char* ret;                  // v->size
    for (int i = 0; i < v->countries->length; i++) {
        //strcpy(p, getName(v->arr[i]));
        strcpy(p, getContinent(v->countries->elems[i]));
        ret=strstr(p,name);
        if (ret!=NULL && getPopulation(v->countries->elems[i])> given_value_of_population || strcmp(name, "null")==0 && getPopulation(v->countries->elems[i])> given_value_of_population){
            //res->arr[res->size++]= v->arr[i];
            int size = getLength_dynamic_array(res->countries);
            res->countries->elems[size] = copyPlanet(v->countries->elems[i]);
            setLength_dynamic_array(res->countries);
        }
    }
    return res;
}

int add(CountryRepo* v, Country* p)
{
    // function 'find'/ search returns the position of the given Object from the CountryRepo, otherwise -1 (name is unique)
    // finally add function will return 1 if add was succesfully done, otherwise 0

//    int val = find(v, p->name);
//    if (val==-1) {
//        v->arr[v->size++] = p;
//        return 1;
//    }
//    return 0;

    int val = find(v, p->name);
    if (val==-1){
        add_dynamic_array(v->countries, p);
        return 1;
    }
    return 0;
}

int removeCountryRepo(CountryRepo* v, char country_name[])
{
    // we remove the element by moving its value to the end of the array and then subtract the length of the array
    // function 'find' returns the index of the country, otherwise -1 (remove failed)
    int val = find(v, country_name);
    if (val!=-1) {
//        v->arr[val]=v->arr[v->size-1];
//        v->size--;
        remove_dynamic_array(v->countries, val);
        return 1;
    }
    return 0;
}

int update(CountryRepo* v, char name[], double quantity, int option)
{
    // 'Find' returns the index of the given Country in order to be updated, otherwise -1
    // option 1 only updates the direct value of the population, option 2 updates migration from a country to other
    // quantity < 0, it is the country that will receive the new population
    // return : true if update has been done

    int val = find(v, name);
    Country* c=NULL;
    if (val!=-1) {
        char continent[30];
        strcpy(continent, getContinent(v->countries->elems[val]));

        if (option==1) {
            c = createCountry(name, continent, quantity);
            //v->arr[val]->population = quantity;
            update_dynamic_array(v->countries, c, val);
            //destroyCountry(c); TODO?
        }
        else{
            //double population = v->arr[val]->population;
            double population = getPopulation(v->countries->elems[val]);
            double new_population;
            if (quantity < 0){
                //v->arr[val]->population = population + fabs(quantity);
                new_population = population+fabs(quantity);
            }
            else { // First Country
                //v->arr[val]->population = population - quantity;
                new_population = population - quantity;
            }
            c = createCountry(name, continent, new_population);
            update_dynamic_array(v->countries, c, val);

        }
        //destroyCountry(c);
        return 1;
    }
    return 0;
}

int getLength(CountryRepo* v)
{
    //return v->size;
    return getLength_dynamic_array(v->countries);
}

Country* getCountryOnPos(CountryRepo* v, int pos)
{
    if (v == NULL)
        return NULL;            // v->size
    if (pos < 0 || pos >= v->countries->length)
        return NULL;
    //return v->arr[pos];
    Country* return_country = get_arr_on_pos(v->countries, pos);
//    char* name = getName_from_dyn_arr(v->countries, pos);
//    char* continent = getContinent_from_dyn_arr(v->countries, pos);
//    double pop = getPopulation_from_dyn_arr(v->countries, pos);
//    Country* return_country = createCountry(name, continent, pop);

    return return_country;
}

Country* findByName(CountryRepo* repo, char* name) {
    if (repo == NULL || name == NULL) {
        return NULL;
    }

    for (int i = 0; i < getLength_dynamic_array(repo->countries); i++) {
        Country * p = get_arr_on_pos(repo->countries, i);
        if (strcmp(getName(p), name) == 0) {
            return p;
        }
    }

    return NULL;
}

void testAdd_Remove_Update()
{
    CountryRepo* v = createRepo();

    //todo ADD
    Country* p1 = createCountry("Ukraine", "Europe", 13.8);
    add(v, p1);
    assert(getLength(v) == 1);
    assert(strcmp(getName(getCountryOnPos(v, 0)), "Ukraine") == 0);

    Country* p2 = createCountry("Argentina", "South America", 450);
    assert(add(v, p2) == 1);
    assert(getLength(v) == 2);

    // now try to add the same planet again -> add must return 0
    assert(add(v, p2) == 0);


//    //todo update
//    update(v, getName(p1), 500, 1);
//    double population = getPopulation_from_dyn_arr(v->countries, 0);
//    assert(population== 500);
//
//    //todo remove
//    //Country* save = p1;
//    removeCountryRepo(v,getName(p1));
//    assert(getLength(v)== 1);
//    assert(strcmp(getName(getCountryOnPos(v, 0)), "Ukraine") != 0); //country does not exist anymore


//    add(v, p1);

    // destroy the test repository
    destroyRepo(v);

    // Option 1:
    // if the repository does not store copies, then the memory allocated for the planets will be deallocated
    // in the repository and the two planets should not be deallocated here.

    // Option 2:
    // otherwise, if the repository makes copied, then the memory allocated for the planets must be freed
    /*destroyPlanet(p1);
    destroyPlanet(p2);*/
}
void testUpdate(){
    CountryRepo* v = createRepo();
    //todo update
    Country* p1 = createCountry("Ukraine", "Europe", 13.8);
    add(v, p1);
    update(v, getName(p1), 500, 1);
    double population = getPopulation_from_dyn_arr(v->countries, 0);
    assert(population== 500);
    destroyRepo(v);
}

void testRemove()
{
    CountryRepo* repos = createRepo();
        //todo remove
    Country* p1 = createCountry("Ukraine", "Europe", 13.8);
    Country* save = copyPlanet(p1);
    add(repos, p1);
    removeCountryRepo(repos, getName(p1));
    assert(getLength(repos) == 0);
    //assert(strcmp(getName(getCountryOnPos(repos, 0)), "Ukraine") != 0); //country does not exist anymore
    add(repos, save);
    destroyRepo(repos);
}

void testsCountryRepo()
{

    testAdd_Remove_Update();
    testUpdate();
    testRemove();
}