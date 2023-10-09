#include <iostream>
#include "research.h"

int main()
{
    std::cout << "TimSort\n";
    resTimsort(10);
    resTimsort(1000);
    resTimsort(100000);
    resTimsort(1000000);
    resTimsort(10000000);
    // std::cout << "QuickSort\n";
    // resQuickSort(10);
    // resQuickSort(1000);
    // resQuickSort(100000);
    // std::cout << "MergeSort\n";
    // resMergeSort(10);
    // resMergeSort(1000);
    // resMergeSort(100000);
    // resMergeSort(1000000);
    // resMergeSort(100000000);
    std::cout << "std::sort\n";
    resSort(10);
    resSort(1000);
    resSort(100000);
    resSort(1000000);
    resSort(10000000);
    std::cout << "std::stable_sort\n";
    resStableSort(10);
    resStableSort(1000);
    resStableSort(100000);
    resStableSort(1000000);
    resStableSort(10000000);
}