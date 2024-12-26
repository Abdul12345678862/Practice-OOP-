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

    //~Date();

    void inputDate();

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Getter Functions
    int getDay();
    int getMonth();
    int getYear();

    int Compare(Date rhs,Date lhs);

    int IncrementMonth();
};

#endif