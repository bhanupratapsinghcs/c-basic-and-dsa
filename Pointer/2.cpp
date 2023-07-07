#include <iostream>
using namespace std;
int main()
{
    int a;  // addrs->204 //Integer
    int *p; // addrs of p-> 64 //Pointer to integer

    // cout << p << endl; // this will give error because of p is not initialize
    a = 10;
    // pointer initialization in 3 ways
    p = &a; // 1
    // int *p = &a; // 2
    // int *p = &a;  // 3

    // cout << p << endl;  // address -> 204
    // cout << &a << endl; // address -> 204
    // cout << &p << endl; // address -> 64
    // cout << *p << endl; // value of a ->5
    // int b = 20;
    // *p = b;
    // cout << p << endl; // address -> 204
    // cout << a << endl; // value of a->8

    // p = 30; // we can't assign int value to pointer type

    // Pointer Arthemtic
    printf("Address p is %d\n", p);           // address -> 204
    printf("value at address p is %d\n", *p); // value of a ->5
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address p is %d\n", p + 1);             // address -> 208
    printf("value at address p is %d\n", *(p + 1)); // value of a ->garbage
}