

#include"DataGenerator.h"
#include"AllSort.h"
#include<chrono>
using namespace std;
using namespace std::chrono;
using namespace std::literals::chrono_literals;


void copyArr(int* arr, int* subArr, int n) {
    for (int i = 0; i < n; i++) {
        subArr[i] = arr[i];
    }
}
void printTimeAndCounting(int* a, int n, int k, long long& count_cmp) {
    switch (k) {
    case 0: {
        cout << "Selection sort: ";
        auto start = steady_clock::now();
        selectionSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 1: {
        cout << "Insertion sort: ";
        auto start = steady_clock::now();
        insertionSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 2: {
        cout << "Bubble sort: ";
        auto start = steady_clock::now();
        bubbleSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 3: {
        cout << "Shaker sort: ";
        auto start = steady_clock::now();
        shakerSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 4: {
        cout << "Shell sort: ";
        auto start = steady_clock::now();
        shellSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 5: {
        cout << "Heap Sort: ";
        auto start = steady_clock::now();
        heapSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 6: {
        cout << "Merge sort: ";
        auto start = steady_clock::now();
        mergeSort(a, 0, n - 1, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 7: {
        cout << "Quick sort: ";
        auto start = steady_clock::now();
        quickSort(a, 0, n - 1, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 8: {
        cout << "Counting sort: ";
        auto start = steady_clock::now();
        countingSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 9: {
        cout << "Radix sort: ";
        auto start = steady_clock::now();
        radixSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    case 10: {
        cout << "Flash sort: ";
        auto start = steady_clock::now();
        flashSort(a, n, count_cmp);
        auto end = steady_clock::now();
        duration<double, std::milli> dur1 = end - start;
        cout << "\tdur1 = " << dur1.count() << "ms\t\t";
        cout << count_cmp << endl;
        break;
    }
    }
}
void PrintDataOrder(int i) {
    switch (i) {
    case 0:
        cout << "\t\t --------RANDOM_DATA---------" << endl;
        break;
    case 1:
        cout << "\t\t --------SORTED_DATA---------" << endl;
        break;
    case 2:
        cout << "\t\t --------REVERSE_DATA---------" << endl;
        break;
    case 3:
        cout << "\t\t --------NSORTED_DATA---------" << endl;
        break;
    }
}
int main() {
    //for (int i = 0; i < 4; i++) {
    PrintDataOrder(0);
    for (int j = 0; j < 6; j++) {
        cout << endl;
        int size = GenerateSize(j);
        int* arr = new int[size];
        GenerateData(arr, size, 0);
        for (int k = 0; k < 11; k++) {
            int* subArr = new int[size];
            copyArr(arr, subArr, size);
            long long count_cmp = 0;
            printTimeAndCounting(subArr, size, k, count_cmp);
            delete[] subArr;
        }
        delete[] arr;
       
    }

    //}
}


