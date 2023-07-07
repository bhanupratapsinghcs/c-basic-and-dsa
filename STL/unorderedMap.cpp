#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
void print_map(unordered_map<string, int> &m)
{
    for (const auto &x : m)
    {
        cout << x.first << " -> " << x.second << endl;
    }
    cout << endl;
}
void print_map1(unordered_map<int, int> &m)
{
    for (const auto &x : m)
    {
        cout << x.first << " -> " << x.second << endl;
    }
    cout << endl;
}
int main()
{
    unordered_map<int, int> m1; // map store the values in unsorted order
    m1[1] = 10;
    m1[2] = 20;
    m1[3] = 30;
    m1[4] = 40;
    print_map1(m1);

    unordered_map<string, int> m{{"bhanu", 22}, {"shantanu", 12}, {"Aradhana", 14}};
    print_map(m);

    unordered_map<string, int> m2;
    m2.insert(pair<string, int>("go", 1));
    m2.insert(pair<string, int>("run", 2));
    m2.insert(pair<string, int>("walk", 3));
    print_map(m2);

    // Capacity
    cout << m.size() << endl;
    cout << m.empty() << endl;
    cout << m.max_size() << endl;

    // Element Access

    cout << m.at("bhanu") << endl;
    cout << m["bhanu"] << endl;

    // Iterator begin end rbegin rend cbegin cend
    unordered_map<string, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " -> " << itr->second << endl;
    }

    // Modifiers
    cout << m2.insert({"jump", 4}).second << endl; // insert return two values first is a iterator and second is boolean success or not (0/1)
    // cout << m2.insert_or_assign({"jump", 5}).second << endl; // introduce in c++20

    print_map(m2);
    print_map(m);
    m.swap(m2); // swap two map completely
    print_map(m2);
    print_map(m);

    std::unordered_map<std::string, std::string> m4;

    // uses pair's move constructor
    m4.emplace(std::make_pair(std::string("a"), std::string("a")));

    // uses pair's converting move constructor
    m4.emplace(std::make_pair("b", "abcd"));

    // uses pair's template constructor
    m4.emplace("d", "ddd");

    // uses pair's piecewise constructor
    m4.emplace(std::piecewise_construct,
               std::forward_as_tuple("c"),
               std::forward_as_tuple(10, 'c'));
    // as of C++17, m.try_emplace("c", 10, 'c'); can be used

    for (const auto &p : m4)
    {
        std::cout << p.first << " => " << p.second << '\n';
    }
    /**
    // c++20 features

    // map<int, char> cont{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    // auto nh = cont.extract(1);
    // cont.insert(move(nh)); // only way to change key in map but only available in c++20

    // std::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
    // std::map<int, std::string> mb{{2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
    // std::map<int, std::string> u;
    // u.merge(ma);
    // std::cout << "ma.size(): " << ma.size() << '\n';
    // u.merge(mb);
    // std::cout << "mb.size(): " << mb.size() << '\n';
    // std::cout << "mb.at(5): " << mb.at(5) << '\n';
    // for (auto const &kv : u)
    //     std::cout << kv.first << ", " << kv.second << '\n';

    */
    print_map1(m1);
    m1.erase(m1.begin()); // delete by iterator
    print_map1(m1);
    m1.erase(2); // delete by value
    print_map1(m1);

    // Lookup Function

    cout << m.count("go") << endl;
    if (m.find("f") != m.end())
    {
        cout << "Element found" << endl;
    }
    else
        cout << "Not Found" << endl;
    // cout << m.contains("go") << endl;     // c++20 feature
    m["go"] = 4;
    print_map(m);
}