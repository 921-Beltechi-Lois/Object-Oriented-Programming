#include "DynamicArray.h"
//#include <stdlib.h>
#include <assert.h>
#include "Country.h"
DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct)
{
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    // make sure that the space was allocated
    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    // allocate space for the elements
    da->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    // initialize the function pointer
    da->destroyElemFct = destroyElemFct;  //??TODO  destroyCountry function

    return da;
}

void destroy(DynamicArray* arr)
{
    if (arr == NULL)
        return;

    // deallocate each of the elements - if we decide that the dynamic array is responsible with this
    for (int i = 0; i < arr->length; i++)
        arr->destroyElemFct(arr->elems[i]);  //TODO ;; arr->destroyElemFct = destroyCountry(), destroySmthElse (not just the elements of a Country)
        //destroyCountry(arr->elems[i]);

    // free the space allocated for the elements
    free(arr->elems);
    arr->elems = NULL;

    // free the space allocated for the dynamic array
    free(arr);
    arr = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* arr)
{
    if (arr == NULL)
        return -1;

    arr->capacity *= 2;

    // version 1 - using realloc
    //TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
    //if (aux == NULL)
    //	return - 1;
    //arr->elems = aux;

    // version 2 - allocate new memory, copy everything and deallocate the old memory
    TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
    if (aux == NULL)
        return -1;
    for (int i = 0; i < arr->length; i++)
        aux[i] = arr->elems[i];
    free(arr->elems);     //TODO
    arr->elems = aux;

    return 0;
}


void add_dynamic_array(DynamicArray* arr, TElement p) // Country* p
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    // resize the array, if necessary
    if (arr->length == arr->capacity)
        resize(arr);

    arr->elems[arr->length++] = p;
}

void remove_dynamic_array(DynamicArray* arr, int pos)
{
    if (arr == NULL || pos < 0 || pos >= arr->length)
        return;

    arr->destroyElemFct(arr->elems[pos]);  // TODO??

    // !!! Do this only if we delete any element but the last
    if (pos != arr->length - 1)
        arr->elems[pos] = arr->elems[arr->length - 1];
    arr->length--;

}

void update_dynamic_array(DynamicArray *arr, TElement t, int position)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;
    destroyCountry(arr->elems[position]);
    arr->elems[position]= t;

}

int getLength_dynamic_array(DynamicArray* arr)
{
    if (arr == NULL)
        return -1;

    return arr->length;
}

void setLength_dynamic_array(DynamicArray* arr)
{
    if (arr == NULL)
        return;

    arr->length+=1;
}

TElement get_arr_on_pos(DynamicArray* arr, int pos)
{
    if (arr == NULL || pos < 0)
        return NULL;
    return arr->elems[pos];
}

double getPopulation_from_dyn_arr(DynamicArray* arr, int pos){
    return getPopulation(arr->elems[pos]);
}

char* getName_from_dyn_arr(DynamicArray* arr, int pos){
    return getName(arr->elems[pos]);
}

char* getContinent_from_dyn_arr(DynamicArray* arr, int pos){
    return getContinent(arr->elems[pos]);
}


void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2,destroyCountry);
	if (da == NULL)
		assert(0);

	assert(da->capacity == 2);
	assert(da->length == 0);

	Country* p1 = createCountry("name", "cont", 13.8);
	add_dynamic_array(da, p1);
	assert(da->length == 1);

	Country* p2 = createCountry("name2", "cont2", 450);
	add_dynamic_array(da, p2);
	assert(da->length == 2);

	// capacity must double
	Country* p3 = createCountry("name2", "cont3", 4.2);
	add_dynamic_array(da, p3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	destroy(da);
}