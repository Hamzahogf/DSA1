#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;
    bool isLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    int daysInMonth(int month, int year) {
        switch(month) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return (isLeapYear(year) ? 29 : 28);
            default:
                return 31;
        }
    }
public:
    Date(int m, int d, int y) {
        if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y) || y < 0) {
            std::cerr << "Invalid date values!" << std::endl;
            exit(1);
        }
        month = m;
        day = d;
        year = y;
    }

    void nextDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void printDate() {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
};

int main() {
    // Test cases
    Date date1(2, 28, 2024);
    Date date2(12, 31, 2023);
    
    std::cout << "Initial date: ";
    date1.printDate();
    std::cout << "Next days: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        date1.nextDay();
        date1.printDate();
    }
    
    std::cout << "Initial date: ";
    date2.printDate();
    std::cout << "Next days: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        date2.nextDay();
        date2.printDate();
    }

    return 0;
}
