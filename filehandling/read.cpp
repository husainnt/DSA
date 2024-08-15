#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
    fstream myfile;
    myfile.open("sample.txt", ios::in); // aread mode
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }

    return 0;
}