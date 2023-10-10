#include <algorithm>

#define MINRUN 32

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
    // return MINRUN;
}

void insertionSort(int *arr, int left, int right, bool (*comparator)(int, int))
{
    for (int i = left + 1; i <= right; i++)
    {
        int j = i - 1;
        while (j >= left && comparator(arr[j+1], arr[j]))
        {
            std::swap(arr[j + 1], arr[j]);
            j--;
        }
    }
}

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
    {
        leftArr[i] = arr[left + i];
    }

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

void customSort(int *arr, int n, bool (*comparator)(int, int))
{
    int current = 0;

    while (current < n)
    {
        int start = current;
        while (current < n - 1 && comparator(arr[current], arr[current+1]))
        {
            current++;
        }

        if (current == start)
        {
            while (current < n - 1 && comparator(arr[current+1], arr[current]))
            {
                current++;
            }
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

void timsort(int *arr, int n, bool (*comparator)(int, int))
{
    if (!n)
    {
        return;
    }
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