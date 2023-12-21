#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
	 private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        Date(string);
        ~Date();
        int getDay();
        int getMonth();
        int getYear();
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        //bool isLeapYear(int);
        //int monthDays(int);
        //void nextDay();
        friend ostream& operator<<(ostream&, const Date&);
        friend int operator-(const Date&, const Date&);
};

#endif