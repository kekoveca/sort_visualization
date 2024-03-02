#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <vector>
#include "sortAlgorithms.hpp"

int main(){
    srand(time(0));

    std::vector<int> arrayToSort;
    arrayToSort.resize(ARR_SIZE);

    for(unsigned int i = 0; i < ARR_SIZE; i++) {
        arrayToSort[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(arrayToSort.begin(), arrayToSort.end(), g);

    BubbleSort(arrayToSort);
    ShakerSort(arrayToSort);
    CombSort(arrayToSort);
    InsertionSort(arrayToSort);
    QuickSort(arrayToSort);
    MergeSort(arrayToSort);
    HeapSort(arrayToSort);

    return 0;
}