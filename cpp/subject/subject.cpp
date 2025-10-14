#include <iostream>
using namespace std;

int main() {
    int marks[5];
    int totalMarks = 0;

    // Input marks for 5 subjects
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
        totalMarks += marks[i];
    }

    // Calculate average and percentage
    double average = static_cast<double>(totalMarks) / 5;
    double percentage = (static_cast<double>(totalMarks) / (5 * 100)) * 100;

    // Display results
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Percentage Scored: " << percentage << "%" << endl;

    return 0;
}