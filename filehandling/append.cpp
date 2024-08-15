#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream myfile;
    myfile.open("sample.txt", ios::app); // append mode
    if (myfile.is_open())
    {
        myfile << "wriiten in append";
        myfile.close();
    }
    return 0;
}