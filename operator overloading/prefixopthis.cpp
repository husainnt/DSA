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
    Count &operator++(); // Prefix increment operator
};

void Count::show()
{
    cout << "n = " << n << endl;
}

// Definition of the prefix increment operator
Count &Count::operator++()
{
    n = n + 1;
    return *this;
}

int main()
{
    Count x, y;
    x.show();
    y.show();
    y = ++x;
    x.show();
    y.show();
    return 0;
}
