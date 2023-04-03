#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int N, int k)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == k)
            return i;
    return -1;
}

int binarySearch1(int arr[], int n, int k)
{
    int lo = 0, hi = n - 1, mid;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (arr[mid] < k)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (arr[lo] == k)
        return lo;
    else if (arr[hi] == k)
        return hi;

    return -1;
}

int binarySearch2(int arr[], int n, int k)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == k)
            return m;
        if (arr[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int ternarySearch(int arr[], int n, int k)
{
    int l = 0, r = n - 1;
    while (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == k)
            return mid1;
        if (arr[mid2] == k)
            return mid2;
        if (k < arr[mid1])
            r = mid1 - 1;
        else if (k > arr[mid2])
            l = mid2 + 1;
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int jumpSearch(int arr[], int n, int k)
{
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < k)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    for (int i = prev; i < min(step, n); i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int k)
{
    int low = 0, high = (n - 1);
    while (low <= high && k >= arr[low] && k <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == k)
                return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (k - arr[low]));

        if (arr[pos] == k)
            return pos;
        if (arr[pos] < k)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int k)
{
    if (n == 0)
        return -1;

    int i = 1;
    while (i < n and arr[i] < k)
        i *= 2;

    int left = i / 2;
    int right = min(i, n - 1);

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 4, 2, 7, 5, 9, 11};
    cout << linearSearch(arr, 7, 5) << endl;
    sort(arr, arr + 7); // Sorted array for binary, jump, interpolation and exponential searches
    cout << binarySearch1(arr, 7, 5) << endl;
    cout << binarySearch2(arr, 7, 5) << endl;
    cout << ternarySearch(arr, 7, 5) << endl;
    cout << jumpSearch(arr, 7, 5) << endl;
    cout << interpolationSearch(arr, 7, 5) << endl;
    cout << exponentialSearch(arr, 7, 5);
    return 0;
}
