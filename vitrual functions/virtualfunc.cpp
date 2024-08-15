#include <iostream>
using namespace std;
class instrument
{
public:
    virtual void MakeSound()
    {
        cout << "Instrument playing...." << endl;
    }
};
class accordion : public instrument
{
    void MakeSound()
    {
        cout << "Accordion playing...." << endl;
    }
};

int main()
{
    instrument *i1 = new accordion();
    i1->MakeSound();
    return 0;
}
