#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n)
{
    int i, j, v, temp;
    for (i = 0; i <= n - 1; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

int partition(int a[], int first, int last)
{
    int pivot = a[first];
    int start = first;
    int end = last;

    while (start < end)
    {
        while (a[start] <= pivot && start < last)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
            swap(a[start], a[end]);
    }
    swap(a[first], a[end]);

    return end;
}

void quickSort(int a[], int start, int last)
{
    if (start < last)
    {
        int loc = partition(a, start, last);
        quickSort(a, start, loc - 1);
        quickSort(a, loc + 1, last);
    }
}

void merge(int a[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int i, j, k;

    int left[n1];
    int right[n2];

    for (i = 0; i < n1; i++)
        left[i] = a[l + i];

    for (i = 0; i < n2; i++)
        right[i] = a[m + 1 + i];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int *a, int n, int i)
{
    int maxindex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[maxindex])
        maxindex = l;

    if (r < n && a[r] > a[maxindex])
        maxindex = r;

    if (maxindex != i)
    {
        swap(a[i], a[maxindex]);
        heapify(a, n, maxindex);
    }
}

void heapSort(int *a, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {5, 2, 7, 1, 2, 10, 6};
    bubbleSort(a, 7);
    selectionSort(a, 7);
    insertionSort(a, 7);
    quickSort(a, 0, 6);
    mergeSort(a, 0, 6);
    heapSort(a, 7);
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    return 0;
}
