#ifndef INSERTSORT_H
#define INSERTSORT_H
#include <algorithm>

void insertionSort(int *arr, int left, int right, bool (*comparator)(int, int))
{
    for (int i = left + 1; i <= right; i++)
    {
        int j = i - 1;
        while (j >= left && comparator(arr[j + 1], arr[j]))
        {
            std::swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}

#endif