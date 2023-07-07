// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// class Person
// {
// public:
//     string name;
//     int age;
//     virtual void getdata()
//     {
//         cout << "Person get" << endl;
//         cin >> this->name >> this->age;
//     }
//     virtual void putdata()
//     {

//         cout << "Person -> " << this->name << " " << this->age << " ";
//     }
// };
// class Professor : public Person
// {
// public:
//     int publications;
//     static int id;
//     int cur_id;
//     Professor()
//     {
//         this->cur_id = ++id;
//     }
//     void getdata()
//     {
//         // Person::getdata();
//         cout << "Professor get" << endl;
//         cin >> this->name >> this->age;
//         cin >> this->publications;
//     }
//     void putdata()
//     {

//         cout << this->name << " " << this->age << " " << this->publications << " " << cur_id << endl;
//     }
// };
// int Professor::id = 0;

// class Student : public Person
// {
// public:
//     int marks[6];
//     static int id;
//     int cur_id;
//     int sum = 0;
//     Student()
//     {
//         this->cur_id = ++id;
//     }
//     void getdata()
//     {
//         // Person::getdata();
//         cout << "Student get-> " << endl;
//         cin >> this->name >> this->age;
//         cout << "er";
//         for (int i = 0; i < 6; i++)
//         {
//             // cout << "yes";
//             cin >> marks[i];
//             // sum = sum + marks[i];
//         }
//     }
//     void putdata()
//     {
//         cout << this->name << " " << this->age << " " << this->sum << " " << cur_id << endl;
//     }
// };
// int Student::id = 0;
// int main()
// {

//     int n, val;
//     cin >> n; //The number of objects that is going to be created.
//     Person *per[n];

//     for (int i = 0; i < n; i++)
//     {

//         cin >> val;
//         if (val == 1)
//         {
//             // If val is 1 current object is of type Professor
//             per[i] = new Professor;
//         }
//         else
//             per[i] = new Student; // Else the current object is of type Student

//         per[i]->getdata(); // Get the data from the user.
//     }

//     for (int i = 0; i < n; i++)
//         per[i]->putdata(); // Print the required output for each object.

//     return 0;
// }
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdlib.h>
// #include <stdio.h>
// #include <limits.h>
// #define MAXSIZE 6555
// int main()
// {

//     int n; //size of array
//     scanf("%i", &n);
//     int a[MAXSIZE];
//     for (int i = 0; i < n; i++)
//         scanf("%i", &a[i]);
//     int minCost = INT_MAX;
//     int k;
//     scanf("%i", &k);
//     if (n == 1)
//         return printf("One elements: minimum cost=%i\n", a[0]), 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (k * (a[i] + a[i + 1]) < minCost)
//             minCost = k * (a[i] + a[i + 1]);
//     }
//     printf("Minimum cost: = %i\n", minCost);
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     unordered_map<char, int> mp;
//     string s1, s2;
//     cin >> s1 >> s2;
//     char arr[s1.length() + s2.length()];
//     int i = 0, j = 0;
//     while (i < s1.length() || i < s2.length())
//     {
//         if (i < s1.length())
//         {
//             // cout << s1[i];
//             arr[j++] = s1[i];
//             mp[s1[i]]++;
//         }
//         if (i < s2.length())
//         {
//             // cout << s2[i];
//             arr[j++] = s2[i];
//             mp[s2[i]]++;
//         }
//         i++;
//     }
//     for (i = 0; i < s1.length() + s2.length(); i++)
//     {
//         if (mp[arr[i]] == 1)
//         {
//             // cout << "yes";
//             cout << arr[i];
//         }
//     }
//     // for (auto &s : mp)
//     // {
//     //     cout << s.first << "->" << s.second << endl;
//     // }
//     // cout << string_diff << endl;ab
// }
