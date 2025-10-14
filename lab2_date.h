#ifndef LAB2_DATE_H
#define LAB2_DATE_H

// Simple Date class
 class Date {
public:
// Complete the default constructor prototype to initialize
 // the default date to 1/1/1990
    Date(int m = 1, int d = 1, int y = 1990);
 void print();
friend bool isLeapYear(const Date& d); // Declaration of friend function
Date& nextDate(const Date&);
 private:
 int month;
 int day;
 int year;
 };

#endif // LAB2_DATE_H