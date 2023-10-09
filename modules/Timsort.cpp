#include "Timsort.h"

int minRunLength(int n)
{
    if (n > 0 && n < 65)
        return MINRUN;

    int flag = 0;
    while (n >= 64)
    {
        flag |= n & 1;
        n >>= 1;
    }
    return n + flag;
}

bool comparator(int a, int b)
{
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b ? false : true;
    }
    return squareA > squareB;
}

void insertionSort(int *arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int j = i - 1;
        while (j >= left && comparator(arr[j], arr[j + 1])) //   arr[j] * arr[j] > temp * temp
        {
            std::swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int len1 = mid - left + 1, len2 = right - mid;

    int *leftArr = new int[len1];
    int *rightArr = new int[len2];

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
    //         rightArr[i] = arr[mid + 1 + i];
    //         std::cout << rightArr[i];
    //         if (i < len2 - 1)
    //             std::cout << ' ';
    //     }
    //     std::cout << '\n';
    // }

    static int num = 0;
    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    if (len2)
    {
        for (int i = 0; i < len2; i++)
        {
            rightArr[i] = arr[mid + 1 + i];
        }
    }

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2)
    {
        if (comparator(rightArr[j], leftArr[i]))
            arr[k] = leftArr[i++];
        else
            arr[k] = rightArr[j++];
        k++;
    }
    while (i < len1)
        arr[k++] = leftArr[i++];
    while (j < len2)
        arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void customSort(int *arr, int n)
{
    int current = 0;

    while (current < n)
    {
        int start = current;
        while (current < n - 1 && comparator(arr[current], arr[current + 1]))
        {
            current++;
        }

        if (current == start)
        {
            while (current < n - 1 && comparator(arr[current + 1], arr[current]))
            {
                current++;
            }
            std::reverse(arr + start, arr + current);
        }

        if (current - start + 1 < minRunLength(n))
        {
            current = std::min(start + minRunLength(n) - 1, n - 1);
        }

        insertionSort(arr, start, current);

        current = current + 1;
    }
}

void timsort(int *arr, int n)
{
    customSort(arr, n);
    for (int size = std::min(minRunLength(n), n); size <= n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int right = std::min((left + 2 * size - 1), (n - 1));
            int mid = left + size - 1;
            if (left + size > n)
                mid = left + (right - left) / 2;
            merge(arr, left, mid, right);
        }
    }
}