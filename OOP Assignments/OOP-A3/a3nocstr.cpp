#include <iostream>
#include <cstdlib> // for strlen, strcpy, strcat
using namespace std;

class myString
{
private:
    char *content;

public:
    myString() : content(nullptr) {}

    myString(const char *str)
    {
        int length = 0;
        while (str[length] != '\0')
            length++;
        content = new char[length + 1];
        for (int i = 0; i < length; ++i)
            content[i] = str[i];
        content[length] = '\0';
    }

    ~myString()
    {
        delete[] content;
    }

    myString(const myString &other)
    {
        int length = 0;
        while (other.content[length] != '\0')
            length++;
        content = new char[length + 1];
        for (int i = 0; i < length; ++i)
            content[i] = other.content[i];
        content[length] = '\0';
    }

    myString &operator=(const myString &other)
    {
        if (this != &other)
        {
            delete[] content;
            int length = 0;
            while (other.content[length] != '\0')
                length++;
            content = new char[length + 1];
            for (int i = 0; i < length; ++i)
                content[i] = other.content[i];
            content[length] = '\0';
        }
        return *this;
    }

    myString &operator=(const char *str)
    {
        if (content != nullptr)
        {
            delete[] content;
        }
        int length = 0;
        while (str[length] != '\0')
            length++;
        content = new char[length + 1];
        for (int i = 0; i < length; ++i)
            content[i] = str[i];
        content[length] = '\0';
        return *this;
    }

    myString operator+(const myString &other) const
    {
        int totalLength = 0;
        int i = 0;
        while (content[i] != '\0')
        {
            totalLength++;
            i++;
        }
        i = 0;
        while (other.content[i] != '\0')
        {
            totalLength++;
            i++;
        }
        char *resultContent = new char[totalLength + 1];
        int index = 0;
        i = 0;
        while (content[i] != '\0')
        {
            resultContent[index++] = content[i++];
        }
        i = 0;
        while (other.content[i] != '\0')
        {
            resultContent[index++] = other.content[i++];
        }
        resultContent[totalLength] = '\0';
        myString result(resultContent);
        delete[] resultContent;
        return result;
    }

    bool operator==(const myString &other) const
    {
        int i = 0;
        while (content[i] != '\0' && other.content[i] != '\0')
        {
            if (content[i] != other.content[i])
                return false;
            i++;
        }
        return (content[i] == '\0' && other.content[i] == '\0');
    }

    bool operator<(const myString &other) const
    {
        int i = 0;
        while (content[i] != '\0' && other.content[i] != '\0')
        {
            if (content[i] < other.content[i])
                return true;
            else if (content[i] > other.content[i])
                return false;
            i++;
        }
        return (content[i] == '\0' && other.content[i] != '\0');
    }

    int length() const
    {
        int length = 0;
        while (content[length] != '\0')
            length++;
        return length;
    }

    char operator[](int index) const
    {
        if (content == nullptr || index < 0 || index >= length())
        {
            return '\0';
        }
        return content[index];
    }

    // Overloaded input operator (cin >>)
    friend istream &operator>>(istream &input, myString &str)
    {
        char ch;
        // Clear existing content
        if (str.content != nullptr)
        {
            delete[] str.content;
            str.content = nullptr;
        }
        // Read characters until newline or EOF
        while (input.get(ch) && ch != '\n')
        {
            if (str.content == nullptr)
            {
                str.content = new char[2];
                str.content[0] = ch;
                str.content[1] = '\0';
            }
            else
            {
                int len = str.length();
                char *temp = new char[len + 2];
                for (int i = 0; i < len; ++i)
                    temp[i] = str.content[i];
                temp[len] = ch;
                temp[len + 1] = '\0';
                delete[] str.content;
                str.content = temp;
            }
        }
        return input;
    }

    // Overloaded output operator (cout <<)
    friend ostream &operator<<(ostream &output, const myString &str)
    {
        if (str.content != nullptr)
        {
            output << str.content;
        }
        return output;
    }
};

int main()
{
    myString str1, str2; // default constructor
    cout << "Enter first string: ";
    cin >> str1; // >> oper overloaded
    cout << "Enter second string: ";
    cin >> str2;

    cout << endl
         << "Individual elements of str1 are\n";
    for (int i = 0; i < str1.length(); i++)
        cout << "str1[" << i << "]= " << str1[i] << endl; // [ ] operator overloaded

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
