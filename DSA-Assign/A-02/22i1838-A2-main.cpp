/*
 * Assignment #: 2
 * Name: Hussain Tahir
 * Roll #: 22i-1838
 * Section: A
 * Program Description:
 * My code includes functions for evaluating infix and postfix expressions.
 * The program performs the following tasks:
 * 1. Takes an infix expression and evaluates it only if it has passed the parenthesis check.
 * 2. Takes a postfix expression and evaluates it.
 *
 * Additionally, I have created a separate class to declare the functions for evaluating expressions
 * along with checking parentheses. I have also added a colorful command-line interface for better
 * user interaction.
 *~
 * Note: As I use VSCode, the compiler gives no errors, but I am not aware of any issues if compiled
 * on DevC++ or any other code editor/IDE.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string RESET = "\033[0m";
string RED = "\033[31m";
string GREEN = "\033[32m";
string YELLOW = "\033[33m";
string BLUE = "\033[34m";
string MAGENTA = "\033[35m";

class Evaluate_infix_postfix
{
public:
    bool areParenthesesBalanced(const string &str);
    int evaluate_infix(const string &str);
    int evaluate_postfix(const string &str);
    bool isFullyParenthesized(const string &str);
    int oper_priority(char op);
    int calculate(int op1, int op2, char op);
};

bool Evaluate_infix_postfix::areParenthesesBalanced(const string &str)
{
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (stack.empty())
                return false;
            char top = stack.top();
            if ((str[i] == ')' && top == '(') || (str[i] == '}' && top == '{') || (str[i] == ']' && top == '['))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int Evaluate_infix_postfix::oper_priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int Evaluate_infix_postfix::calculate(int op1, int op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    default:
        return 0;
    }
}

int Evaluate_infix_postfix::evaluate_infix(const string &str)
{
    if (!isFullyParenthesized(str))
    {
        cout << "Error: The expression is not fully parenthesized." << endl;
    }

    stack<int> nstk;
    stack<char> opr;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ')
            continue;

        if (str[i] >= '0' && str[i] <= '9')
        {
            int value = 0;

            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                value = (value * 10) + (str[i] - '0');
                i++;
            }
            nstk.push(value);
            i--;
        }
        else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            opr.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            while (!opr.empty() && (opr.top() != '(' && opr.top() != '{' && opr.top() != '['))
            {
                int value2 = nstk.top();
                nstk.pop();
                int value1 = nstk.top();
                nstk.pop();
                char op = opr.top();
                opr.pop();
                nstk.push(calculate(value1, value2, op));
            }
            opr.pop();
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (!opr.empty() && oper_priority(opr.top()) >= oper_priority(str[i]))
            {
                int value2 = nstk.top();
                nstk.pop();
                int value1 = nstk.top();
                nstk.pop();
                char op = opr.top();
                opr.pop();
                nstk.push(calculate(value1, value2, op));
            }
            opr.push(str[i]);
        }
    }

    while (!opr.empty())
    {
        int value2 = nstk.top();
        nstk.pop();
        int value1 = nstk.top();
        nstk.pop();
        char op = opr.top();
        opr.pop();
        nstk.push(calculate(value1, value2, op));
    }

    return nstk.top();
}

int Evaluate_infix_postfix::evaluate_postfix(const string &str)
{
    stack<int> nstk;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ')
            continue;

        if (str[i] >= '0' && str[i] <= '9')
        {
            int value = 0;
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                value = (value * 10) + (str[i] - '0');
                i++;
            }
            nstk.push(value);
            i--;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            int value2 = nstk.top();
            nstk.pop();
            int value1 = nstk.top();
            nstk.pop();
            nstk.push(calculate(value1, value2, str[i]));
        }
    }

    return nstk.top();
}

bool Evaluate_infix_postfix::isFullyParenthesized(const string &str)
{
    int cnt = 0;
    bool lastWasOp = true;

    for (int i = 0; i < str.length(); ++i)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            cnt++;
            lastWasOp = true;
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (cnt == 0)
            {
                return false;
            }
            cnt--;
            lastWasOp = false;
        }

        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (lastWasOp)
            {
                return false;
            }
            if (cnt == 0)
            {
                return false;
            }
            lastWasOp = true;
        }

        else if (str[i] >= '0' && str[i] <= '9')
        {

            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                i++;
            }
            i--;
            lastWasOp = false;
        }
    }

    return cnt == 0 && !lastWasOp;
}

int main()
{
    Evaluate_infix_postfix eval;
    int choice;
    string str;
    int result;

    do
    {
        cout << BLUE;
        cout << "====================" << endl;
        cout << "      Menu          " << endl;
        cout << "====================" << endl;
        cout << GREEN;
        cout << "1. Evaluate Infix Expression" << endl;
        cout << "2. Evaluate Postfix Expression" << endl;
        cout << "3. Exit" << endl;
        cout << RESET;
        cout << MAGENTA;
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << YELLOW;
            cout << "Input fully parenthesized infix expression: ";
            getline(cin, str);
            if (eval.areParenthesesBalanced(str))
            {
                if (eval.isFullyParenthesized(str))
                {
                    int result = eval.evaluate_infix(str);
                    cout << GREEN;
                    cout << "Result: " << result << endl;
                }
                else
                {
                    cout << RED;
                    cout << "Not fully parenthesized." << endl;
                }
            }
            else
            {
                cout << RED;
                cout << "Parenthesis problem." << endl;
            }
            break;
        }
        case 2:
        {
            cout << YELLOW;
            cout << "Input postfix expression (put space after every operand or operator): ";
            getline(cin, str);
            result = eval.evaluate_postfix(str);
            cout << GREEN;
            cout << "Answer: " << result << endl;
            break;
        }
        case 3:
            cout << MAGENTA;
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << RED;
            cout << "Invalid choice! Enter a valid choice." << endl;
            break;
        }
        cout << RESET;
    } while (choice != 3);

    return 0;
}