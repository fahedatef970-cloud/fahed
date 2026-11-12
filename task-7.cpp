#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Define the vector containing the names
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    // Sort the names in ascending order (A to Z)
    sort(names.begin(), names.end());

    // Print the sorted names
    cout << "Sorted Names (Ascending Order):" << endl;
    for (const string& name : names) {
        cout << name << endl;
    }

    return 0;
}
