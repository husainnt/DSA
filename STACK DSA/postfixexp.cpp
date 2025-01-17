#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;
int eval_postfix(string str)
{
    stack<int> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string exp = "46+2/5*7+";
    cout << eval_postfix(exp) << endl;

    return 0;
}