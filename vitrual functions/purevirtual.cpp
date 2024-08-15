#include <iostream>
using namespace std;
class instrument
{
public:
    virtual void MakeSound() = 0; // now the func is pure-virtual and clalss is abstract
};
class accordion : public instrument
{
    void MakeSound()
    {
        cout << "Accordion playing...." << endl;
    }
};
class piano : public instrument
{
    void MakeSound()
    {
        cout << "Piano playing...." << endl;
    }
};

int main()
{
    instrument *i1 = new accordion();
    // i1->MakeSound();
    instrument *i2 = new piano();
    // i2->MakeSound();
    instrument *instruments[2] = {i1, i2}; // polymprphism
    for (int i = 0; i < 2; i++)
    {
        instruments[i]->MakeSound();
    }
    return 0;
}
