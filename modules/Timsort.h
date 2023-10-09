#include <iostream>
#include <algorithm>

#define MINRUN 32

bool comparator(int a, int b);

int minRunLength(int n);

void insertionSort(int *arr, int left, int right);

void merge(int *arr, int left, int mid, int right);

void customSort(int *arr, int n);

void timsort(int *arr, int n);