#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int m = 1, int d = 1, int y = 1990);
    void print() const;
    friend bool isLeapYear(const Date& d); 
    Date nextDate() const;
private:
    int month;
    int day;
    int year;
};

#endif
