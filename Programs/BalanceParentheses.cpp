#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool balanceParantheses(string *str)
{
    stack<char> BP;
    int n = (*str).length();
    int i;
    for (i = 0; i < n; i++)
    {
        if ((*str)[i] == '(' || (*str)[i] == '[' || (*str)[i] == '{')
        {
            BP.push((*str)[i]);
        }
        else if ((*str)[i] == ')' || (*str)[i] == ']' || (*str)[i] == '}')
        {
            if (BP.empty())
                return false;
            else if (BP.top() == '(' && ')' != (*str)[i])
            {
                return false;
            }
            else if (BP.top() == '{' && '}' != (*str)[i])
            {
                return false;
            }
            else if (BP.top() == '[' && ']' != (*str)[i])
            {
                return false;
            }
            else
            {
                BP.pop();
            }
        }
    }
    return BP.empty() ? true : false;
}
int main()
{
    string str;
    getline(cin >> ws, str);
    cout << balanceParantheses(&str);
}