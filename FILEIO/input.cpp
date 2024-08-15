#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file1("testing.txt");
    file1 << "my name is hussain" << endl;
    file1 << "intro to file handling" << endl;
    file1.close();
    return 0;
}