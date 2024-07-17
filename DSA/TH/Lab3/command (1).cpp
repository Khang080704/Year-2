
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>

#include "AllSort.h"
#include "DataGenerator.h"
using namespace std;
using namespace std::chrono;
using namespace std::literals::chrono_literals;

typedef std::chrono::duration<double, std::milli> Time;

void copyArr(int* arr, int* subArr, int n) {
    for (int i = 0; i < n; i++) {
        subArr[i] = arr[i];
    }
}
enum input_order {
    RANDOMIZED,
    NEARLY_SORTED,
    SORTED,
    RESERVE_SORT,
    INVALID_ORDER
};

enum algorithm_name {
    SELECTON,
    INSERTION,
    BUBBLE,
    SHAKER,
    SHELL,
    HEAP,
    MERGE,
    QUICK,
    COUNTING,
    RADIX,
    FLASH,
    INVALID
    
};

void Help() {
    cout << "Wrong syntax" << endl;
    cout << "Mode:" << endl;
    cout << "- a: Algorithm mode\t\t\t- c : Comparison mode\n";
        
    cout << "Algorithm name :Lowercase, words are connected by " - "\n";
    cout << "Input size :Integer(≤ 1, 000, 000)\n";
    cout << "Input order :\n";
    cout << "- rand : randomized data\n"
        << "- nsorted : nearly sorted data\n "
        << "-sorted: sorted data\n"
        << "- rev : reverse sorted data\n";
       
}
void copyArray(int* a, int* suba, int n) {
    for (int i = 0; i < n; i++) {
        suba[i] = a[i];
    }
}
int defineInputOrder(string inputOrder) {
    int type = INVALID_ORDER ;
    if (inputOrder == "-rand") {
        type = RANDOMIZED;
        return type;
    }
    else if (inputOrder == "-nsorted") {
        type =NEARLY_SORTED;
        return type;
    }
    else if (inputOrder == "-sorted") {
        type = SORTED;
        return type;
    }
    else if (inputOrder == "-rev") {
        type = RESERVE_SORT;
        return type;
    }
    return type;
}

int defineAlgorithmName(string name) {
    int type = INVALID ;
    if (name == "selection-sort") {
        type = SELECTON;
        return type;
    }
        
    else if (name == "insertion-sort") {
        type = INSERTION;
        return type;
    }
        
    else if (name == "bubble-sort") {
        type = BUBBLE;
        return type;
    }
        
    else if (name == "shaker-sort") {
        type = SHAKER;
        return type;
    }
    else if (name == "shell-sort") {
        type = SHELL;
        return type;
    }
        
    else if (name == "heap-sort") {
        type = HEAP;
        return type;
    }
        
    else if (name == "merge-sort") {
        type = MERGE;
        return type;
    }
        
    else if (name == "quick-sort") {
        type = QUICK;
        return type;
    }
        
    else if (name == "counting-sort") {
        type = COUNTING;
        return type;
    }
        
    else if (name == "radix-sort") {
        type = RADIX;
        return type;
    }
        
    else if (name == "flash-sort") {
        type = FLASH;
        return type;
    }
        
    return type;
}
void inputCommand(int type, int* a, int size) {
    switch (type) {
    case NEARLY_SORTED: {
        GenerateNearlySortedData(a, size);
        break;
    }
    case RANDOMIZED: {
        GenerateRandomData(a, size);
        break;
    }
    case SORTED: {
        GenerateSortedData(a, size);
    }
    case RESERVE_SORT: {
        GenerateReverseData(a, size);
    }
    default:
        Help();
    }
}

