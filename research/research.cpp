#include <iostream>
#include "research.h"

int main()
{
    std::cout << MINRUN << '\n';
    for (int i = 10; i <= 10000000; i *= 100)
    {
        std::cout << "TimSort random " << i << ": ";
        resTimsort(i);
        std::cout << "TimSort already sorted " << i << ": ";
        resTimsortAsc(i);
        std::cout << "TimSort reversed " << i << ": ";
        resTimsortDes(i);
        std::cout << '\n';
    }

    // for (int i = 10; i <= 10000000; i *= 100)
    // {
    //     std::cout << "std::sort random " << i << ": ";
    //     resSort(i);
    //     std::cout << "std::sort already sorted " << i << ": ";
    //     resSortAsc(i);
    //     std::cout << "std::sort reversed " << i << ": ";
    //     resSortDes(i);
    //     std::cout << '\n';
    // }

    // for (int i = 10; i <= 10000000; i *= 100)
    // {
    //     std::cout << "std::stable_sort random " << i << ": ";
    //     resSort(i);
    //     std::cout << "std::stable_sort already sorted " << i << ": ";
    //     resStableSortAsc(i);
    //     std::cout << "std::stable_sort reversed " << i << ": ";
    //     resStableSortDes(i);
    //     std::cout << '\n';
    // }
}