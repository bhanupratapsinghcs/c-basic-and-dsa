// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> arr;
    stringstream ss(str);
    for (int i; ss >> i;)
    {
        cout << i;
        arr.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return arr;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}