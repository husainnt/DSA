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

    // Overload the postfix increment operator
    Count operator++(int);
};

// Implementation of the show function
void Count::show()
{
    cout << "n = " << n << endl;
}

// Implementation of the postfix increment operator
Count Count::operator++(int)
{
    Count temp;  // Create a temporary Count object
    n = n + 1;   // Increment the member variable n
    temp.n = n;  // Assign the incremented value to the temporary object's n
    return temp; // Return the temporary object
}

int main()
{
    Count x, y;
    x.show();
    x++;
    x.show();
    y = x++;
    y.show();
    return 0;
}
