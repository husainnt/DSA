#include <iostream>
#include <stack>
using namespace std;

// Function to evaluate fully parenthesized infix expression
int eval_fully_parenthesized_infix(string str)
{
    stack<int> nst;
    stack<char> cst;
    char oper;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            nst.push(str[i] - '0');
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            cst.push(str[i]);
        }
        else if (str[i] == ')')
        {
            int num2 = nst.top();
            nst.pop();
            int num1 = nst.top();
            nst.pop();
            oper = cst.top();
            cst.pop();
            if (oper == '+')

                nst.push(num1 + num2);

            else if (oper == '-')
                nst.push(num1 - num2);
            else if (oper == '*')
                nst.push(num1 * num2);
            else if (oper == '/')
                nst.push(num1 / num2);
        }
    }
    return nst.top();
}

int main()
{
    string expression = "(((6 + 9) / 3) * (6 - 2))";
    cout << "Result: " << eval_fully_parenthesized_infix(expression) << endl;

    return 0;
}
