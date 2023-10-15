#ifndef CUSTOM_SORT_H
#define CUSTOM_SORT_H
#include "InsertionSort.h"
#define MINRUN 32

int minRunLength(int n)
{
    if (n > 0 && n < 65)
        return /*n*/ MINRUN;

    int flag = 0;
    while (n >= 64)
    {
        flag |= n & 1;
        n >>= 1;
    }
    return n + flag;
    // return MINRUN;
}

void customSort(int *arr, int n, bool (*comparator)(int, int))
{
    int current = 0;

    while (current < n)
    {
        int start = current;
        while (current < n - 1 && comparator(arr[current], arr[current + 1]))
        {
            current++;
        }
        current++;
        if (current == start)
        {
            while (current < n - 1 && comparator(arr[current + 1], arr[current]))
            {
                current++;
            }
            current++;
            int j = current - start;
            for (int i = start; i < (current - start + 1) / 2; i++, j--)
                std::swap(arr[i], arr[j]);
        }

        if (current - start + 1 < minRunLength(n))
        {
            current = std::min(start + minRunLength(n) - 1, n - 1);
        }

        insertionSort(arr, start, current, comparator);

        current = current + 1;
    }
}

#endif