#include <iostream>
#include <string>
using namespace std;
class Hero
{

private:
    int health;
    char level;
    char name[100];

public:
    Hero(int health, char level) // parameterised constructor
    {
        this->health = health;
        this->level = level;
    }

    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }
    void setHealth(int h)
    {
        health = h;
    }
    void setlevel(char ch)
    {
        level = ch;
    }
};
int main()
{
    cout << "printing properties for object created statically:" << endl;
    Hero h1(80, 'B');

    cout << "health is: " << h1.getHealth() << endl;
    cout << "level is: " << h1.getLevel() << endl;

    // cout << "printing properties for object created dynamically:" << endl;
    // Hero *s = new Hero(90, 'C'); // dynamic creation
    // cout << "health is: " << s->getHealth() << endl;
    // cout << "level is: " << s->getLevel() << endl;

    // Hero r1(h1); // copy constructor
    //  cout << "health is: " << r1.getHealth() << endl;
    //  cout << "level is: " << r1.getLevel() << endl;
    //   cout << "size is: " << sizeof(h1) << endl;

    return 0;
}
