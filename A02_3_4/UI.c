#include "UI.h"
//#include <stdio.h>
//#include <stdlib.h>


int undoUI(UI *ui);

int redoUI(UI *ui);

UI* createUI(Service* s)
{
    UI* ui = malloc(sizeof(UI));
    if (ui == NULL)
        return NULL;
    ui->serv = s;

    return ui;
}

void destroyUI(UI * ui)
{
    if (ui == NULL)
        return;

    // first destroy the Service
    destroyService(ui->serv);
    // free the UI memory
    free(ui);
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
*/
void printMenu()
{
    printf("\n**********************************************************\n");
    printf("1 - add a country.\n");
    printf("2 - list all countries.\n");
    printf("3 - list / filter countries by a given type (name or continent)\n");
    printf("4 - remove a country.\n");
    printf("5 - update a country.\n");
    printf("6 - undo.\n");
    printf("7 - redo.\n");
    printf("0 - to exit.\n");
    printf("**********************************************************\n");
}

/*
	Verifies if the given command is valid (is either 1, 2 or 0)
	Input: command - integer
	Output: 1 - if the command is valid
	0 - otherwise
*/
int validCommand(int command)
{
    if (command >= 0 && command <= 7)
        return 1;
    return 0;
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
    char s[16] = { 0 };
    int res = 0;
    int flag = 0;
    int r = 0;

    while (flag == 0)
    {
        printf(message);
        int scanf_result = scanf("%15s", s);

        r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
        flag = (r == 1);
        if (flag == 0)
            printf("Error reading number!\n");
    }
    return res;
}

int addCountryUI(UI* ui)
{
    // read the country's data
    char name[50], continent[50];
    double population = 0;

    printf("Please input the name: ");
    int scanf_result = scanf("%49s", name);
    printf("Please input the continent: ");
    scanf_result = scanf("%49s", continent);
    printf("Please input the population from the above country (stored in millions): ");
    scanf_result = scanf("%lf", &population);

    return addCountry(ui->serv, name, continent, population);
}

void listAllCountries(UI* ui)
{
    if (ui == NULL)
        return;
    CountryRepo* repo = getRepo(ui->serv);
    if (repo == NULL)
        return;

    for (int i = 0; i < getLength(repo); i++)
    {
        Country* country = getCountryOnPos(repo, i);
        char planetString[200];
        toString(country, planetString);
        printf("%s\n", planetString);
    }
}

void listCountriesByType(UI* ui)
{
    printf("1.List by Country (name) ~ list countries with a given 'name'(or substring) \n 2.List by Continent ~ display all countries of a given continent, > given population, sorted asc\n");
    printf("Input option 1 or option 2:\n ");
    //scanf("%d", option);
    int option = readIntegerNumber("Input option: ");

    char symbols[50];
    double given_population = 0;

    if (option ==1){
        printf("Please input the desired name of the country; input 'null' for all country names: ");
        int scanf_result = scanf("%49s", symbols);
    }

    else{
        printf("Please input the desired name of the CONTINENT; input 'null' for all continent names: ");
        int scanf_result = scanf("%49s", symbols);
        printf("sorting the array > no. of given_population: ");
        //scanf("%lf", given_population);
        scanf_result = scanf("%lf", &given_population);
    }

    CountryRepo* res = filter(ui->serv, symbols,option,given_population);

    if(res->countries->length ==0){
        listAllCountries(ui);
    }
    else if(option==2){
        res=sort(ui->serv, res);
    }

    for (int i = 0; i < getLength(res); i++)
    {
        Country* country = getCountryOnPos(res, i);
        char planetString[200];
        toString(country, planetString);
        printf("%s\n", planetString);
        //destroyCountry(country);
    }

    // now we must destroy the repository that was created for this operation
    destroyRepo(res);    // TODO, mem leak

    //free(res);
}

int removeCountryUI(UI *ui) {
    char name[50];
    printf("Please input the name of the country to be deleted: ");
    int scanf_result = scanf("%49s", name);
    return removeCountry(ui->serv, name);
}

int updateCountryUI(UI *ui) {
    char name[50];
    double given_population;
    printf("Option 1: update a country, option 2: migrate population from a country to another\n");
    int option = readIntegerNumber("Input option: ");
    switch(option){
        case 1:
        {
            printf("Please input the name of the country to be updated: ");
            int scanf_result = scanf("%49s", name);
            printf("Please input the quantity of the country's population to be updated:\n ");
            scanf_result = scanf("%lf", &given_population);   // ?
            return updateCountry(ui->serv, name, given_population, option);
        }
        case 2:
        {
            printf("Please input the name of the country from which the migration will take place: ");
            int scanf_result = scanf("%49s", name);
            printf("Please input the quantity of the population that will leave the selected country: ");
            scanf_result = scanf("%lf", &given_population);   // ?
            int res = updateCountry(ui->serv, name, given_population, option);

            if (res==1) {
                printf("Please input the name of the country in which no. of population from above will move into: ");
                scanf_result = scanf("%49s", name);
                return updateCountry(ui->serv, name, -given_population, option);
            }
        }
        default:
            break;
    }
}

void startUI(UI* ui)
{
    while (1)
    {
        printMenu();
        int command = readIntegerNumber("Input command: ");
        while (validCommand(command) == 0)
        {
            printf("Please input a valid command!\n");
            command = readIntegerNumber("Input command: ");
        }
        if (command == 0){
            break;
        }

        switch (command)
        {
            case 1:
            {
                int res = addCountryUI(ui);
                if (res == 1)
                    printf("Country successfully added.\n");
                else
                    printf("Error! Country could not be added, as there is another Country with the same name!\n");
                break;
            }
            case 2:
            {
                listAllCountries(ui);
                break;
            }
            case 3:
            {
                listCountriesByType(ui);
                break;
            }
            case 4:
            {
                int res= removeCountryUI(ui);
                if (res == 1)
                    printf("Country successfully deleted.\n");
                else
                    printf("Error! Country could not be deleted, as there isn't such a country with the same name!\n");
                break;
            }
            case 5:
            {
                int res= updateCountryUI(ui);
                if (res == 1)
                    printf("Country successfully updated.\n");
                else
                    printf("Error! Country could not be updated, as there isn't such a country with the same name!\n");
                break;
            }
            case 6:
            {
                int res = undoUI(ui);
                // check res and print message accordingly
                if (res == 0)
                    printf("Undo successful");
                else
                    printf("undo failed");
                break;
            }
            case 7:
            {
                int res = redoUI(ui);
                // check res and print message accordingly
                if (res == 0)
                    printf("redo successful");
                else{
                    printf("redo failed");
                }
                break;
            }
            default:
                break;

        }
    }
}

int redoUI(UI *ui) {
    return redo(ui->serv);
}

int undoUI(UI *ui) {
    return undo(ui->serv);
}


