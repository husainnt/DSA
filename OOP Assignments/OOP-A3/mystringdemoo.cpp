#include <iostream>
#include <cstring>
#include "myString.h"

using namespace std;



int main ()
{

    myString str1, str2;       // default constructor
    cout<<"Enter first string: ";
    cin>>str1;              // >> oper overloaded
    cout<<"Enter second string: ";
    cin>> str2;

    cout<<endl<<"Individual elements of str1 are\n";
    for(int i=0;i<str1.length();i++)
        cout<<"str1["<<i<<"]= "<<str1[i]<<endl;         // [ ] operator overloaded

    if(str1 == str2)                       // == operator overloaded
        cout<<"\nTwo strings are equal\n";
    else
        cout<<"\nTwo strings are not equal\n";

    if(str1 < str2)
        cout<<"\nfirst string is smaller than second string\n";
    else
        cout<<"\nfirst string is NOT smaller than second string\n";

    myString str3;                //default constructor needed
    int  len ;

    str3 = str1;                //assig oper overloaded in case of dynamic memory
    cout << "str3 : " << str3 << endl;      // << oper overloaded

    str3 = str1 + str2;         // + operator overloaded
    cout << "str1 + str2 : " << str3 << endl;

    len = str3.length();                // length function needed
    cout << "str3.length() :  " << len << endl;

    return 0;
}
