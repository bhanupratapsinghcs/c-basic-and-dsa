#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return;
    }
    int i = 1;
    int rightmostpeak = -1;
    while (i < n) // find the rightmostpeak
    {
        if (nums[i - 1] < nums[i])
        {
            rightmostpeak = i;
        }
        i++;
    }
    if (rightmostpeak == -1) // decrease sequence
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(nums[j], nums[n - j - 1]);
        }
        return;
    }
    int mn = nums[rightmostpeak];
    int index = rightmostpeak;
    for (i = rightmostpeak; i < n; i++)
    {
        if (nums[i] > nums[rightmostpeak - 1] && (nums[i] < nums[index]))
        {
            index = i;
        }
    }
    swap(nums[rightmostpeak - 1], nums[index]);
    sort((nums.begin() + rightmostpeak), nums.end());
}
int main()
{
    vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    for (auto &i : arr)
    {
        cout << i << " ";
    }
}