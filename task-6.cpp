#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    string filename = "grades.txt";
    string tempFilename = "temp.txt";

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    int initialGrades[5] = {85, 90, 78, 92, 88};
    for (int i = 0; i < 5; i++) {
        outFile << initialGrades[i] << endl;
    }
    outFile.close();
    cout << "1. File 'grades.txt' created successfully with 5 grades.\n" << endl;

    cout << "2. --- Current Grades in File ---" << endl;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();
    cout << "------------------------------------\n" << endl;

    int gradeToDelete;
    cout << "3. Enter the grade you want to delete: ";
    cin >> gradeToDelete;

    ifstream inFileRead(filename);
    ofstream tempFile(tempFilename);

    if (!inFileRead || !tempFile) {
        cout << "Error opening files for processing!" << endl;
        return 1;
    }

    bool found = false;
    while (inFileRead >> grade) {
        if (grade == gradeToDelete) {
            found = true;
            continue; 
        }
        tempFile << grade << endl;
    }

    inFileRead.close();
    tempFile.close();

    if (found) {
        remove(filename.c_str());
        rename(tempFilename.c_str(), filename.c_str());
        cout << "\n4. [Success] Grade deleted and original file replaced successfully!" << endl;
    } else {
        remove(tempFilename.c_str());
        cout << "\n4. [Error] Grade not found in the file!" << endl;
    }

    return 0;
}
