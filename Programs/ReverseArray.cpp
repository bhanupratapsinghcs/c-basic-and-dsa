#include <iostream>
#include <string>
#include <stack>
using namespace std;
void ReverseString(string *str)
{
    stack<char> sstr;
    int n = (*str).length();
    int i;
    for (i = 0; i < n; i++)
    {
        sstr.push((*str)[i]);
    }
    for (i = 0; i < n; i++)
    {
        (*str)[i] = sstr.top();
        sstr.pop();
    }
}
int main()
{
    string str;
    getline(cin >> ws, str);
    ReverseString(&str);
    cout << str;
}