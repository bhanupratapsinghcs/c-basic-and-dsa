#include <iostream>
using namespace std;
int main()
{
    int b;
    register int a = 1;
    static int j = 0; // initial a variable globaly
    extern int k;
    // The extern variable is visible to all the programs.
    // It is used if two or more files are sharing same variable or function.
    cout << &b << endl;
    //The register variable allocates memory in register than RAM. Its size is same of register size.
    // It has a faster access than other variables.
    //It is recommended to use register variable only for quick access such as in counter.

    cout << &a << sizeof(a) << endl;
    //Note: We can't get the address of register variable.
    cout << a;
}