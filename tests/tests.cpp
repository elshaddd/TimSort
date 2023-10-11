#include <gtest/gtest.h>
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
    std::vector<int> arr;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr.push_back(i);
        }
        arr.push_back(rand() % 201 - 100);
    }

    std::vector<int> arr = {2, 2, 2, 1, 1, 1};
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, NegativeElements)
{
    std::vector<int> arr;
    for (int i = -10000; i < 0; i++)
    {
        arr.push_back(i);
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, TwoParts)
{
    std::vector<int> arr;
    for (int i = -10000; i < 10000; i++)
    {
        arr.push_back(i);
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, AscendingOrder)
{
    std::vector<int> arr;
    for (int i = 0; i < 10000; i++)
    {
        arr.push_back(i);
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, Reversed)
{
    std::vector<int> arr;
    for (int i = 10000; i > 0; i--)
    {
        arr.push_back(i);
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, LargeRandomArray)
{
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

TEST(TimSortTest, LargeRandomArrayReversed)
{
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    timsort(arr.data(), arr.size(), descending);
    timsort(arr.data(), arr.size(), ascending);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end(), ascending));
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}