#include "Country.h"
//#include <crtdbg.h>
#include <stdio.h>
#include "UI.h"
#include "CountryRepository.h"

int main()
{

    testCountry();
    testsCountryRepo();
    test_undo_redo();
    testsDynamicArray();
//    Country* p = createCountry("France", "Europe", 1000000);
//    char* name = getName(p);
//    printf("%s", name);
    CountryRepo* repo = createRepo();
    Service* serv = createService(repo);

    addCountry(serv, "France", "Europe", 13.8);
    addCountry(serv, "Hungary", "Europe", 20);
    addCountry(serv, "Zambia", "Africa", 4.2);
    addCountry(serv, "Brazil", "South America", 111);
    addCountry(serv, "Romania", "Europe", 5);

//    updateCountry(serv, "Romania", 2, 2);
//    updateCountry(serv, "Brazil", -2, 2);

    UI* ui = createUI(serv);

    startUI(ui);

    destroyUI(ui);
    //_CrtDumpMemoryLeaks();

}