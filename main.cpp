#include <iostream>

#define MINRUN 32

using namespace std;

int comparator(int a, int b){
    int squareA = a * a;
    int squareB = b * b;
    if (squareA == squareB)
    {
        return a > b ? squareB : squareA;
    }
    return squareA > squareB ? squareA : squareB;;
}
// bool comparator(int a, int b)
// {
//     int squareA = a * a;
//     int squareB = b * b;
//     if (squareA == squareB)
//     {
//         return a > b ? false : true;
//     }
//     return squareA > squareB;
// }

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
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && comparator(arr[j], temp)) // comparator(int a, int b)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int len1 = mid - left + 1, len2 = right - mid;
    int leftArr[len1], rightArr[len2];

    static int num = 0;

    std::cout << "Part " << num++ << ' ' << len1 << ": ";
    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[left + i];
        std::cout << leftArr[i] << " ";
    }
    std::cout << '\n';
    std::cout << "Part " << num++ << ' ' << len2 << ": ";
    for (int i = 0; i < len2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
        std::cout << rightArr[i] << " ";
    }
    std::cout << '\n';

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2)
    {
        if (comparator(leftArr[i], rightArr[j])) // comparator
            arr[k] = leftArr[i++];
        else
            arr[k] = rightArr[j++];
        k++;
    }
    while (i < len1)
        arr[k++] = leftArr[i++];
    while (j < len2)
        arr[k++] = rightArr[j++];
        
    std::cout << "! ";
    for (int i = left; i < right; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void timSortAlgo(int *arr, int n)
{
    for (int i = 0; i < n; i += minRunLength(n))
        insertionSort(arr, i, std::min(i + minRunLength(n)-1, n-1)); // Call insertionSort() // std::min(i + minRunLength(n), n)
    for (int size = minRunLength(n); size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1; // find ending point of left sub array mid+1 is starting point of right sub array
            int right = min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right); // merge sub array arr[left.....mid] & arr[mid+1....right]
        }
    }
}

// int main()
// {
//     int n;
//     std::cin >> n;
//     // std::cout << minRunLength(n);
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
//         std::cout << arr[i] << " ";
//     }
// }

int main()
{
    int n;
    std::cin >> n;
    // std::cout << minRunLength(n);
    // int *arr = new int[n];
    int arr[44] = {-4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6};
    // int arr[200] = {9, 0, 6, 0, 3, 4, 4, 3, 9, 4, 0, 7, 8, 0, 7, 2, 3, 1, 3, 5, 4, 5, 8, 0, 4, 9, 10, 6, 1, 0, 6, 10, 3, 4, 5, 3, 6, 4, 9, 7, 9, 0, 0, 4, 6, 1, 10, 8, 0, 7, 9, 2, 0, 7, 2, 7, 9, 8, 2, 1, 3, 1, 9, 1, 2, 1, 2, 1, 0, 0, 8, 9, 2, 7, 8, 9, 5, 3, 0, 8, 4, 1, 1, 10, 7, 3, 6, 5, 0, 4, 9, 9, 7, 6, 7, 6, 5, 8, 3, 10, 4, 7, 1, 10, 0, 3, 3, 2, 7, 10, 7, 8, 3, 7, 9, 2, 2, 0, 8, 8, 3, 10, 7, 10, 3, 10, 1, 2, 9, 6, 2, 9, 6, 4, 2, 10, 6, 9, 1, 9, 1, 1, 7, 8, 1, 9, 8, 10, 9, 10, 7, 4, 5, 6, 1, 6, 1, 1, 8, 5, 5, 7, 9, 2, 5, 9, 0, 8, 8, 4, 9, 5, 8, 7, 8, 4, 9, 4, 3, 3, 7, 4, 4, 0, 4, 6, 0, 3, 5, 3, 9, 0, 1, 5, 8, 9, 2, 4, 10, 5};
    // int arr[19] = {5, -1, 6, -6, 0, -4, 7, -2, -2, 9, -2, -10, 5, 8, 3, 2, 2, 8, 9};
    int val;
    // for (int i = 0; i < n; i++)
    // {
    //     std::cin >> val;
    //     arr[i] = val;
    // }
    timSortAlgo(arr, n);
    std::cout << "Answer: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}