#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream myfile;
    myfile.open("write.txt", ios::out); // write mode
    if (myfile.is_open())
    {
        myfile << "Hello\n";
        myfile << "this is second line";
        myfile.close();
    }
    return 0;
}