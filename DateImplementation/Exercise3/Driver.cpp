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

    return 0;
}
