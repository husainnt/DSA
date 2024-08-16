// i22-1838,Hussain Tahir, Sec:B, A-03
#include <iostream>
#include <cstring>
using namespace std;

class myString
{
private:
    char *content;

public:
    myString() : content(nullptr) {}

    myString(const char *str)
    {
        content = new char[strlen(str) + 1];
        strcpy(content, str);
    }

    ~myString()
    {
        delete[] content;
    }

    myString(const myString &other)
    {
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
    }

    myString &operator=(const myString &other)
    {
        if (this != &other)
        {
            delete[] content;
            content = new char[strlen(other.content) + 1];
            strcpy(content, other.content);
        }
        return *this;
    }

    myString &operator=(const char *str)
    {
        if (content != nullptr)
        {
            delete[] content;
        }
        content = new char[strlen(str) + 1];
        strcpy(content, str);
        return *this;
    }

    myString operator+(const myString &other) const
    {
        myString result;
        int totalLength = strlen(content) + strlen(other.content);
        result.content = new char[totalLength + 1];
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

    // Overloaded input operator (cin >>)
    friend istream &operator>>(istream &input, myString &str)
    {
        char ch;

        if (str.content != nullptr)
        {
            delete[] str.content;
            str.content = nullptr;
        }

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
                int len = strlen(str.content);
                char *temp = new char[len + 2];
                strcpy(temp, str.content);
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