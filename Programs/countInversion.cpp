// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <iostream>
#include <vector>
#include <algorithm>
// #define long long long long
using namespace std;
void print(long long arr[], long long n)
{
    cout << endl;
    for (long long i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long i, j, k;
    long long inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
long long mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long int inversionCount3(long long arr[], long long n) // using enhenced Merge sort
{
    long long temp[n];
    return mergeSort(arr, temp, 0, n);
}
long long merge(long long l[], long long r[], long long a[], long long nl, long long nr) // should look at GFG solution not this
{
    long long i, j, k; // this code will segmentation fault because of stack memory leak
    long long int inv_count = 0;
    i = j = k = 0;
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
            inv_count += nl - i;
        }
        k++;
    }
    while (i < nl)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        a[k] = r[j];
        j++;
        k++;
    }
    return inv_count;
}
long long int mergeSort(long long arr[], long long n)
{
    if (n < 2)
        return 0;
    long long mid = n / 2;
    long long int inv_count = 0;
    long long leftarr[mid];
    long long rightarr[n - mid];
    for (long long i = 0; i < mid; i++)
    {
        leftarr[i] = arr[i];
    }
    for (long long j = mid; j < n; j++)
    {
        rightarr[j - mid] = arr[j];
    }
    inv_count += mergeSort(leftarr, mid);
    inv_count += mergeSort(rightarr, n - mid);
    inv_count += merge(leftarr, rightarr, arr, mid, n - mid); // the array arr here is redueced array when we calong long left and right subarray
    return inv_count;
}

long long int inversionCount2(long long arr[], long long n) // using enhenced Merge sort
{
    return mergeSort(arr, n);
}
long long int inversionCount(long long arr[], long long n)
{
    // int temp[n];
    // for (int i = 0; i < n; i++)
    // {
    //     temp[i] = arr[i];
    // }
    // sort(arr, arr + n);
    long long int count = 0;
    int minIndex = -1;
    for (int i = 0; i < n - 1; i++) // selection sort method
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                count += 1;
                // minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return count;
}
int main()
{
    long long arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 34, 345, 2345, 3245, 45, 4235, 345, 43565, 3453, 3245, 345, 3245, 3453, 4335, 345678, 4564, 76, 567, 32454, 24534, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    // print(arr, 62);
    cout << inversionCount3(arr, 62);
    // print(arr, 62);
}

// long long merge(long long left[], long long right[], long long arr[],  long long nl,  long long nr)
//     {
//         long long i, k, j, inversion_count;
//         i = k = j = inversion_count = 0;
//         while (i < nl && j < nr)
//         {
//             if (left[i] <= right[j])
//             {
//                 arr[k++] = left[i++];
//             }
//             else
//             {
//                 inversion_count = inversion_count + nl - i;
//                 arr[k++] == right[j++];
//             }
//         }

//         while (i < nl)
//         {
//             arr[k++] = left[i++];
//         }
//         while (j < nr)
//         {
//             arr[k++] = right[j++];
//         }
//         return inversion_count;
//     }
//     long long int mergeSort(long long arr[], long long end)
//     {
//         long long mid, inversion_count = 0;
//         if (end < 2)
//         {
//             return inversion_count;
//         }
//         mid = end / 2;
//         long long leftarr[mid];
//         long long rightarr[end - mid];
//         for (long long i = 0; i < mid; i++)
//         {
//             leftarr[i] = arr[i];
//         }
//         for (long long i = mid; i < end; i++)
//         {
//             rightarr[i - mid] = arr[i];
//         }
//         inversion_count += mergeSort(leftarr, mid);
//         inversion_count += mergeSort(rightarr, end - mid);
//         inversion_count += merge(leftarr, rightarr, arr, mid, end - mid);
//         return inversion_count;
//     }
//     long long int inversionCount(long long arr[], long long N)
//     {
//         // Your Code Here
//         return mergeSort(arr, N);
//     }