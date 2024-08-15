#include <iostream>
using namespace std;

const int max_size = 5;

void input(char vowels[]);
void output(const char vowels[]);

void input(char vowels[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> vowels[i];
    }
}

void output(const char vowels[])
{
    for (int i = 0; i < max_size; i++)
    {
        cout << vowels[i] << endl;
    }
}

int main()
{
    char vowels[max_size];
    cout << "Enter vowels:" << endl;
    input(vowels);
    cout << endl;
    cout << "Vowels are:" << endl;
    output(vowels);
    return 0;
}
