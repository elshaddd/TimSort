#include <iostream>

#define MINRUN 32

using namespace std;

bool comparator(int a, int b)
{
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b ? false : true;
    }
    return squareA > squareB;
}

int minRunLength(int n)
{
    if (n > 0 && n < 65)
        return MINRUN;

    int flag = 0;
    while (n >= 64)
    {
        flag |= n & 1;
        n >>= 1;
    }
    return n + flag;
}

void insertionSort(int *arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int j = i - 1;
        while (j >= left && comparator(arr[j], arr[j+1])) //   arr[j] * arr[j] > temp * temp
        {
            std::swap(arr[j+1],arr[j]);
            j--;
        }

        if(i==right){
            int newI = right+1;
            int flag = 0;
            int count = 0;
            int temp;
            while (!comparator(arr[newI],arr[newI+1]))
            {
                
            }
            
        }
    }
    // int flag = 0;
    // for (int i = right + 1; !flag; i++)
    // {
    //     int temp = arr[i];
    //     int j = i - 1;
    //     while (j >= left && comparator(arr[j], temp)) //   arr[j] * arr[j] > temp * temp
    //     {
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     arr[j + 1] = temp;
    // }
}

void merge(int *arr, int left, int mid, int right)
{
    int len1 = mid - left + 1, len2 = right - mid;
    int leftArr[len1], rightArr[len2];

    static int num = 0;
    std::cout << "Part " << num++ << ": ";
    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[left + i];
        std::cout << leftArr[i];
        if (i < len1 - 1)
            std::cout << ' ';
    }
    std::cout << '\n';

    if (len2)
    {
        std::cout << "Part " << num++ << ": ";
        for (int i = 0; i < len2; i++)
        {
            rightArr[i] = arr[mid + 1 + i];
            std::cout << rightArr[i];
            if (i < len2 - 1)
                std::cout << ' ';
        }
        std::cout << '\n';
    }

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2)
    {
        if (comparator(rightArr[j], leftArr[i])) //  (leftArr[i] * leftArr[i]) <= (rightArr[j] * rightArr[j])
            arr[k] = leftArr[i++];
        else
            arr[k] = rightArr[j++];
        k++;
    }
    while (i < len1)
        arr[k++] = leftArr[i++];
    while (j < len2)
        arr[k++] = rightArr[j++];
}

