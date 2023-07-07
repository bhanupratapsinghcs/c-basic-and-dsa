#include <iostream>
using namespace std;
void towerOfHanoi(int n, char from_rod, char axl_rod, char to_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, to_rod, axl_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, axl_rod, from_rod, to_rod);
}
int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
}