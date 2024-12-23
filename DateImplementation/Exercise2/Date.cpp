#include <iostream>
#include "Date.h"

using namespace std;
//Default Constructor
Date::Date(){
    cout <<"Default Constructor called" << endl;
    day=1;
    month=1;
    year=1926;
    cout << "Date "<< day << "/" << month << "/" << year << endl;
}
