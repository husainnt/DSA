#include <iostream>
using namespace std;
class Fruit
{
public:
    string name;
    string color;
};
int main()
{
    Fruit apple; // object
    // using dot operator
    apple.name = "apple";
    apple.color = "red";
    cout << apple.name << "-" << apple.color << endl;
    // creating object using pointer
    Fruit *mango = new Fruit();
    mango->name = "mango";
    mango->color = "yellow";
    cout << mango->name << "-" << mango->color << endl;
    return 0;
}