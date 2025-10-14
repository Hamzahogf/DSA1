#include "lab2_date.h"
 #include <iostream>
 using namespace std;


bool isLeapYear(const Date& d) {
    int temp = d.year;
    if (temp % 4 == 0) {
        if (temp % 100 != 0 || (temp % 100 == 0 && temp % 400 == 0)) {
            return true;
        }
    }
    return false;
}
 Date::Date( int m=1, int d=1, int y=1990 ) {
 do
 {
    cout<<"-re-enter the values ";
    month=m;
    day=d;
    year=y; 
 } while (m<0 || d<0 || y<0);

  }

 void Date::print() {
 cout << month << '-' << day << '-' << year;
 }

 // Add the implementation of the missing member functions
Date& Date::nextDate(const Date& d) {
    
    if (((month==1|| month==3|| month==5 || month ==7|| month==8|| month ==10) && day==31) || ((month==4|| month==6|| month==9 || month ==11) && day==30)  || (month == 2 && isLeapYear(d) && day == 29) &&  (month == 2 && !isLeapYear(d) && day == 28)  )
    {
        month =d.month+1;
        day=1;
        year=d.year;
    } else if (month==12 || day==31)
    {
        month=1;
        year=d.year+1;
        day=1;
    } else 
    { 
        month=d.month;
        year=d.year;
        day=d.day;
    }
    
    
    return *this;
}