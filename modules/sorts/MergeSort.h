#include <iostream>
#include "../comparators/Comparators.h"

void merge(int *a, int left, int mid, int right, bool (*comparator)(int, int))
{

    int it1 = 0, it2 = 0;
    int *result = new int[right - left];
    while (left + it1 < mid && mid + it2 < right)
    {
        if (comparator(a[left + it1], a[mid + it2]))
        {
            result[it1 + it2] = a[left + it1];
            it1 += 1;
        }

        else
        {
            result[it1 + it2] = a[mid + it2];
            it2 += 1;
        }
    }

    while (left + it1 < mid)
    {
        result[it1 + it2] = a[left + it1];
        it1 += 1;
    }

    while (mid + it2 < right)
    {
        result[it1 + it2] = a[mid + it2];
        it2 += 1;
    }

    for (int i = 0; i < it1 + it2; i++)
    {
        a[left + i] = result[i];
    }
}

void mergeSortRecursive(int *arr, int left, int right, bool (*comparator)(int, int))
{
    if (left + 1 >= right)
        return;
    int mid = (left + right + 1) / 2;
    std::cout << "Merging arr: ";
    for (int i = left; i < right; i++)
    {
        std::cout << arr[i];
        if (i < right - 1)
            std::cout << ' ';
    }
    std::cout << "\n";
    mergeSortRecursive(arr, left, mid, comparator);
    mergeSortRecursive(arr, mid, right, comparator);

    merge(arr, left, mid, right, comparator);
}