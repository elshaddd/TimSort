#include <gtest/gtest.h>
#include "../comparators/Comparators.h"

int partitionSort(int *arr, int l, int r, bool (*comparator)(int, int))
{
    std::cout << "Массив до: ";
    for (int i = l; i < r; i++)
    {
        std::cout << arr[i];
        if (i < r - 1)
            std::cout << ' ';
    }
    std::cout << '\n';
    int pivot = arr[(l + r) / 2];
    std::cout << "Опорный элемент: " << pivot;
    std::cout << '\n';
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (comparator(arr[i], pivot))
            i++;
        while (comparator(pivot, arr[j]))
            j--;
        if (i >= j)
            break;
        std::swap(arr[i++], arr[j--]);
    }
    std::cout << "Массив после: ";
    for (int i = l; i < r; i++)
    {
        std::cout << arr[i];
        if (i < r - 1)
            std::cout << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
    return j;
}

void quickSort(int *arr, int l, int r, bool (*comparator)(int, int))
{
    if (l < r)
    {
        int p = partitionSort(arr, l, r, comparator);
        quickSort(arr, l, p, comparator);
        quickSort(arr, p + 1, r, comparator);
    }
}

// TEST(TimSortTest, LargeRandomArrayReversed)
// {
//     std::vector<int> arr(100);
//     for (int i = 0; i < 100; i++)
//     {
//         arr[i] = rand() % 201 - 100;
//     }
//     quickSort(arr.data(),0, arr.size(), defense);
//     EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), defense));
// }

// int main()
// {
//     ::testing::InitGoogleTest();
//     return RUN_ALL_TESTS();
// }