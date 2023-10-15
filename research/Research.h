#ifndef RESEARCH_H
#define RESEARCH_H
#include "../modules/sorts/Timsort.h"
#include "../modules/comparators/Comparators.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>

std::vector<int> generic(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    return vec;
}

void getTime(int *arr, int n, void (*someSort)(int *, int, bool (*comparator)(int, int)))
{
    auto start = std::chrono::high_resolution_clock::now();
    someSort(arr, n, ascending);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << "ms" << '\n';
}

void getTime(std::vector<int>::iterator arr, std::vector<int>::iterator end, void (*someSort)(std::vector<int>::iterator, std::vector<int>::iterator, bool (*comparator)(int, int)))
{
    auto start = std::chrono::high_resolution_clock::now();
    someSort(arr, end, ascending);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << "ms" << '\n';
}

void resTimsort(int n)
{
    std::vector<int> vec = generic(n);

    getTime(vec.data(), n, timsort);
}

void resTimsortAsc(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::sort(vec.begin(), vec.end(), ascending);

    getTime(vec.data(), n, timsort);
}

void resTimsortDes(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::sort(vec.begin(), vec.end(), descending);

    getTime(vec.data(), n, timsort);
}

void resSort(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }

    getTime(vec.begin(), vec.end(), std::sort);
}

void resSortAsc(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::sort(vec.begin(), vec.end(), ascending);

    getTime(vec.begin(), vec.end(), std::sort);
}

void resSortDes(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::sort(vec.begin(), vec.end(), descending);

    getTime(vec.begin(), vec.end(), std::sort);
}

void resStableSort(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }

    getTime(vec.begin(), vec.end(), std::stable_sort);
}

void resStableSortAsc(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::stable_sort(vec.begin(), vec.end(), ascending);

    getTime(vec.begin(), vec.end(), std::stable_sort);
}

void resStableSortDes(int n)
{
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % 201 - 100);
    }
    std::stable_sort(vec.begin(), vec.end(), descending);

    getTime(vec.begin(), vec.end(), std::stable_sort);
}

#endif