#include <iostream>
using namespace std;
class book
{
private:
    int bookid, pages;
    float price;

public:
    void getinput() // storing data in private variables
    {
        cout << "Enter Book Id: " << endl;
        cin >> bookid;
        cout << " Enter pages of book: " << endl;
        cin >> pages;
        cout << " Enter price of book: " << endl;
        cin >> price;
    }
    void show() // ouptput of data stored
    {
        cout << "Book Id = " << bookid << endl;
        cout << "Book Pages =" << pages << endl;
        cout << "Book Price =" << price << endl;
    }
    void set(int id, int pg, float pr) // copying private data into separate var
    {
        bookid = id;
        pages = pg;
        price = pr;
    }
    float getprice()
    {
        return price;
    }
};
int main()
{
    book b1, b2;
    b1.getinput();          // take input and set values for private var
    b2.set(2, 320, 150.75); // directly sets values for private var
    cout << "\nThe details of the most costly book is as follows: " << endl;
    if (b1.getprice() > b2.getprice())
    {
        b1.show();
    }
    else
    {
        b2.show();
    }
}