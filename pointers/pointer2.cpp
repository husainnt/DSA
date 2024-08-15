#include <iostream>
using namespace std;
int main()
{
    // int i = 5;
    // int *p = 0;
    // p = &i;
    // cout << "Adress stored in p: " << p << endl;
    // cout << "Value pointed by p: " << *p << endl;
    // return 0;
    int num = 5;
    int a = num;
    a++;
    cout << "num is: " << num << endl;
    int *p = &num;
    cout << "num before: " << num << endl;
    (*p)++;
    cout << "num after: " << num << endl;
    // copying a pointer
    int *q = p;
    cout << "Address in p: " << p << '\t' << "Adress in q: " << q << endl;
    cout << "Value pointed by p: " << *p << '\t' << "Value pointed by q: " << *q << endl;
    // pointer increment
    int i = 9;
    int *t = &i;
    *t = *t + 1;
    cout << (*t)++ << endl;

    return 0;
}