#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char choice;
    do {
        char name[20];
        int id;
        float grade;
        char delim = '$';

        cout << "Enter Student Name (up to 20 chars): ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Student Grade: ";
        cin >> grade;

        outFile << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    return 0;
}
