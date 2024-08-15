#include <iostream>
#include <cstring>
using namespace std;

class myString
{
private:
    char *content;
    int capacity;

public:
    myString() : content(nullptr), capacity(0) {}

    myString(const char *str)
    {
        capacity = strlen(str) + 1;
        content = new char[capacity];
        strcpy(content, str);
    }

    ~myString()
    {
        delete[] content;
    }

    myString(const myString &other)
    {
        capacity = other.capacity;
        content = new char[capacity];
        strcpy(content, other.content);
    }

    myString &operator=(const myString &other)
    {
        if (this != &other)
        {
            delete[] content;
            capacity = other.capacity;
            content = new char[capacity];
            strcpy(content, other.content);
        }
        return *this;
    }

    myString &operator=(const char *str)
    {
        delete[] content;
        capacity = strlen(str) + 1;
        content = new char[capacity];
        strcpy(content, str);
        return *this;
    }

    myString operator+(const myString &other) const
    {
        myString result;
        result.capacity = capacity + other.capacity - 1;
        result.content = new char[result.capacity];
        strcpy(result.content, content);
        strcat(result.content, other.content);
        return result;
    }

    bool operator==(const myString &other) const
    {
        return (strcmp(content, other.content) == 0);
    }

    bool operator<(const myString &other) const
    {
        return (strcmp(content, other.content) < 0);
    }

    int length() const
    {
        return (content != nullptr) ? strlen(content) : 0;
    }

    char operator[](int index) const
    {
        if (content == nullptr || index < 0 || index >= strlen(content))
        {
            return '\0';
        }
        return content[index];
    }
};

// Overloaded input operator (cin >>)
istream &operator>>(istream &input, myString &str)
{
    char ch;
    // Clear existing content
    if (str.content != nullptr)
    {
        delete[] str.content;
        str.content = nullptr;
        str.capacity = 0;
    }
    // Read characters until newline or EOF
    while (input.get(ch) && ch != '\n')
    {
        if (str.content == nullptr)
        {
            str.capacity = 2;
            str.content = new char[str.capacity];
            str.content[0] = ch;
            str.content[1] = '\0';
        }
        else
        {
            int len = strlen(str.content);
            if (len + 1 >= str.capacity)
            {
                // Allocate more space
                char *temp = new char[2 * str.capacity];
                strcpy(temp, str.content);
                delete[] str.content;
                str.content = temp;
                str.capacity *= 2;
            }
            str.content[len] = ch;
            str.content[len + 1] = '\0';
        }
    }
    return input;
}

// Overloaded output operator (cout <<)
ostream &operator<<(ostream &output, const myString &str)
{
    if (str.content != nullptr)
    {
        output << str.content;
    }
    return output;
}

int main()
{
    myString str1, str2; // default constructor
    cout << "Enter first string: ";
    cin >> str1; // >> overloaded
    cout << "Enter second string: ";
    cin >> str2;

    cout << endl
         << "Individual elements of str1 are\n";
    for (int i = 0; i < str1.length(); i++)
        cout << "str1[" << i << "]= " << str1[i] << endl; // [] operator overloaded

    if (str1 == str2) // == operator overloaded
        cout << "\nTwo strings are equal\n";
    else
        cout << "\nTwo strings are not equal\n";

    if (str1 < str2)
        cout << "\nfirst string is smaller than second string\n";
    else
        cout << "\nfirst string is NOT smaller than second string\n";

    myString str3; // default constructor needed
    int len;

    str3 = str1;                       // assig oper overloaded in case of dynamic memory
    cout << "str3 : " << str3 << endl; // << oper overloaded

    str3 = str1 + str2; // + operator overloaded
    cout << "str1 + str2 : " << str3 << endl;

    len = str3.length(); // length function needed
    cout << "str3.length() :  " << len << endl;

    return 0;
}
