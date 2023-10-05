#include <iostream>

int minRunLength(int n)
{
    int flag = 0;
    while (n >= 64)
    {
        flag |= n & 1;
        n >>= 1;
    }

    return n + flag;
}

void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void timSort(int* arr, int n) {
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && arr[j-1] <= arr[j]) 
            j++;
        if (j - i == 1 && arr[i] > arr[i+1]) 
            std::swap(arr[i], arr[i+1]);
        int run_end = std::min(i + minRunLength(n), n);
        insertionSort(arr, i, run_end - 1);
        i = run_end;
    }
}


int main()
{
    int n;
    std::cin >> n;
    // std::cout << minRunLength(n);
    int *arr = new int[n];
    int val;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        arr[i] = val;
    }
    timSort(arr,n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}