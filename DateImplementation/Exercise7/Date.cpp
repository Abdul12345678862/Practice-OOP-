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
void Date::inputDate(){
    int d, m, y;
    cout<<"Enter Date in integer 01-30"<<endl;
    cin >> d ;
    cout<<"Enter month in integer 01-12"<<endl;
    cin >> m ;
    cout<<"Enter year in integer i.e:2024"<<endl;
    cin >> y ;
    day=d;
    month=m;
    year=y;
}

//function to print the date
void Date::printDate(){
    cout << "Date "<< day << "/" << month << "/" << year << endl;
}

Date::~Date(){
    cout << "Destructor Called" << endl;
}

void Date::setDay(int d){
    day=d;    
}

void Date::setMonth(int m){
    month = m;    
}

void Date::setYear(int y){
    year = y;    
}
