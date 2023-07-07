#include <stdio.h>
int main()
{
    int a = 1025; // addrs->204 //Integer
    int *p;       // addrs of p-> 64 //Pointer to integer
    p = &a;
    printf("Size of integer %d\n", sizeof(int));
    printf("Address = %d value = %d\n", p, *p);
    char *p0;
    p0 = (char *)p;
    printf("Size of char %d\n", sizeof(char));
    printf("Address = %d value = %d\n", p0, *p0);           // value of *p0->1
    printf("Address = %d value = %d\n", p0 + 1, *(p0 + 1)); // value of *(p0+1)->4

    // void Pointer

    void *p1;
    p1 = p;
    printf("Address = %d", p1);
    // printf("this will give an error = %d", *p1);
    // printf("arthetic is not allowed in void pointer %d", *(p1 + 1));
}