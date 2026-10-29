#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string text = "Hello Everybody";

    ofstream outFile("welcome.txt");
    outFile << text;
    outFile.close();

    size_t pos = text.find("body");
    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    ofstream file("welcome.txt");
    file << text;
    file.close();

    cout << text << endl;

    return 0;
}
