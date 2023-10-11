#ifndef TIMSORT_H
#define TIMSORT_H
#include "InsertionSort.h"
#include "CustomSort.h"

void merge(int *arr, int left, int mid, int right, bool (*comparator)(int, int))
{
    int len1 = mid - left + 1, len2 = right - mid;
    int *leftArr = new int[len1];

    // static int num = 0;
    // std::cout << "Part " << num++ << ": ";
    // for (int i = 0; i < len1; i++)
    // {
    //     leftArr[i] = arr[left + i];
    //     std::cout << leftArr[i];
    //     if (i < len1 - 1)
    //         std::cout << ' ';
    // }
    // std::cout << '\n';
    // if (len2)
    // {
    //     std::cout << "Part " << num++ << ": ";
    //     for (int i = 0; i < len2; i++)
    //     {
    //         std::cout << arr[mid + 1 + i];
    //         if (i < len2 - 1)
    //             std::cout << ' ';
    //     }
    //     std::cout << '\n';
    // }

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];

    int i = 0, j = mid + 1, k = left;
    while (i < len1 && j <= right)
    {
        if (comparator(arr[j], leftArr[i]))
            arr[k] = arr[j++];
        else
            arr[k] = leftArr[i++];
        k++;
    }
    while (i < len1)
        arr[k++] = leftArr[i++];

    delete[] leftArr;
}

void timsort(int *arr, int n, bool (*comparator)(int, int))
{
    if (!n)
        return;
    customSort(arr, n, comparator);
    for (int size = std::min(minRunLength(n), n); size <= n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int right = std::min((left + 2 * size - 1), (n - 1));
            int mid = left + size - 1;
            if (left + size > n)
                mid = left + (right - left) / 2;
            merge(arr, left, mid, right, comparator);
        }
    }
}

#endif