double runningTime(int type, int* a, int size, long long& count_cmp) {
    count_cmp = 0;
    switch (type) {
    case SELECTON: {
        auto start = steady_clock::now();
        insertionSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case INSERTION: {
        auto start = steady_clock::now();
        insertionSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case BUBBLE: {
        auto start = steady_clock::now();
        bubbleSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case SHAKER: {
        auto start = steady_clock::now();
        shakerSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case SHELL: {
        auto start = steady_clock::now();
        shellSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case HEAP: {
        auto start = steady_clock::now();
        heapSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case MERGE: {
        auto start = steady_clock::now();
        mergeSort(a, 0, size - 1, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case QUICK: {
        auto start = steady_clock::now();
        quickSort(a, 0, size - 1, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case COUNTING: {
        auto start = steady_clock::now();
        countingSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case RADIX: {
        auto start = steady_clock::now();
        radixSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    case FLASH: {
        auto start = steady_clock::now();
        flashSort(a, size, count_cmp);
        auto end = steady_clock::now();
        Time dur = end - start;
        return dur.count();
    }
    default:
        return INT_MIN;
    }
}
void printAlgorithmName(int type) {
    switch (type) {
    case SELECTON: {
        cout << "Selection sort";
        return;
    }
    case INSERTION: {
        cout << "Insertion sort";
        return;
    }
    case BUBBLE: {
        cout << "Bubble sort";
        return;
    }
    case SHAKER: {
        cout << "Shaker sort";
        return;
    }
    case SHELL: {
        cout << "Shell sort";
        return;
    }
    case HEAP: {
        cout << "Heap sort";
        return;
    }
    case MERGE: {
        cout << "Merge sort";
        return;
    }
    case QUICK: {
        cout << "Quick sort";
        return;
    }
    case COUNTING: {
        cout << "Counting sort";
        return;
    }
    case RADIX: {
        cout << "Radix sort";
        return;
    }
    case FLASH: {
        cout << "Flash sort";
        return;
    }
    }
}
void printInputOrder(int type) {
    switch (type) {
    case NEARLY_SORTED: {
        cout << "Nearly sorted";
        return;
    }
    case RANDOMIZED: {
        cout << "Randomized";
        return;
    }
    case SORTED: {
        cout << "Sorted";
        return;
    }
    case RESERVE_SORT: {
        cout << "Reserve sorted";
        return;
    }
    
    }
}
void writeInputToFile(int* a, int size, int typeCmd) {
    if (typeCmd == RANDOMIZED) {
        ofstream writer("input_1.txt");
        writer << size << endl;
        for (int i = 0; i < size; i++) {
            writer << a[i] << " ";
        }

        writer.close();
        return;
    }
    else if (typeCmd == NEARLY_SORTED) {
        ofstream writer("input_2.txt");
        writer << size << endl;
        for (int i = 0; i < size; i++) {
            writer << a[i] << " ";
        }

        writer.close();
        return;
    }
    else if (typeCmd == SORTED) {
        ofstream writer("input_3.txt");
        writer << size << endl;
        for (int i = 0; i < size; i++) {
            writer << a[i] << " ";
        }

        writer.close();
        return;
    }
    else if (typeCmd == RESERVE_SORT) {
        ofstream writer("input_4.txt");
        writer << size << endl;
        for (int i = 0; i < size; i++) {
            writer << a[i] << " ";
        }

        writer.close();
        return;
    }
    else if (typeCmd == 5) {
        ofstream writer("input.txt");
        writer << size << endl;
        for (int i = 0; i < size; i++) {
            writer << a[i] << " ";
        }

        writer.close();
        return;
    }

}


void readFileInput(string filename, int*& a, int& size) {
    ifstream reader(filename);
    reader >> size;
    a = new int[size];
    for (int i = 0; i < size; i++) {
        reader >> a[i];
    }
    
    reader.close();
}

void outputCommand_3(int typeOrder, long long count_cmp, string OutputParameter,double timeSort) {
    cout << "Input order: "; 
    printInputOrder(typeOrder);
    cout << endl;
    cout << "-----------------------------------------\n";
    if (OutputParameter == "-time") {
        cout << "Running time: " << timeSort << "ms\n";
    }
    else if (OutputParameter == "-comp") {
        cout << "Comparisons: " << count_cmp << "ms\n";
    }
    else {
        cout << "Running time: " << timeSort << "ms\n";
        cout << "Comparisons: " << count_cmp << "ms\n";
    }
    
}
void Command_2(string algorithm, string inputSize, string inputOrder, string OutputParameter) {
    int size = stoi(inputSize);
    if (size > 1000000) {
        Help();
        return;
    }

    int typeOrder = defineInputOrder(inputOrder);
    if (typeOrder == INVALID_ORDER) {
        Help();
        return;
    }

    int algorithmName = defineAlgorithmName(algorithm);
    if (algorithmName == INVALID) {
        Help();
        return;
    }

    long long count_cmp = 0;
    int* arr = new int[size];
    inputCommand(typeOrder, arr, size);

    writeInputToFile(arr, size, 5);

    double timeSort = runningTime(algorithmName, arr, size, count_cmp);

    outputCommand_3(typeOrder, count_cmp, OutputParameter, timeSort);

    delete[] arr;
}

void Command_3(string algorithm, string inputSize, string OutputParameter) {
    int size = stoi(inputSize);
    if (size > 1000000) {
        Help;
        return;
    }
    
    int algorithmName = defineAlgorithmName(algorithm);
   
    if (algorithmName == INVALID ) {
        Help;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        long long count_cmp = 0;
        int* arr = new int[size];
        inputCommand(i, arr, size);
        writeInputToFile(arr, size, i);
        double timeSort = runningTime(algorithmName, arr, size, count_cmp);
        outputCommand_3(i,count_cmp, OutputParameter,timeSort);
        delete[] arr;
       
    }
}

void outputCommand4(string algorithm1, string algorithm2, int size, string filename,
    double timeSort1, double timeSort2, long long count_cmp1, long long count_cmp2) {
    cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
    cout << "Input file: " << filename << endl;
    cout << "Input size: " << size << endl;
    cout << "-----------------------------------------\n";
    cout << "Running time: " << timeSort1 << " | " << timeSort2 << endl;
    cout << "Comparisions: " << count_cmp1 << " | " << count_cmp2 << endl;
}
void Command_4(string algorithm1, string algorithm2, string filename) {
    int size = 0;
      
    if (size > 1000000) {
        Help;
        return;
    }

    int name1 = defineAlgorithmName(algorithm1);
    int name2 = defineAlgorithmName(algorithm2);
    if (name1 == INVALID || name2 == INVALID) {
        Help;
        return;
    }
    int* arr;
    readFileInput(filename, arr, size);

    long long count_cmp1 = 0;
    long long count_cmp2 = 0;
   
    int* subArr = new int[size];
    copyArray(arr, subArr, size);
    double timeSort1 = runningTime(name1, arr, size, count_cmp1);
    delete[] arr;

    double timeSort2 = runningTime(name2, subArr, size, count_cmp2);
    delete[] subArr;
    outputCommand4(algorithm1,algorithm2,size,filename, timeSort1,timeSort2,count_cmp1,count_cmp2);

}
void outputCommand5(string algorithm1, string algorithm2, string inputSize, string inputOrder,
    double timeSort1, double timeSort2, long long count_cmp1, long long count_cmp2) {
    cout << "Algorithm: " << algorithm1
        << " | " << algorithm2 << endl;
    cout << "Input size: " << inputSize << endl;
    cout << "Input order: " << inputOrder << endl;
    cout << "-----------------------------------------\n";
    cout << "Running time: " << timeSort1 << " | " << timeSort2 << endl;
    cout << "Comparisions: " << count_cmp1 << " | " << count_cmp2 << endl;
}
void Command_5(string algorithm1, string algorithm2, string inputSize, string inputOrder) {
    int size = stoi(inputSize);
    if (size > 1000000) {
        Help;
        return;
    }

    int typeOrder = defineInputOrder(inputOrder);
    if (typeOrder == INVALID_ORDER) {
        Help;
        return;
    }
    int name1 = defineAlgorithmName(algorithm1);
    int name2 = defineAlgorithmName(algorithm2);
    if (name1 == INVALID || name2 == INVALID) {
        Help;
        return;
    }
    long long count_cmp1 = 0;
    long long count_cmp2 = 0;
    int* arr = new int[size];
    inputCommand(typeOrder, arr, size);
    writeInputToFile(arr, size,5);
    int* subArr = new int[size];
    copyArray(arr, subArr, size);
    double timeSort1 = runningTime(name1, arr, size, count_cmp1);
    delete[] arr;

    double timeSort2 = runningTime(name2, subArr, size, count_cmp2);
    delete[] subArr;
    outputCommand5(algorithm1, algorithm2, inputSize, inputOrder, timeSort1, timeSort2, count_cmp1, count_cmp2);
}


int main(int argc, char* argv[]) {
    string MODECOMP = "-c";
    string MODEAL = "-a";
    string time_param = "-time";
    string comp_param = "-comp";
    string both_param = "-both";
    if (argv[1] == MODECOMP) {
        if (argc == 6) {
            Command_5(argv[2], argv[3], argv[4], argv[5]);
        }
        if (argc == 5) {
            Command_4(argv[2], argv[3], argv[4]);

        }
        else {
            Help();
        }
        
    }
    else if (argv[1] == MODEAL) {

    }
    if (argc == 7 && argv[1] == MODEAL && string(argv[6]) == "-time") {
        Command_2(argv[2], argv[3], argv[4], argv[5]);
    }
    else {
        Help();
    }
     
    
   
    return 0;
}
