#include <iostream>
using namespace std;
int main()
{
    // Loop

    // for (int i = 1; i <= 3; i++)
    // {
    //     for (int j = 1; j <= 3; j++)
    //     {
    //         if (i == 2 && j == 2)
    //         {
    //             cout << "--";
    //             break; // Break only inner Loop
    //         }
    //         cout << i << " " << j << "\n";
    //     }
    // }

    // GOTO

    int r = 0;
Repeat:

    if (r++ < 20)
        goto Repeat;
    cout << "done" << endl;
}