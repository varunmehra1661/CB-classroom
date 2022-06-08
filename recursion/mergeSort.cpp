#include <bits/stdc++.h>
using namespace std;

void MergeArray(int a[], int s, int e)
{
    int mid = (s + e) / 2;

    int a3[e]; // alternate array
    int i = s - 1, j = mid, k = 0;
    for (k = s - 1; (i < mid && j < e); k++) // merging array
    {

        if (a[i] <= a[j])
        {
            a3[k] = a[i];
            i++;
        }
        else
        {
            a3[k] = a[j];
            j++;
        }
    }
    // merging left elements
    if (i < mid)
    {
        for (int m = i; m < mid; m++)
        {
            a3[k++] = a[m];
        }
    }
    if (j < e)
    {
        for (int m = j; m < e; m++)
        {
            a3[k++] = a[m];
        }
    }
    // copying into original array
    for (int i = s - 1; i < e; i++)
    {
        a[i] = a3[i];
    }
}

void mergeSorting(int input[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSorting(input, start, mid);
    mergeSorting(input, mid + 1, end);
    MergeArray(input, start, end);
}

void mergeSort(int input[], int size)
{
    int start = 1;
    int end = size;
    mergeSorting(input, start, end);
}

int main()
{
    int input[] = {1, 2, 2, 1};
    int size = sizeof(input) / sizeof(int);
    mergeSort(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}