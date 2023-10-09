#include "../modules/sorts/Timsort.h"
#include "../modules/sorts/QuickSort.h"
#include "../modules/sorts/MergeSort.h"
#include "../modules/comparators/comparators.h"
#include <chrono>
#include <vector>
#include <iostream>

int GetRandomNumber(const int from, const int to)
{
    if (to == from)
        return to;

    if (to < from)
        return GetRandomNumber(to, from);

    return from + rand() % (to - from + 1);
}

void resTimsort(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = GetRandomNumber(-5, 5);
    }

    auto start = std::chrono::high_resolution_clock::now();
    timsort(arr, n, ascending);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << '\n';
    delete[] arr;
}

void resQuickSort(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = GetRandomNumber(-5, 5);
    }

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << '\n';

    delete[] arr;
}

void resSort(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(GetRandomNumber(-5, 5));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << '\n';
}

void resMergeSort(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = GetRandomNumber(-5, 5);
    }

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << '\n';

    delete[] arr;
}

void resStableSort(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(GetRandomNumber(-5, 5));
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::stable_sort(vec.begin(), vec.end(), ascending);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << '\n';
}