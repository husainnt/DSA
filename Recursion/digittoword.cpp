#include <iostream>
#include <string>

using namespace std;

string digitToWord(int digit)
{
    switch (digit)
    {
    case 0:
        return "zero";
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    case 6:
        return "six";
    case 7:
        return "seven";
    case 8:
        return "eight";
    case 9:
        return "nine";
    default:
        return "";
    }
}

void printNumberInWords(int number)
{
    if (number == 0)
        return;

    printNumberInWords(number / 10);
    cout << digitToWord(number % 10) << " ";
}

int main()
{
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    cout << endl;

    printNumberInWords(number);
    cout << endl;

    return 0;
}
