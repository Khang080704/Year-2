#pragma once
#include "AllSort.h"
#include<vector>
using namespace std;


void SWAP(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//----------------selection sort ---------------------
void selectionSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    int index = -1;  // Bước 1: Khởi tạo biến index.

    // Bước 2: Lặp lại quá trình sau để sắp xếp mảng banSao
    while (++count_cmp && index < n) {
        // Tìm vị trí của giá trị nhỏ nhất trong mảng con chưa sắp xếp (s1)
        int minIndex = index + 1;  // Khởi tạo lính canh MIN
        for (int i = index + 1; ++count_cmp && i < n; i++) {
            if (++count_cmp && a[i] < a[minIndex]) {
                minIndex = i;
            }
        }
        // Tráo giá trị ở vị trí Index+1 và vị trí chứa giá trị nhỏ nhất.
        SWAP(a[index + 1], a[minIndex]);

        index++;  // Tăng kích thước của mảng con đã được sắp xếp
    }

    // Bước 3: Trả về mảng kết quả cuối cùng.
}

//----------------insertion sort ---------------------
void insertionSort(int arr[], int n, long long& count_cmp) {
    count_cmp = 0;
    int i, key, j;

    for (i = 1; ++count_cmp && i < n; i++) {
        key = arr[i];
        // Luu lai gia tri phan tu can chen
        // Bat dau tu vi tri thu 2 trong mang
        j = i - 1;
        // So sanh key voi phan tu truoc no

        // Duyet mang j tu 0 den i-1 neu arr[j] > key thi chen
        // key truoc vi tri hien tai cua no
        // Vi du so sanh 12 voi 11, ban dau key la 11, 12 > 11
        while (++count_cmp && j >= 0 && ++count_cmp && arr[j] > key) {
            arr[j + 1] = arr[j];
            // gan vi tri co gia tri 11 thanh gia tri 12
            j = j - 1;
        }
        arr[j + 1] = key;
        // gan vi tri co gia tri 12 thanh gia tri 11
    }
}

//----------------bubble sort ---------------------
void bubbleSort(int arr[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int i = 0; ++count_cmp && i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; ++count_cmp && j < n - i - 1; j++) {
            if (++count_cmp && arr[j] > arr[j + 1]) {
                swapped = true;
                SWAP(arr[j], arr[j + 1]);
            }
        }
        if (++count_cmp && !swapped) break;
    }
}

