#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string mydata;
    ifstream file1("read.txt");
    getline(file1, mydata);
    cout << mydata;
    return 0;
}