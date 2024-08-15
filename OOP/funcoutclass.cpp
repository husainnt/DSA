#include <iostream>
using namespace std;
class array
{

private:
    int a[5]; // declaring data members

public:
    // declaring member functions
    void fill();
    void display();
    int max();
    int min();
};
void array::fill()
{
    for (int i = 0; i < 5; i++)
    {
        cout << " Enter a[" << i << "]: ";
        cin >> a[i];
    }
}
void array::display()
{
    for (int i = 0; i < 5; i++)
    {
        cout << " a[" << i << "]: " << a[i] << endl;
    }
}
int array::max()
{
    int m;
    m = a[0];
    for (int i = 0; i < 5; i++)

        if (m < a[i])
        {
            m = a[i];
        }

    return m;
}
int array::min()
{
    int n;
    n = a[0];
    for (int i = 0; i < 5; i++)

        if (n > a[i])
        {
            n = a[i];
        }

    return n;
}
int main()
{
    array a1;
    cout << " Enter values in the array: " << endl;
    a1.fill();
    cout << " The values you entered are as follows: " << endl;
    a1.display();
    cout << " The maximum value in the array is: " << a1.max() << endl;
    cout << " The minimum value in the array is: " << a1.min() << endl;
}