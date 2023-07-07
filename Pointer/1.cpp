#include <iostream>
using namespace std;
int main()
{
    // pointer are strongly Type
    int a;  // addrs->204 //Integer
    int *p; // addrs of p-> 64 //Pointer to integer
    p = &a;
    a = 5;
    cout << p << endl;  // address -> 204
    cout << &a << endl; // address -> 204
    cout << &p << endl; // address -> 64
    cout << *p << endl; // value of a ->5
    *p = 8;
    cout << a << endl; // value of a->8
}