#include <iostream>
using namespace std;

// void print()
// {
//     ;
// }

// template <typename T>
// void print(T v)
// {
//     cout << v << endl;
// }

// template <typename T, typename... Types>
// void print(const T &first, const Types &...t)
// {
//     cout << first << ", ";
//     print(t...);
// }
template <typename T>
T sumUp(const T &v)
{
    return v;
}

template <typename T, typename... Types>
T sumUp(const T &first, const Types &...args)
{
    return first + sumUp(args...);
}
int main()
{
    cout << sumUp(1, 2, 3, 5, 6);
}