#include <bits/stdc++.h>
using namespace std;

int Palindrome(string Str)
{
    int startIndex = 0;
    int endIndex = Str.length() - 1; //reduce the lenght

    while (startIndex != endIndex) // loop for not palindrome
    {
        if (Str[startIndex++] != Str[endIndex--]) //update index after reading the first and last character
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string str = "bab";
    if (Palindrome(str))
    {
        cout << str << " is a palindrome.";
    }
    else
    {
        cout << str << " is not a palindrome.";
    }
}