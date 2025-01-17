#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(const string &str)
{
    stack<char> charStack;

    // Push all characters of the string onto the stack
    for (char ch : str)
    {
        charStack.push(ch);
    }

    // Pop from the stack and compare with the original string
    for (char ch : str)
    {
        if (ch != charStack.top())
        {
            return false; // If any character doesn't match, it's not a palindrome
        }
        charStack.pop();
    }

    return true; // If all characters matched, it is a palindrome
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Use getline to include spaces in the input

    if (isPalindrome(input))
    {
        cout << "\"" << input << "\" is a palindrome." << endl;
    }
    else
    {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