void timSortAlgo(int *arr, int n)
{
    for (int i = 0; i < n; i += minRunLength(n))
        insertionSort(arr, i, std::min(i + minRunLength(n) - 1, n - 1)); // std::min(i + minRunLength(n), n)
    for (int size = min(minRunLength(n), n); size <= n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}

// int main()
// {
//     int n;
//     std::cin >> n;
//     int *arr = new int[n];
//     int val;
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> val;
//         arr[i] = val;
//     }
//     timSortAlgo(arr, n);
//     std::cout << "Answer: ";
//     for (int i = 0; i < n; i++)
//     {
//         std::cout << arr[i];
//         if (i < n - 1)
//             std::cout << ' ';
//     }
// }

int main()
{
    int n;
    std::cin >> n;
    std::cout << minRunLength(n) << '\n';
    // int *arr = new int[n];
    int arr[44] = {-4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6};
    // int arr[1000] = {2, 4, 0, 2, 7, 3, 4, 1, 3, 1, 6, 0, 8, 8, 6, 7, 1, 7, 10, 7, 4, 5, 3, 7, 5, 2, 10, 7, 2, 7, 4, 7, 8, 4, 1, 10, 3, 4, 10, 7, 7, 0, 4, 0, 7, 9, 3, 4, 3, 3, 5, 4, 3, 2, 5, 5, 8, 4, 1, 9, 2, 10, 3, 6, 3, 4, 2, 1, 5, 2, 1, 10, 0, 9, 4, 6, 2, 6, 10, 1, 6, 8, 7, 4, 5, 10, 2, 5, 7, 7, 6, 0, 10, 2, 1, 5, 7, 4, 8, 6, 0, 0, 1, 4, 5, 7, 6, 9, 7, 3, 9, 9, 10, 8, 6, 0, 10, 9, 1, 2, 8, 6, 6, 7, 2, 3, 4, 10, 1, 6, 10, 7, 1, 3, 4, 5, 0, 3, 7, 8, 2, 1, 9, 1, 8, 7, 3, 9, 3, 2, 0, 4, 4, 7, 2, 2, 5, 7, 6, 6, 3, 0, 7, 7, 6, 5, 8, 4, 6, 1, 10, 7, 7, 1, 8, 10, 2, 10, 1, 1, 8, 6, 2, 6, 1, 6, 0, 5, 3, 6, 9, 5, 10, 3, 6, 7, 1, 3, 9, 9, 5, 5, 3, 2, 7, 3, 4, 9, 0, 7, 5, 6, 9, 3, 0, 9, 0, 6, 4, 9, 10, 8, 0, 3, 1, 7, 6, 1, 0, 4, 7, 10, 5, 8, 0, 8, 1, 10, 7, 3, 8, 4, 0, 7, 1, 3, 10, 1, 2, 4, 4, 1, 10, 1, 1, 5, 2, 8, 1, 1, 1, 3, 7, 3, 3, 3, 8, 2, 8, 7, 7, 7, 4, 5, 1, 7, 3, 7, 2, 6, 7, 1, 10, 9, 5, 2, 2, 7, 6, 2, 9, 8, 5, 0, 6, 8, 6, 7, 5, 5, 4, 1, 8, 3, 9, 4, 9, 2, 1, 4, 4, 4, 2, 10, 1, 10, 10, 7, 1, 4, 8, 4, 2, 4, 10, 0, 0, 0, 4, 7, 1, 10, 7, 1, 9, 6, 7, 2, 7, 2, 0, 1, 8, 8, 5, 3, 5, 3, 7, 2, 5, 8, 4, 6, 8, 6, 3, 10, 3, 5, 4, 10, 8, 7, 6, 2, 6, 9, 2, 8, 8, 0, 0, 6, 2, 1, 8, 2, 3, 7, 9, 7, 6, 10, 4, 0, 7, 0, 1, 9, 9, 10, 1, 3, 6, 2, 9, 4, 1, 5, 7, 4, 6, 4, 6, 9, 2, 6, 9, 5, 9, 0, 6, 6, 9, 9, 10, 10, 4, 5, 1, 2, 10, 2, 6, 5, 10, 8, 9, 2, 7, 4, 2, 3, 7, 7, 7, 6, 3, 7, 6, 5, 8, 9, 6, 5, 7, 10, 7, 10, 2, 3, 9, 7, 9, 6, 2, 0, 5, 0, 5, 10, 9, 6, 6, 2, 1, 8, 5, 9, 8, 0, 5, 4, 4, 3, 1, 10, 7, 9, 6, 7, 3, 3, 9, 6, 0, 0, 2, 2, 0, 6, 0, 10, 8, 4, 10, 5, 4, 1, 5, 1, 10, 5, 2, 7, 3, 4, 6, 7, 1, 4, 7, 2, 10, 0, 0, 10, 2, 1, 6, 2, 9, 8, 10, 4, 0, 9, 8, 1, 7, 3, 5, 1, 6, 6, 2, 10, 7, 9, 6, 4, 2, 6, 2, 4, 4, 9, 7, 7, 4, 9, 2, 5, 4, 4, 8, 9, 6, 10, 3, 3, 6, 2, 9, 4, 3, 1, 6, 9, 10, 4, 2, 6, 10, 0, 10, 1, 4, 7, 9, 3, 8, 5, 6, 1, 10, 2, 10, 6, 0, 8, 6, 7, 1, 0, 7, 7, 0, 5, 8, 3, 0, 4, 2, 5, 5, 8, 2, 1, 4, 7, 3, 1, 8, 0, 6, 6, 0, 0, 0, 1, 10, 5, 9, 4, 6, 6, 6, 0, 5, 3, 10, 3, 2, 7, 0, 9, 4, 4, 7, 0, 7, 7, 10, 0, 1, 6, 4, 3, 1, 9, 1, 3, 8, 8, 8, 2, 10, 10, 6, 1, 8, 4, 5, 6, 9, 6, 6, 8, 7, 0, 0, 3, 2, 8, 10, 9, 0, 7, 2, 1, 9, 7, 4, 6, 1, 2, 8, 5, 6, 1, 3, 3, 5, 10, 2, 7, 3, 6, 4, 2, 1, 9, 4, 6, 4, 9, 0, 0, 1, 2, 6, 1, 6, 3, 3, 5, 7, 5, 5, 8, 9, 0, 9, 3, 0, 6, 2, 2, 1, 9, 10, 5, 5, 0, 0, 9, 2, 2, 9, 0, 2, 3, 3, 9, 4, 6, 10, 0, 4, 6, 3, 1, 3, 5, 7, 6, 3, 7, 8, 4, 7, 5, 9, 10, 4, 10, 7, 5, 6, 5, 3, 1, 9, 3, 2, 10, 6, 0, 2, 8, 2, 9, 9, 10, 9, 2, 0, 7, 5, 4, 8, 6, 10, 5, 8, 0, 1, 4, 5, 1, 6, 3, 5, 3, 0, 3, 5, 2, 10, 5, 10, 8, 10, 4, 0, 5, 2, 6, 6, 0, 3, 3, 0, 3, 3, 1, 0, 0, 1, 1, 3, 6, 4, 3, 2, 3, 7, 7, 6, 8, 10, 8, 10, 0, 10, 4, 0, 5, 4, 0, 10, 10, 8, 8, 6, 10, 1, 9, 7, 9, 3, 5, 7, 6, 0, 9, 7, 4, 10, 0, 0, 9, 5, 5, 7, 10, 3, 4, 0, 1, 3, 4, 10, 6, 5, 5, 0, 9, 0, 1, 5, 3, 0, 1, 8, 7, 2, 5, 4, 3, 6, 0, 1, 4, 8, 1, 4, 1, 8, 1, 5, 0, 4, 6, 2, 10, 7, 5, 8, 2, 3, 10, 5, 3, 0, 0, 6, 10, 9, 2, 3, 4, 1, 8, 5, 7, 0, 4, 9, 8, 10, 6, 1, 5, 4, 7, 1, 4, 7, 8, 10, 5, 4, 6, 3, 0, 5, 5, 6, 6, 10, 2, 8, 8, 8, 8, 6, 9, 9, 1, 2, 0, 9, 9, 2, 0, 3, 4, 4, 0, 0, 1, 3, 7, 6, 1, 9, 7, 7, 8, 7, 1, 7, 4, 1, 7, 1, 3};
    // int arr[19] = {5, -1, 6, -6, 0, -4, 7, -2, -2, 9, -2, -10, 5, 8, 3, 2, 2, 8, 9};

    timSortAlgo(arr, n);
    std::cout << "Answer: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}