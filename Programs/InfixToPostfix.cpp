#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsOperator(char O)
{
    if (O == '+' || O == '-' || O == '*' || O == '/' || O == '^')
    {
        return true;
    }
    return false;
}

bool IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    else if (C >= 'a' && C <= 'z')
        return true;
    else if (C >= 'A' && C <= 'Z')
        return true;
    return false;
}
int GetOperatorWeight(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return -1;
}

bool HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    if (op1Weight == op2Weight)
    {
        // if operator is right associative, return false
        if (op1 == '^')
            return false;
        else
            return true;
    }
    return op1Weight > op2Weight ? true : false;
}

string infixToPostfix(string exp)
{
    stack<char> S;
    string postfix = "";
    int n = exp.length();
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if (IsOperator(exp[i]))
        {
            while (!S.empty() && exp[i] != '(' && HasHigherPrecedence(S.top(), exp[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
        else if (IsOperand(exp[i]))
        {
            postfix += exp[i];
        }
        else if (exp[i] == '(')
        {
            S.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    while (!S.empty())
    {
        postfix += S.top();
        S.pop();
    }
    return postfix;
}
int main()
{
    string exp;
    getline(cin >> ws, exp);
    string result = infixToPostfix(exp);
    cout << result;
    return 0;
}