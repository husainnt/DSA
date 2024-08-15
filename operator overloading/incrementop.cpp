#include <iostream>
using namespace std;

class Count
{
private:
    int n;

public:
    Count()
    {
        n = 0;
    }
    void show();
    void operator++(); // Prefix increment operator
};

void Count::show()
{
    cout << "n = " << n << endl;
}

// Definition of the prefix increment operator
void Count::operator++()
{
    n = n + 1;
}

int main()
{
    Count obj;
    obj.show();
    ++obj; // Calls the prefix increment operator
    obj.show();
}
