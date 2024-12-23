#include <iostream>
#include "Date.h"

using namespace std;

int main(){
    //Create a object using a default Constructor
    Date date1;
    date1.printDate();

    //Create an object using parametrized constructor
    Date date2(23,12,2024);
    date2.printDate();

    //Independance day object date print
    Date independenceDay(14,8,1947);
    independenceDay.printDate();

    Date date3;
    date3.inputDate();
    date3.printDate();

    Date xmasDay;
    xmasDay.printDate();

    cout<<"After Setter Functions of Date Month And Year The default constructor date values override"<<endl;
    xmasDay.setDay(25);
    xmasDay.setMonth(12);
    xmasDay.setYear(2018);
    xmasDay.printDate();

    return 0;
}
