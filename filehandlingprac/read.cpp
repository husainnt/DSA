#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("file1.txt");
    if (infile.fail()) // check for a successful open
    {
        cout << "\nThe file was not successfully opened"
             << "\n Please check that the file currently exists."
             << endl;
        exit(1);
    }
    cout << "\nThe file has been successfully opened for reading."
         << endl;
    // statements to read data from the file would be placed here
    return 0;
}
