#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double AverageAge(const string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Could not open the file.\n";
        return 0;
    }

    int totalAge = 0;
    int count = 0;
    string name;
    int age;

    while (file >> name >> age)
    {
        totalAge += age;
        count++;
    }

    file.close();

    if (count == 0)
    {
        cout << "Error: No data found in the file.\n";
        return 0;
    }

    return static_cast<double>(totalAge) / count;
}

int main()
{
    string filename = "students.txt";
    double averageAge = AverageAge(filename);
    cout << "Average age: " << averageAge << endl;
    return 0;
}
