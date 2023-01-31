#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class arrayFunctions
{
public:
    int n;
    int array[5];

    void rotateArray()
    {
        int *temp = array;
        for (int i = 0; i < n; i++)
        {
            array[i] = temp[n - i - 1];
        }
    }

    void samePlaceSameNumber()
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (array[i] == j)
                {
                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
    }

    void rangeQuery()
    {
        int start, end, count = 0;
        int *temp;
        cin >> start >> end;
        for (int i = start - 1; i < end; i++)
        {
            temp[count] = array[i];
            count++;
        }
        for (int i = 0; i < count; i++)
            cout << temp[i] << endl;
    }

    void multiDim()
    {
        int m, n;
        cin >> m >> n;
        int array[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> array[i][j];
            }
        }
    }

    int kadane()
    {
        int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;

        for (int i = 0; i < n; i++)
        {
            max_ending_here += array[i];
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        cout << "Maximum contiguous sum is " << max_so_far << endl;
        cout << "Starting index " << start << endl
             << "Ending index " << end << endl;
    }

    void dutchFlag()
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            switch (array[mid])
            {
            case 0:
                swap(array[low++], array[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(array[mid], array[high--]);
                break;
            }
        }

        for (int i = 0; i < n; i++)
            cout << array[i] << endl;
    }
};

int main()
{
    int a[5] = {1, 1, 2, 0, 2};
    int res;
    arrayFunctions a1;
    a1.n = 5;
    copy(a, a + 5, a1.array);
    // a1.rotateArray();
    // a1.samePlaceSameNumber();
    // a1.rangeQuery();
    // a1.multiDim();
    // a1.kadane();
    // a1.dutchFlag();

    // for (int i = 0; i < a1.n; i++)
    //     cout << a1.array[i] << endl;

    return 0;
}
