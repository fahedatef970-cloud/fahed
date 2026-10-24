#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cin >> n;

    ofstream outFile("persons.txt");

    for (int i = 0; i < n; i++) {
        Person p;
        getline(cin >> ws, p.name);
        cin >> p.age;

        outFile << p.name << '\n';
        outFile << p.age << '\n';
    }

    outFile.close();

    vector<Person> persons;
    ifstream inFile("persons.txt");

    Person p;
    while (getline(inFile, p.name)) {
        if (!(inFile >> p.age))
            break;

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        persons.push_back(p);
    }

    inFile.close();

    if (persons.empty())
        return 0;

    int youngest = persons[0].age;
    int oldest = persons[0].age;

    for (const Person& person : persons) {
        if (person.age < youngest)
            youngest = person.age;

        if (person.age > oldest)
            oldest = person.age;
    }

    ofstream resultFile("results.txt");

    resultFile << "Youngest person(s):\n";

    for (const Person& person : persons) {
        if (person.age == youngest) {
            resultFile << "Name: " << person.name
                       << ", Age: " << person.age << '\n';
        }
    }

    resultFile << "\nOldest person(s):\n";

    for (const Person& person : persons) {
        if (person.age == oldest) {
            resultFile << "Name: " << person.name
                       << ", Age: " << person.age << '\n';
        }
    }

    resultFile.close();

    return 0;
}
