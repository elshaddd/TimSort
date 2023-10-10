#include <iostream>
#include <algorithm>
#include "./modules/sorts/Timsort.h"
#include "./modules/comparators/comparators.h"

int main()
{
    int n;
    std::cin >> n;
    int *arr = new int[n];
    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        arr[i] = val;
    }
    timsort(arr, n, &ascending);
    std::cout << "Answer: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i < n - 1)
            std::cout << ' ';
    }
    delete[] arr;
}