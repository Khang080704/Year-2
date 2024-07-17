#pragma once

#include<iostream>
using namespace std;

void SWAP(int& a, int& b);
void selectionSort(int a[], int n, long long& count_cmp);
void insertionSort(int arr[], int n, long long& count_cmp);
void bubbleSort(int arr[], int n, long long& count_cmp);
void shakerSort(int a[], int n, long long& count_cmp);
void shellSort(int arr[], int n, long long& count_cmp);
void heapify(int arr[], int n, int i, long long& count_cmp);
void heapSort(int arr[], int n, long long& count_cmp);
void merge(int array[], int left, int mid,
    int right, long long& count_cmp);
void mergeSort(int array[], int begin, int end, long long& count_cmp);
int LomutoPartition(int a[], int low, int high, long long& count_cmp);
void quickSort(int a[], int low, int high, long long& count_cmp);
void countingSort(int a[], int n, long long& count_cmp);
void countSort(int a[], int n, int exp, long long& count_cmp);
void radixSort(int a[], int n, long long& count_cmp);
void flashSort(int a[], int n, long long& count_cmp);


