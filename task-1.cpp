#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    int id;
    float grade;

    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    if (file.is_open()) {
        file << "Full Name: " << name << endl;
        file << "ID: " << id << endl;
        file << "Grade: " << grade << endl;
        file.close();

        cout << "Student data saved successfully!" << endl;
    } else {
        cout << "Error creating file!" << endl;
    }

    return 0;
}