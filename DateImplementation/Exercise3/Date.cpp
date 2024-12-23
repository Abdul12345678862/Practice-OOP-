#include <iostream>
#include "Date.h"

using namespace std;
//Default Constructor
Date::Date(){
    cout <<"Default Constructor called" << endl;
    day=1;
    month=1;
    year=1926;
}

//Parameterized Constructor
Date::Date(int d, int m,int y){
    cout <<"Parametrized Constructor called" << endl;
    day=d;
    month=m;
    year = y;
}

//function to print the date
void Date::printDate(){
    cout << "Date "<< day << "/" << month << "/" << year << endl;
}