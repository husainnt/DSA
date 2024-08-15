#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    cout << num << endl;
    cout << "Adress of num: " << &num << endl; // address of num
    int *ptr = &num;                           // declaring pointer of type num
    cout << "adress is: " << ptr << endl;
    cout << "value is: " << *ptr << endl;
    double d = 4.3;
    double *ptr2 = &d;
    cout << "adress stored in ptr2 is: " << ptr2 << endl;
    cout << "value is: " << *ptr2 << endl;
    cout << "Size of integer  is: " << sizeof(num) << endl;
    cout << "Size of double is: " << sizeof(d) << endl;
    cout << "Size of int ptr is: " << sizeof(ptr) << endl;
    cout << "Size of double ptr is: " << sizeof(ptr2) << endl;

    return 0;
}