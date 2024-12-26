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
    cout<<"Enter Day in integer 01-30"<<endl;
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

// Date::~Date(){
//     cout << "Destructor Called" << endl;
// }

void Date::setDay(int d){
    day=d;    
}

void Date::setMonth(int m){
    month = m;    
}

void Date::setYear(int y){
    year = y;    
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::Compare(Date rhs,Date lhs){
    if(lhs.year>rhs.year){
        return 1;
    }
    else if(lhs.year<rhs.year){
        return -1;
    }
    else{
        if(lhs.month>rhs.month){
        return 1;
    }
    else if(lhs.month<rhs.month){
        return -1;
    }
    else{
        if(lhs.day>rhs.day){
        return 1;
    }
    else if(lhs.day<rhs.day){
        return -1;
    }
    else{
        return 0;
    }
    }
    }  
}

int Date::IncrementMonth() {
    month++;  // Increment the month

    if (month > 12) {  // If the month exceeds December
        month = 1;     // Reset to January
        year++;        // Increment the year
    }

    return month;
}