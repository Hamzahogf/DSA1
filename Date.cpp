#include "Date.hpp"
#include <iostream>

Date::Date(int m, int d, int y) {
    if (m >= 1 && m <= 12)
        month = m;
    else
        month = 1;

    if (d >= 1 && d <= 31)
        day = d;
    else
        day = 1;

    if (y >= 1)
        year = y;
    else
        year = 1990;
}

void Date::print() const {
    std::cout << month << '-' << day << '-' << year;
}

Date Date::nextDate() const {
    Date nextDate(month, day, year);

    // Determine the number of days in the current month
    int daysInMonth;
    if (month == 2) {
        // February has 28 days in a non-leap year and 29 days in a leap year
        daysInMonth = isLeapYear(nextDate) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // April, June, September, and November have 30 days
        daysInMonth = 30;
    } else {
        // All other months have 31 days
        daysInMonth = 31;
    }

    // Increment the day
    if (day < daysInMonth) {
        nextDate.day++;
    } else {
        nextDate.day = 1;
        // Increment the month
        if (month < 12) {
            nextDate.month++;
        } else {
            nextDate.month = 1;
            // Increment the year
            nextDate.year++;
        }
    }

    return nextDate;
}

bool isLeapYear(const Date& d) {
    int temp = d.year;
    return ((temp % 4 == 0) && (temp % 100 != 0 || temp % 400 == 0));
}
