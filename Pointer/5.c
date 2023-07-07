#include <stdio.h>
void Inc(int p)
{
    p = p + 1;
    printf(" Adress of p in Inc = %d\n", &p); // address -> 23 (random due to new variable initalation)
}
void inc(int *p)
{
    *p = *p + 1;
    printf(" Adress of p in inc = %d\n", p); // address -> 64
}
int main()
{
    // call by Reference
    int a = 10;                                // address ->64
    printf(" Adress of p in main = %d\n", &a); // address -> 64
    Inc(a);
    inc(&a); //increase the value by 1
    printf("a = %d\n", a);
}