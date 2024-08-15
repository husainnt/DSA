#include <iostream>
using namespace std;
#include <string.h>
class Tv
{
private:
    char brandname[20];
    char model[10];
    float retailprice;

public:
    Tv(char brand[], char mod[], float price); // parameterised constructor
    void change(char brand[], char mod[], float price);
    void display();
};
Tv::Tv(char brand[], char mod[], float price)
{
    strcpy(brandname, brand);
    strcpy(model, mod);
    retailprice = price;
}
void Tv::change(char brand[], char mod[], float price)
{
    strcpy(brandname, brand);
    strcpy(model, mod);
    retailprice = price;
}
void Tv::display()
{
    cout << "Brand name: " << brandname << endl;
    cout << "Model: " << model << endl;
    cout << "Retail price: " << retailprice << endl;
}
int main()
{
    Tv Test("Sony", "HDTV", 2500);
    cout << "Displaying the object...." << endl;
    Test.display();
    Test.change("LG", " 4KLED", 4800);
    cout << "Displaying the changed values...." << endl;
    Test.display();
    return 0;
}