#include <iostream>
#include <array>
using namespace std;
int main()
{
    // Declare
    array<int, 5> arr;

    // Initialization
    array<int, 5> arr1 = {1, 2, 3, 4, 5};
    array<int, 5> arr2{1, 2, 3, 4, 5}; // uniform initialization

    arr = {19, 2, 3, 4, 5};
    cout << arr.at(2) << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.data() << endl;
    cout << arr[3] << endl;
    arr.fill(4); // not dynamically increase the size of array, it just replace the last element with filled element
    cout << arr.max_size() << endl;
    cout << *arr.end() << endl;    // this just return the address of first index
    cout << *arr.begin() << endl;  // return last element address
    cout << *arr.cbegin() << endl; // return the address of index of first element when list is reverse
    cout << *arr.cend() << endl;   // opposite of cbegin
    cout << arr.size() << endl;
}