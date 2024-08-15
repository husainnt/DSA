#include <iostream>
using namespace std;
class Read
{
private:
    int days, pages;

public:
    Read()
    {
        int days = pages = 0;
    }
    void input();
    void display();
    void operator+=(Read r);
};
void Read::input()
{
    cout << "Enter the no of days read :" << endl;
    cin >> days;
    cout << "Enter the no of pages read :" << endl;
    cin >> pages;
}
void Read::display()
{
    cout << "You have read: " << pages << " pages in: " << days << " days" << endl;
}
void Read::operator+=(Read r)
{
    days = days + r.days;
    pages = pages + r.pages;
}
int main()
{
    Read r1, r2;
    cout << "Reading in 1st month: " << endl;
    r1.input();
    cout << "Reading in 2nd month: " << endl;
    r2.input();
    cout << "Reading details in 1st month: " << endl;
    r1.display();
    cout << "Reading details in 2nd month: " << endl;
    r2.display();
    cout << "Adding 1st months reading to 2nd months reading using (+=)" << endl;
    r2 += r1;
    cout << "Total reading : " << endl;
    r2.display();
}
