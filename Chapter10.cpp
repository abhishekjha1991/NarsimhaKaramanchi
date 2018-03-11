#ifndef CHAPTER_10
#define CHAPTER_10

#include <Sorting.h>
#include <iostream>

using namespace std;

inline void testBubbleSort(){
    cout << "Testing bubble sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::BubbleSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::BubbleSort(arr2, 12);
    Util::printArray(arr2, 12);
}

inline void testInsertionSort(){
    cout << "Testing insertion sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::InsertionSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::InsertionSort(arr2, 12);
    Util::printArray(arr2, 12);
}

inline void testSelectionSort(){
    cout << "Testing selection sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::SelectionSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::SelectionSort(arr2, 12);
    Util::printArray(arr2, 12);
}

inline void testRankSort(){
    cout << "Testing rank sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    int * rank = Util::generateRankArray(arr1, 10);
    Sorting<int>::RankSort(arr1, rank, 10);
    Util::printArray(arr1, 10);
    delete rank;

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0, -1};
    rank = Util::generateRankArray(arr2, 13);
    Sorting<int>::RankSort(arr2, rank, 13);
    Util::printArray(arr2, 13);
    delete rank;
}

inline void testQuickSort(){
    cout << "Testing quick sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::QuickSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::QuickSort(arr2, 12);
    Util::printArray(arr2, 12);

    int arr3[] = {-1,0,1,2,2,2,3,4,5,6,7,8};
    Sorting<int>::QuickSort(arr3, 12);
    Util::printArray(arr2, 12);

    int arr4[] = {-1,6,5,4,7,9,8,7,3,2,1,0, -1};
    Sorting<int>::QuickSort(arr4, 13);
    Util::printArray(arr4, 13);
}

inline void testHeapSort(){
    cout << "Testing heap sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::HeapSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::HeapSort(arr2, 12);
    Util::printArray(arr2, 12);

    int arr3[] = {-1,0,1,2,2,2,3,4,5,6,7,8};
    Sorting<int>::HeapSort(arr3, 12);
    Util::printArray(arr2, 12);

    int arr4[] = {-1,6,5,4,7,9,8,7,3,2,1,0, -1};
    Sorting<int>::HeapSort(arr4, 13);
    Util::printArray(arr4, 13);
}

inline void testMergeSort(){
    cout << "Testing merge sort." << endl;
    int arr1[] = {9,8,7,6,5,4,3,2,1,0};
    Sorting<int>::MergeSort(arr1, 10);
    Util::printArray(arr1, 10);

    int arr2[] = {-1,6,5,4,7,9,8,7,3,2,1,0};
    Sorting<int>::MergeSort(arr2, 12);
    Util::printArray(arr2, 12);

    int arr3[] = {-1,0,1,2,2,2,3,4,5,6,7,8};
    Sorting<int>::MergeSort(arr3, 12);
    Util::printArray(arr2, 12);

    int arr4[] = {-1,6,5,4,7,9,8,7,3,2,1,0, -1};
    Sorting<int>::MergeSort(arr4, 13);
    Util::printArray(arr4, 13);
}

#endif // CHAPTER_10
