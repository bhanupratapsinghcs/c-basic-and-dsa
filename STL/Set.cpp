#include <iostream>
#include <set>
using namespace std;
void print_set(set<int> &s)
{
    for (auto &x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    set<int> m1{1, 2, 4, 5, 3, 4, 2, 3, 5, 1};
    print_set(m1);
    set<int> m = {1, 2, 4, 5, 3, 4, 2, 3, 5, 1};
    print_set(m);
    // Capacity
    cout << m.empty() << endl;
    cout << m.size() << endl;
    cout << m.max_size() << endl;

    // Iterator
    set<int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << *itr << " -> ";
    }
    cout << endl;

    // Modifiers
    cout << m.insert(6).second << endl;

    cout << m.emplace(3).second << endl; // similar as insert but useful for user defined data type

    m1.erase(m1.begin());
    print_set(m1);

    m1.erase(m1.begin(), m1.end());
    print_set(m1);

    m.swap(m1);
    print_set(m);
    print_set(m1);

    // Look up

    cout << m1.count(2) << endl; // returns the number of elements matching specific key
    cout << *m1.find(2) << endl; // return iterator
    // cout << m1.contains(3) << " " << m1.contains(9) << endl; // c++20 feature
}