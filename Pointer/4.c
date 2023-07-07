#include <stdio.h>
int main()
{
    int *ptr[10];

    // This is an array of 10 int *pointers, not as you would assume,
    // a pointer to an array of 10 ints

    int(*ptr)[10];

    // This is a pointer to an array of 10 int

    // It is I believe the same as int *ptr;
    // in that both can point to an array,
    // but the given form can ONLY point to an array of 10 ints

    // Pointer to pointer
    int a = 5; // addrs->204 //Integer
    int *p;    // addrs of p-> 64 //Pointer to integer
    p = &a;
    *p = 6;

    int **q;
    q = &p;
    // or int **q=&p;
    // int ***r = &p; give error , it only take int ** pointer addresss
    int ***r = &q;
    printf("%d\n", *p);
    printf("%d\n", *q);
    printf("%d\n", **q);
    printf("%d\n", *r);
    printf("%d\n", **r);
    printf("%d\n", ***r);
    ***r = 10;
    printf("%d\n", a);
    **q = *p + 2;
    printf("%d", a);
}