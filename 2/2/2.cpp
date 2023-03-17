#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
    if (c == '*' || c == '/') 
    {
        return 1;
    }

    if (c == '+' || c == '-') 
    {
        return 2;
    }

    return 3;
}

bool isOperand(char c) 
{
    return (c >= '0' && c <= '9');
}

string infixToPostfix(string infix)
{
    stack<char> s;

    string postfix;

    for (int i = 0; i<infix.length();i++)
    {
        if (infix[i] == '(')
        {
            s.push(infix[i] );
        }

        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }

        else if (isOperand(infix[i]))
        {
            postfix.push_back(infix[i]);
        }

        else 
        {
            while (!s.empty() && prec(infix[i]) >= prec(s.top()))
            {
                postfix.push_back(s.top());
                s.pop();
            }

            s.push(infix[i]);
        }
    }

    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

int evalPostfix(string exp)
{
    stack<int> stack;

    for (int i = 0; i<exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack.push(exp[i] - '0');
        }
        else 
        {
            int x = stack.top();
            stack.pop();

            int y = stack.top();
            stack.pop();

            if (exp[i] == '+')
            {
                stack.push(y + x);
            }
            else if (exp[i] == '-')
            {
                stack.push(y - x);
            }
            else if (exp[i] == '*')
            {
                stack.push(y * x);
            }
            else if (exp[i] == '/')
            {
                stack.push(y / x);
            }
        }
    }

    return stack.top();
}

int main()
{
    string infix;
    cin >> infix;

    cout << evalPostfix(infixToPostfix(infix));
}