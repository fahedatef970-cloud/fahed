#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile("fruit.txt");
    string line;

    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);
    outFile << "\nFresh Fruits";
    outFile.close();

    cout << "Fresh Fruits added successfully." << endl;

    return 0;
}
