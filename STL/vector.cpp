#include <iostream>
#include <vector>
using namespace std;
void print_container(vector<int> &c)
{
    for (auto &i : c)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // Declare
    vector<int> arr;

    // Initialization
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2{1, 2, 3, 4, 5}; // uniform initialization

    arr = {19, 2, 3, 4, 5};
    // data access
    cout << arr.at(2) << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.data() << endl;
    cout << arr[3] << endl;
    // Iterator
    // returns an iterator to the beginning
    cout << *arr.begin() << endl;
    cout << *arr.cbegin() << endl;
    //returns an iterator to the end
    cout << *arr.end() << endl;
    cout << *arr.cbegin() << endl;
    // Capacity
    cout << arr.capacity() << endl; //  the number of elements that the container has currently allocated space for
    cout << arr.size() << endl;
    cout << arr.max_size() << endl; // returns the maximum possible number of elements
    cout << arr.empty() << endl;
    // cout << arr.shrink_to_fit() << endl;
    // Modifiers

    arr.push_back(4); // not dynamically increase the size of vector, and automatically increase the capacity of vector
    arr1.clear();     // remove all element of vector but leaves the capacity unchanged
    cout << arr1.empty() << endl;
    print_container(arr2);
    arr2.erase(arr2.begin()); // delete from the begin using the iterator

    print_container(arr2);
    arr2.erase(arr2.begin() + 2); // delete from a specific index using begin iterator
    // it can also delete element in a range
    // c.erase(c.begin()+2, c.begin()+5);

    print_container(arr2);
    std::vector<int> vec(3, 100);
    print_container(vec);

    auto it = vec.begin();
    it = vec.insert(it, 200); // insert at begin using iterator
    print_container(vec);

    vec.insert(it, 2, 300); // add 2 values at begin using iterator
    print_container(vec);

    // "it" no longer valid, get a new one:
    it = vec.begin();

    std::vector<int> vec2(2, 400);
    vec.insert(it + 2, vec2.begin(), vec2.end()); // insert in vec 1 at index at index 2 from begin to end then it's other element using iterator
    print_container(vec);

    int arrv[] = {501, 502, 503};
    vec.insert(vec.begin(), arrv, arrv + 3); // similar as above
    print_container(vec);

    std::vector<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    print_container(c);
    c.resize(5); //increase the size by 5 and fiil with 0 by default
    std::cout << "After resize up to 5: ";
    print_container(c);
    c.resize(8, 1); //increase the size by 5 and fiil with 1
    std::cout << "After resize up to 5: ";
    print_container(c);
    c.resize(2);
    std::cout << "After resize down to 2: ";
    print_container(c);

    vec.resize(3);
    print_container(vec);
    print_container(vec2);
    vec.swap(vec2); // swap two vector
    print_container(vec);
    print_container(vec2);
    vec.pop_back();
    print_container(vec);
    /**
     * two more function called emplace and emplace_back are 
     * also used to insert a element in a container directly before position
     * The element is constructed through std::allocator_traits::construct, 
     * which typically uses placement-new to construct the element in-place at a location 
     * provided by the container. However, if the required location has been occupied by
     * an existing element, the inserted element is constructed at another location at first,
     * and then move assigned into the required location.
     * The arguments args... are forwarded to the constructor as std::forward<Args>(args).... args...
     * may directly or indirectly refer to a value in the container.
     * If the new size() is greater than capacity(), all iterators and references are invalidated. Otherwise,
     * only the iterators and references before the insertion point remain valid. 
     * The past-the-end iterator is also invalidated.
     */

    /** emplace and emplace_back used when a data type is user defined 
     * they all in directly add the object without creating the extra copy of 
     * of object and append in the object without calling it's constructor
     */
}