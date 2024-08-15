#include <iostream>
using namespace std;

// Definition of the Count class
class Count
{
private:
    int n; // Private member variable to store the count

public:
    // Constructor to initialize n to 0
    Count()
    {
        n = 0;
    }

    // Function to display the value of n
    void show();

    // Overload the prefix increment operator
    Count operator++();
};

// Implementation of the show function
void Count::show()
{
    cout << "n = " << n << endl;
}

// Implementation of the prefix increment operator
Count Count::operator++()
{
    Count temp;  // Create a temporary Count object
    n = n + 1;   // Increment the member variable n
    temp.n = n;  // Assign the incremented value to the temporary object's n
    return temp; // Return the temporary object
}

int main()
{
    Count x, y; // Create two Count objects, x and y
    x.show();   // Display the initial value of x (should be 0)
    y.show();   // Display the initial value of y (should be 0)
    y = ++x;    // Increment x using the prefix operator and assign the result to y
    x.show();   // Display the value of x after incrementing (should be 1)
    y.show();   // Display the value of y after assignment (should be 1)
    return 0;   // Exit the program
}
