#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class Cat {
private:
    std::string furColor;
    std::string eyeColor;
    std::string hairLength;

public:
    Cat() {
        static const char* furColors[] = {"black", "grey", "brown"};
        static const char* eyeColors[] = {"green", "blue", "brown"};
        static const char* hairLengths[] = {"short", "long"};

        furColor = furColors[rand() % 3];
        eyeColor = eyeColors[rand() % 3];
        hairLength = hairLengths[rand() % 2];
    }

    // Getters
    std::string getFurColor() const {
        return furColor;
    }

    std::string getEyeColor() const {
        return eyeColor;
    }

    std::string getHairLength() const {
        return hairLength;
    }

    // Function to print cat attributes
    void printAttributes() const {
        std::cout << "Cat attributes: Fur color: " << furColor << ", Eye color: " << eyeColor << ", Hair length: " << hairLength << std::endl;
    }
};

bool check(const Cat* cats, int size) {
    int blackCount = 0;
    int greyCount = 0;
    int greenCount = 0;
    int blueCount = 0;
    int brownCount = 0;

    for (int i = 0; i < size; ++i) {
        if (cats[i].getFurColor() == "black") {
            blackCount++;
        } else if (cats[i].getFurColor() == "grey") {
            greyCount++;
        }
        
        if (cats[i].getEyeColor() == "green") {
            greenCount++;
        } else if (cats[i].getEyeColor() == "blue") {
            blueCount++;
        } else if (cats[i].getEyeColor() == "brown") {
            brownCount++;
        }
    }

    // Conditions for a fight
    if ((greyCount > 0 && brownCount > 0) || (blackCount > 1 && greenCount > 0 && blueCount > 0 && brownCount > 0)) {
        return true;
    }

    return false;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int roomCapacity = 7;
    Cat* room = new Cat[roomCapacity];

    char key;
    int catsCount = 0;
    do {
        std::cout << "Press Enter to add a cat, or 'q' to quit: ";
        std::cin.get(key);
        if (key == '\n') {
            if (catsCount < roomCapacity) {
                catsCount++;
                room[catsCount - 1].printAttributes();
                if (check(room, catsCount)) {
                   std::cout << "A fight has broken out!" << std::endl;
      } else {
                    std::cout << "Cat added to the room." << std::endl;
                }
            } else {
                std::cout << "Room is full, cannot add more cats!" << std::endl;
            }
        }
    } while (key != 'q');

    delete[] room;
    return 0;
}
