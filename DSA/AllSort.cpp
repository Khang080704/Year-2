#pragma once
#include <vector>

#include "AllSort.h"
using namespace std;

void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//----------------selection sort ---------------------
void selectionSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    int index = -1;
    while (++count_cmp && index < n) {
        int minIndex = index + 1;
        for (int i = index + 1; ++count_cmp && i < n; i++) {
            if (++count_cmp && a[i] < a[minIndex]) {
                minIndex = i;
            }
        }

        swapElements(a[index + 1], a[minIndex]);

        index++;
    }
}

//----------------insertion sort ---------------------
void insertionSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    int i, key, j;

    for (i = 1; ++count_cmp && i < n; i++) {
        key = a[i];

        j = i - 1;

        while (++count_cmp && j >= 0 && ++count_cmp && a[j] > key) {
            a[j + 1] = a[j];

            j = j - 1;
        }
        a[j + 1] = key;
    }
}

//----------------bubble sort ---------------------
void bubbleSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int i = 0; ++count_cmp && i < n - 1; i++) {
        for (int j = 0; ++count_cmp && j < n - i - 1; j++) {
            if (++count_cmp && a[j] > a[j + 1]) {
                swapElements(a[j], a[j + 1]);
            }
        }
    }
}

//----------------shaker sort ---------------------
void shakerSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;

    int count = INT_MIN;
    while (++count_cmp && count != 0) {
        count = 0;

        for (int i = 0; ++count_cmp && i < n - 1; i++) {
            if (++count_cmp && a[i] > a[i + 1]) {
                swapElements(a[i], a[i + 1]);
                count++;
            }
        }

        for (int i = n - 1; ++count_cmp && i > 0; i--) {
            if (++count_cmp&& a[i] < a[i - 1]) {
                swapElements(a[i], a[i - 1]);
                count++;
            }
        }
    }
}
//----------------shell sort ---------------------
void shellSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int gap = n / 2; ++count_cmp && gap > 0; gap /= 2) {
        for (int i = gap; ++count_cmp && i < n; i += 1) {
            int temp = a[i];

            int j;
            for (j = i; ++count_cmp && j >= gap && ++count_cmp && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

//----------------heap sort ---------------------
void heapify(int a[], int n, int i, long long& count_cmp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++count_cmp && left < n && ++count_cmp && a[left] > a[largest])
        largest = left;
    if (++count_cmp && right < n && ++count_cmp && a[right] > a[largest])
        largest = right;
    if (++count_cmp && largest != i) {
        swapElements(a[i], a[largest]);
        heapify(a, n, largest, count_cmp);
    }
}

void heapSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int i = n / 2 - 1; ++count_cmp && i >= 0; i--)
        heapify(a, n, i, count_cmp);
    for (int i = n - 1; ++count_cmp && i >= 0; i--) {
        swapElements(a[0], a[i]);
        heapify(a, i, 0, count_cmp);
    }
}

//----------------merge sort ---------------------
void merge(int aay[], int left, int mid,
    int right, long long& count_cmp) {
    int subaayOne = mid - left + 1;
    int subaayTwo = right - mid;

    int* leftaay = new int[subaayOne],
        * rightaay = new int[subaayTwo];

    for (int i = 0; ++count_cmp && i < subaayOne; i++)
        leftaay[i] = aay[left + i];
    for (int j = 0; ++count_cmp && j < subaayTwo; j++)
        rightaay[j] = aay[mid + 1 + j];

    int indexOfSubaayOne = 0, indexOfSubaayTwo = 0;
    int indexOfMergedaay = left;

    while (++count_cmp && indexOfSubaayOne < subaayOne && ++count_cmp && indexOfSubaayTwo < subaayTwo) {
        if (++count_cmp && leftaay[indexOfSubaayOne] <= rightaay[indexOfSubaayTwo]) {
            aay[indexOfMergedaay] = leftaay[indexOfSubaayOne];
            indexOfSubaayOne++;
        }
        else {
            aay[indexOfMergedaay] = rightaay[indexOfSubaayTwo];
            indexOfSubaayTwo++;
        }
        indexOfMergedaay++;
    }

    while (++count_cmp && indexOfSubaayOne < subaayOne) {
        aay[indexOfMergedaay] = leftaay[indexOfSubaayOne];
        indexOfSubaayOne++;
        indexOfMergedaay++;
    }
    delete[] leftaay;

    while (++count_cmp && indexOfSubaayTwo < subaayTwo) {
        aay[indexOfMergedaay] = rightaay[indexOfSubaayTwo];
        indexOfSubaayTwo++;
        indexOfMergedaay++;
    }

    delete[] rightaay;
}

