#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../modules/sorts/Timsort.h"
#include "../modules/comparators/comparators.h"

TEST(TimSortTest, EmptyArray)
{
    std::vector<int> arr;
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, SingleElement)
{
    std::vector<int> arr = {1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, DuplicateElements)
{
    std::vector<int> arr = {2, 2, 2, 1, 1, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, NegativeElements)
{
    std::vector<int> arr = {-2, -1, -3, -5, -4};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, DifferentElements)
{
    std::vector<int> arr = {0, -1, 2, -2, -4};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, AscendingOrder)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, DescendingOrder)
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, LargeArray)
{
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, LargeArrayReverse)
{
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    timsort(arr.data(),arr.size(),descending);
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}