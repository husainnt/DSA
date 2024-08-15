#include <iostream>  // Include the input-output stream library
#include <stack>     // Include the stack library
using namespace std; // Use the standard namespace

int main()
{
    string str = "hussain"; // Initialize the string to be reversed
    stack<char> s;          // Declare a stack to store characters

    // Push all characters of the string onto the stack
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i]; // Get the current character from the string
        s.push(ch);       // Push the character onto the stack
    }

    string ans = ""; // Initialize an empty string to store the reversed string

    // Pop all characters from the stack and append them to the answer string
    while (!s.empty())
    {
        char ch = s.top(); // Get the character on the top of the stack
        ans.push_back(ch); // Append the character to the answer string
        s.pop();           // Remove the character from the stack
    }

    // Output the reversed string
    cout << "Reversed string is: " << ans << endl;

    return 0; // Return 0 to indicate successful execution
}