void mergeSort(int aay[], int begin, int end, long long& count_cmp) {
    if (++count_cmp && begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(aay, begin, mid, count_cmp);
    mergeSort(aay, mid + 1, end, count_cmp);
    merge(aay, begin, mid, end, count_cmp);
}

//----------------quick sort ---------------------
int hoarePartition(int a[], int low, int high, long long& count_cmp) {
    int mid = low + (high - low) / 2;
    int pivotIndex = -1;

    if ((++count_cmp && a[low] <= a[mid] && ++count_cmp && a[mid] <= a[high]) || (++count_cmp && a[high] <= a[mid] && ++count_cmp && a[mid] <= a[low]))
        pivotIndex = mid;
    else if ((++count_cmp && a[mid] <= a[low] && ++count_cmp && a[low] <= a[high]) || (++count_cmp && a[high] <= a[low] && ++count_cmp && a[low] <= a[mid]))
        pivotIndex = low;
    else
        pivotIndex = high;

    int temp1 = a[pivotIndex];
    int temp2 = a[high];
    a[pivotIndex] = temp2;
    a[high] = temp1;

    int i = low - 1;
    int pivot = a[high];
    int j = high + 1;
    while (++count_cmp && true) {
        do {
            i++;
        } while (++count_cmp && a[i] < pivot);

        do {
            j--;
        } while (++count_cmp && a[j] > pivot);

        if (++count_cmp && i >= j) {
            return j;
        }

        int tmp1 = a[i];
        int tmp2 = a[j];
        a[i] = tmp2;
        a[j] = tmp1;
    }
}

void quickSort(int a[], int low, int high, long long& count_cmp) {
    if (++count_cmp && low < high) {
        int index = hoarePartition(a, low, high, count_cmp);
        quickSort(a, low, index, count_cmp);
        quickSort(a, index + 1, high, count_cmp);
    }
    return;
}

//----------------counting sort ---------------------
void countingSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;

    int maxValue = a[0];
    for (int i = 0; ++count_cmp && i < n; i++) {
        if (++count_cmp && maxValue < a[i]) {
            maxValue = a[i];
        }
    }

    vector<int> count(maxValue + 1, 0);

    for (int i = 0; ++count_cmp && i < n; i++) {
        count[a[i]]++;
    }

    int index = 0;

    for (int i = 0; ++count_cmp && i <= maxValue; ++i) {
        while (++count_cmp && count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

//----------------radix sort ---------------------

void countSort(int a[], int n, int exp, long long& count_cmp) {
    vector<int> aayAfterDistributed(n);

    int count[10]{ 0 };

    for (int i = 0; ++count_cmp && i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; ++count_cmp && i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++count_cmp && i >= 0; i--) {
        aayAfterDistributed[--count[(a[i] / exp) % 10]] = a[i];
    }

    for (int i = 0; ++count_cmp && i < n; i++) {
        a[i] = aayAfterDistributed[i];
    }
}

void radixSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;

    int Max = a[0];
    for (int i = 1; ++count_cmp && i < n; i++) {
        if (++count_cmp && Max < a[i]) {
            Max = a[i];
        }
    }
    int exp = 1;

    while (++count_cmp && Max / exp > 0) {
        countSort(a, n, exp, count_cmp);
        exp *= 10;
    }
}

//----------------flash sort ---------------------
void flashSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;

    int numberOfBuckets = int(0.43 * n);

    int* Buckets = new int[numberOfBuckets];
    for (int i = 0; ++count_cmp && i < numberOfBuckets; i++)
        Buckets[i] = 0;

    int minVal = a[0];
    int maxPos = 0;
    for (int i = 1; ++count_cmp && i < n; i++) {
        if (++count_cmp && a[i] < minVal)
            minVal = a[i];
        if (++count_cmp && a[i] > a[maxPos])
            maxPos = i;
    }

    if (++count_cmp && a[maxPos] == minVal)
        return;

    double constNum = (double)(numberOfBuckets - 1) / (a[maxPos] - minVal);

    for (int i = 0; ++count_cmp && i < n; i++) {
        int k = int(constNum * (a[i] - minVal));
        ++Buckets[k];
    }
    for (int i = 1; ++count_cmp && i < numberOfBuckets; i++)
        Buckets[i] += Buckets[i - 1];

    swapElements(a[maxPos], a[0]);

    int i = 0;
    int k = numberOfBuckets - 1;
    int t = 0;
    int flash;
    int countswapElements = 0;
    while (++count_cmp && countswapElements < n - 1) {
        while (++count_cmp && i > Buckets[k] - 1) {
            i++;
            k = int(constNum * (a[i] - minVal));
        }

        if (++count_cmp && k < 0) break;
        flash = a[i];

        while (++count_cmp && i != Buckets[k]) {
            k = int(constNum * (flash - minVal));
            int temp = a[t = --Buckets[k]];
            a[t] = flash;
            flash = temp;
            ++countswapElements;
        }
    }
    delete[] Buckets;
    for (int i = 1; ++count_cmp && i < n; i++) {
        int temp = a[i];
        int pos = i - 1;
        while (++count_cmp && pos >= 0 && ++count_cmp && a[pos] > temp) {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = temp;
    }
}