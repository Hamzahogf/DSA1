#include <iostream>
#include <string>

const int MAX_CONTACTS = 5;

struct Contact {
    std::string lastName;
    std::string firstName;
    std::string phoneNumbers[3];
    std::string birthDate;
    struct Address {
        std::string street;
        std::string city;
        std::string postalCode;
    } address;
};

int main() {
    Contact contacts[MAX_CONTACTS];

    for (int i = 0; i < MAX_CONTACTS; ++i) {

        std::cin >> contacts[i].lastName;

        std::cin >> contacts[i].firstName;

        for (int j = 0; j < 3; ++j) {
            std::cout << "Phone Number " << j + 1 << ": ";
            std::cin >> contacts[i].phoneNumbers[j];
        }

        std::cin >> contacts[i].birthDate;

        std::cin.ignore();  // Ignore newline character from previous input
        std::getline(std::cin, contacts[i].address.street);
        std::getline(std::cin, contacts[i].address.city);
        std::cin >> contacts[i].address.postalCode;

    }


    return 0;
}