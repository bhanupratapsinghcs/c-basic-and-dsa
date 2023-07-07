#include <iostream>
#include <stack>
#include <string>
using namespace std;
int performOperation(char operation, int op1, int op2)
{
    if (operation == '+')
        return op1 + op2;
    else if (operation == '-')
        return op1 - op2;
    else if (operation == '*')
        return op1 * op2;
    else if (operation == '/')
        return op1 / op2;
    else
        return -1;
}
void EvaluatePostfix(string exp)
{
    stack<int> S;
    int op1, op2, res;
    int n = exp.length();
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
            continue;
        else if (exp[i] >= 48 && exp[i] <= 57)
        {
            int op = 0;
            while (i < n && exp[i] >= 48 && exp[i] <= 57)
            {
                op = (op * 10) + (exp[i] - 48);
                i++;
            }
            i--;
            // cout << op << endl;
            S.push(op);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            op2 = S.top();
            S.pop();
            op1 = S.top();
            S.pop();
            res = performOperation(exp[i], op1, op2);
            S.push(res);
        }
    }
    cout << S.top();
}
int main()
{
    int a = 11 + 25 - 33 * 44;
    cout << a << endl;
    // There should be space in betwen 2 operands.
    string exp = "11 25+33 44*-";
    EvaluatePostfix(exp);
}