#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void set_difference(vector<int> a, vector<int> b)
{
    // cout << "yes";
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> res(n);

    vector<int>::iterator it;

    it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin());
    res.resize(it - res.begin());
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
    for (auto &i : res)
    {
        cout << i << " ";
    }
}
vector<int> set_differnce(vector<int> a, vector<int> b)
{
    vector<int> freq(10001, 0);
    vector<int> res;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for (int i = 0; i < b.size(); i++)
    {
        mx = max(b[i], mx);
        mn = min(b[i], mn);
        freq[b[i]] += 1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        freq[a[i]] -= 1;
    }
    for (int i = mn; i <= mx; i++)
    {
        if (freq[i] > 0)
        {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    vector<int> first = {5, 10, 15, 20, 25, 15};
    vector<int> second = {50, 40, 30, 20, 10};
    set_difference(first, second);
}