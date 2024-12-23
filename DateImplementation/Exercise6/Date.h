#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

public:
    //Default Constructor
    Date();

    //Parametrized Constructor
    Date(int d, int m, int y);

    //Function to print the date
    void printDate();

    ~Date();

    void inputDate();
};

#endif