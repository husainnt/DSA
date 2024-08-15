#include <iostream>
using namespace std;

class sum
{
private:
    int x;
    int y;

public:
    void set(int x_val, int y_val)
    {
        x = x_val;
        y = y_val;
    }

    int getSum()
    {
        return x + y;
    }
};

int main()
{
    sum s;
    int x_input, y_input;

    cout << "Enter value for x: ";
    cin >> x_input;

    cout << "Enter value for y: ";
    cin >> y_input;

    s.set(x_input, y_input);

    cout << "Sum: " << s.getSum() << endl;

    return 0;
}
