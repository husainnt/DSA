#include <iostream>
#include <string.h>
using namespace std;

class mystring
{
private:
    char arr[100];

public:
    mystring()
    {
        arr[0] = '\0';
    }

    void input();
    void display();

    mystring operator+(mystring s);
    bool operator==(mystring s);
    char operator[](int i);

    friend ostream &operator<<(ostream &os, const mystring &s);
    friend istream &operator>>(istream &is, mystring &s);
};

void mystring::input()
{
    cout << "Enter a string: ";
    cin >> arr;
}

void mystring::display()
{
    cout << "String: " << arr << endl;
}

mystring mystring::operator+(mystring s)
{
    mystring temp;
    strcpy(temp.arr, arr);
    strcat(temp.arr, s.arr);
    return temp;
}

bool mystring::operator==(mystring s)
{
    return strcmp(arr, s.arr) == 0;
}

char mystring::operator[](int i)
{
    if (i >= 0 && i < strlen(arr))
    {
        return arr[i];
    }
    else
    {
        throw out_of_range("Index out of range");
    }
}

ostream &operator<<(ostream &os, const mystring &s)
{
    os << s.arr;
    return os;
}

istream &operator>>(istream &is, mystring &s)
{
    is >> s.arr;
    return is;
}

int main()
{
    mystring str1, str2, str3;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    str3 = str1 + str2;
    cout << "Concatenated string: " << str3 << endl;

    if (str1 == str2)
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        cout << "Strings are not equal" << endl;
    }

    cout << "Character at index 2 in first string: " << str1[2] << endl;

    return 0;
}
