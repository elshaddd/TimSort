#include <iostream>
#include <algorithm>
#include "./modules/sorts/Timsort.h"
#include "./modules/comparators/comparators.h"

using namespace std;

#ifdef T

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

#else

int main()
{
    int n;
    std::cin >> n;
    int arr[45] = {-4, -5, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6};

    sort(arr, arr + n, ascending);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    timsort(arr, n, &ascending);

    std::cout << "Answer: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

#endif