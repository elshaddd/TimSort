#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "../modules/sorts/Timsort.h"
#include "../modules/comparators/comparators.h"

TEST(TimSortTest, EmptyArray)
{
    std::vector<int> arr;
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, SingleElement)
{
    std::vector<int> arr = {1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, TwoElements)
{
    std::vector<int> arr = {2, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, DuplicateElements)
{
    std::vector<int> arr = {2, 2, 2, 1, 1, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, NegativeElements)
{
    std::vector<int> arr = {-2, -1, -3, -5, -4};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, DifferentElements)
{
    std::vector<int> arr = {0, -1, 2, -2, -4};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, AscendingOrder)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

TEST(TimSortTest, DescendingOrder)
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}
int GetRandomNumber(const int from, const int to)
{
    if (to == from)
        return to;

    if (to < from)
        return GetRandomNumber(to, from);

    return from + rand() % (to - from + 1);
}
TEST(TimSortTest, LargeArray)
{
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = GetRandomNumber(-5, 5);
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), cmp));
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}