//----------------shaker sort ---------------------
void shakerSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    // Bước 1: Duyệt mảng từ trái sang phải đẻ dìm phần tử lớn nhất chìm xuống cuối mảng và duyệt từ phải sang trái để nâng phần tử nhỏ nhất nổi lên đầu mảng.
    // Đồng thời khởi tạo biến count.
    // Bước 2: Lặp lại Bước 1 với điều kiện dừng count = 0.
    int count = INT_MIN;
    while (++count_cmp && count != 0) {
        count = 0;

        // Duyệt từ trái sáng phải
        for (int i = 0; ++count_cmp && i < n - 1; i++) {
            if (++count_cmp && a[i] > a[i + 1]) {
                SWAP(a[i], a[i + 1]);
                count++;
            }
        }

        // Duyệt từ phải sang trái
        for (int i = n - 1; ++count_cmp && i > 0; i--) {
            if (++count_cmp&& a[i] < a[i - 1]) {
                SWAP(a[i], a[i - 1]);
                count++;
            }
        }
    }
}
//----------------shell sort ---------------------
void shellSort(int arr[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int gap = n / 2; ++count_cmp && gap > 0; gap /= 2) {
        for (int i = gap; ++count_cmp && i < n; i += 1) {
            int temp = arr[i];

            int j;
            for (j = i; ++count_cmp && j >= gap && ++count_cmp && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

//----------------heap sort ---------------------
void heapify(int arr[], int n, int i, long long& count_cmp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++count_cmp && left < n && ++count_cmp && arr[left] > arr[largest])
        largest = left;
    if (++count_cmp && right < n && ++count_cmp && arr[right] > arr[largest])
        largest = right;
    if (++count_cmp && largest != i) {
        SWAP(arr[i], arr[largest]);
        heapify(arr, n, largest, count_cmp);
    }
}

// Function to implement Heap Sort
void heapSort(int arr[], int n, long long& count_cmp) {
    count_cmp = 0;
    for (int i = n / 2 - 1; ++count_cmp && i >= 0; i--)
        heapify(arr, n, i, count_cmp);
    for (int i = n - 1; ++count_cmp && i >= 0; i--) {
        SWAP(arr[0], arr[i]);
        heapify(arr, i, 0, count_cmp);
    }
}

//----------------merge sort ---------------------
void merge(int array[], int left, int mid,
    int right, long long& count_cmp) {
    // mang thu nhat chay tu begin den mid
    // mang thu hai chay tu mid + 1 den end
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // Tao 2 mang temp luu ket qua cua mang con can tron
     int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    /*vector<int> leftArray(subArrayOne);
    vector<int> rightArray(subArrayTwo);*/

    // Sao chep du lieu vao 2 mang temp
    for (int i = 0; ++count_cmp && i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; ++count_cmp && j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Tron cac mang temp lai voi nhau, sap xep chung
    // va dat vao vi tri thich hop
    while (++count_cmp && indexOfSubArrayOne < subArrayOne && ++count_cmp && indexOfSubArrayTwo < subArrayTwo) {
        if (++count_cmp && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // neu 1 trong 2 mang left hoac right xong truoc
    // sao chep lai cac phan tu con lai cua left[], neu co
    while (++count_cmp && indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    delete[] leftArray;

    // sao chep lai cac phan tu con lai cua right[], neu co
    while (++count_cmp && indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
     
     delete[] rightArray;
}

void mergeSort(int array[], int begin, int end, long long& count_cmp) {
    if (++count_cmp && begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, count_cmp);
    mergeSort(array, mid + 1, end, count_cmp);
    // Cac thuat toan tren la chia mang thanh nhiu mang con

    // Buoc nay la tron lai
    merge(array, begin, mid, end, count_cmp);
}

//----------------quick sort ---------------------
int LomutoPartition(int a[], int low, int high, long long& count_cmp) {
    int mid = low + (high - low) / 2;
    int pivotIndex = -1;

    if ((++count_cmp && a[low] <= a[mid] && ++count_cmp && a[mid] <= a[high]) || (++count_cmp && a[high] <= a[mid] && ++count_cmp && a[mid] <= a[low]))
        pivotIndex = mid;
    else if ((++count_cmp && a[mid] <= a[low] && ++count_cmp && a[low] <= a[high]) || (++count_cmp && a[high] <= a[low] && ++count_cmp && a[low] <= a[mid]))
        pivotIndex = low;
    else
        pivotIndex = high;

    //SWAP(a[pivotIndex], a[high]);
    int temp1 = a[pivotIndex];
    int temp2 = a[high];
    a[pivotIndex] = temp2;
    a[high] = temp1;

    int i = low - 1;
    int pivot = a[high];
    int j = high + 1;
    while (++count_cmp&&true) {
        do {
            i++;
        } while (++count_cmp && a[i] < pivot);

        do {
            j--;
        } while (++count_cmp && a[j] > pivot);

        if (++count_cmp && i >= j)
            return j;

        //swap(a[i], a[j]);
        int tmp1 = a[i];
        int tmp2 = a[j];
        a[i] = tmp2;
        a[j] = tmp1;
    }
}



void quickSort(int a[], int low, int high, long long& count_cmp) {
    if (++count_cmp && low < high) {
        int index = LomutoPartition(a, low, high, count_cmp);
        quickSort(a, low, index, count_cmp);
        quickSort(a, index + 1, high, count_cmp);
    }
    return;
}

//----------------counting sort ---------------------
void countingSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    // Tim gia tri lon nhat cua mang de xac dinh kich thuoc cua mang
    int maxValue = a[0];
    for (int i = 0; ++count_cmp && i < n; i++) {
        if (++count_cmp && maxValue < a[i]) {
            maxValue = a[i];
        }
    }

    // Khoi tao mang dem voi gia tri la 0
    // Khoi tao mang ans de luu ket qua voi gia tri la 0
    // int* count = new int[maxValue];
    // int* ans = new int[n];

    // for (int i = 0; ++count_cmp && i < maxValue + 1; i++) {
    //     count[i] = 0;
    // }

    // for (int i = 0; ++count_cmp && i < n; i++) {
    //     ans[i] = 0;
    // }

    // // Dem so lan xuat hien cua moi phan tu trong day
    // for (int i = 0; ++count_cmp && i < n; i++) {
    //     count[a[i]]++;
    // }

    // // Tinh tong tich luy cua mang dem
    // for (int i = 1; ++count_cmp && i <= maxValue; i++) {
    //     count[i] = count[i] + count[i - 1];
    // }

    // // Luu ket qua vao mang ket qua

    // for (int i = n - 1; ++count_cmp && i >= 0; i--) {
    //     ans[--count[a[i]]] = a[i];
    // }

    // // Copy mang ket qua vao day so ban dau
    // for (int i = 0; ++count_cmp && i < n; i++) {
    //     a[i] = ans[i];
    // }
    // delete[] count;
    // delete[] ans;

    vector<int> count(maxValue + 1, 0);

    // // Dem so lan xuat hien cua moi phan tu trong day
    for (int i = 0; ++count_cmp && i < n; i++) {
        count[a[i]]++;
    }

    // // Tinh tong tich luy cua mang dem
    // for (int i = 1; i <= maxValue; i++) {
    //     count[i] = count[i] + count[i - 1];
    // }

    // // Luu ket qua vao mang ket qua

    // for (int i = n - 1; i >= 0; i--) {
    //     ans[--count[arr[i]]] = arr[i];
    // }

    // // Copy mang ket qua vao day so ban dau
    // for (int i = 0; i < n; i++) {
    //     arr[i] = ans[i];
    // }

    int index = 0;

    for (int i = 0; ++count_cmp && i <= maxValue; ++i) {
        while (++count_cmp &&count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

//----------------radix sort ---------------------

void countSort(int a[], int n, int exp, long long& count_cmp) {
    vector<int> arrayAfterDistributed(n);

    // Muoi ngan chua co gia tri tu 1-9 de chia cac
    // phan tu vao khi xet tung chu so
    int count[10]{ 0 };

    // Dung ky thuat cua counting sort
    // de phan chia cac chu so vao cac ngan
    for (int i = 0; ++count_cmp && i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    // cong don de xac dinh vi tri
    // cua cac phan tu
    // tren mang arrayAfterDistributed
    for (int i = 1; ++count_cmp && i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++count_cmp && i >= 0; i--) {
        arrayAfterDistributed[--count[(a[i] / exp) % 10]] = a[i];
    }

    for (int i = 0; ++count_cmp && i < n; i++) {
        a[i] = arrayAfterDistributed[i];
    }
}

void radixSort(int a[], int n, long long& count_cmp) {
    count_cmp = 0;
    //  Tim phan tu lon nhat trong mang
    //  de xac dinh so luong chu so lon nhat
    //  cua cac phan tu
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
void flashSort(int a[], int n, long long& count_cmp)
{
    count_cmp = 0;
    // Tinh so bucket de dem cac phan tu
    int numberOfBuckets = int(0.43 * n);

    // Tao cac buckets
    int* Buckets = new int[numberOfBuckets];
    for (int i = 0; ++count_cmp&&i < numberOfBuckets; i++)
        Buckets[i] = 0;

    int minVal = a[0];
    int maxPos = 0;
    for (int i = 1; ++count_cmp&&i < n; i++)
    {
        if (++count_cmp && a[i] < minVal)
            minVal = a[i];
        if (++count_cmp && a[i] > a[maxPos])
            maxPos = i;
    }

    if (++count_cmp && a[maxPos] == minVal)
        return;

    double constNum = (double)(numberOfBuckets - 1) / (a[maxPos] - minVal);
    // Dem so luong phan tu trong moi bucket
    for (int i = 0; ++count_cmp && i < n; i++)
    {
        int k = int(constNum * (a[i] - minVal));
        ++Buckets[k];
    }
    for (int i = 1; ++count_cmp && i < numberOfBuckets; i++)
        Buckets[i] += Buckets[i - 1];

    // Hoan vi toan cuc:
    SWAP(a[maxPos], a[0]);
    
    int i = 0; // bien chay tren mang
    int k = numberOfBuckets - 1;
    int t = 0;
    int flash;
    int countSWAP = 0;
    while (++count_cmp && countSWAP < n - 1)
    {   // Khi phan tu a[i] da thuoc dung Bucket
        // di chuyen sang phan tu tiep theo
        while (++count_cmp && i > Buckets[k] - 1)
        {
            i++;
            k = int(constNum * (a[i] - minVal));
        }
        
        if (++count_cmp && k < 0) break;
        flash = a[i];
        // Khi Bucket[k] chua day
        while (++count_cmp && i != Buckets[k])
        {
            k = int(constNum * (flash - minVal));
            int temp = a[t = --Buckets[k]];
            a[t] = flash;
            flash = temp;
            ++countSWAP;
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
