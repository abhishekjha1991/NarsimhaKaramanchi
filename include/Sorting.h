#ifndef SORTING_H
#define SORTING_H

#include "Util.h"

template <typename T>
class Sorting
{
    public:
        /** Default constructor */
        Sorting() {}
        /** Default destructor */
        virtual ~Sorting()=0;
        static void BubbleSort(T [], const unsigned int);
        static void InsertionSort(T [], const unsigned int);
        static void SelectionSort(T [], const unsigned int);
        static void RankSort(T [], int[], const unsigned int);
        static void QuickSort(T [], const unsigned int);
        static void QuickSortUtil(T[], int, int);
        static const unsigned int QuickPartition(T[], int, int);
        static void maxHeapify(T[], unsigned int, const unsigned int);
        static void maxHeapDel(T[], unsigned int);
        static void HeapSort(T[], const unsigned int);
        static void Merge(T[], const unsigned int, const unsigned int, const unsigned int);
        static void MergeSortUtil(T[], int beg, int end);
        static void MergeSort(T[], const unsigned int);
    protected:

    private:
};

template <typename T>
void Sorting<T>::BubbleSort(T arr[], const unsigned int size){
    for(unsigned int loop1=0; loop1<size-1; loop1++){
        for(unsigned loop2=0; loop2<size-1-loop1; loop2++){
            if(arr[loop2] > arr[loop2+1]){
                Util::swap(arr[loop2], arr[loop2+1]);
            }
        }
    }
}

template <typename T>
void Sorting<T>::InsertionSort(T arr[], const unsigned int size){
    for(unsigned int loop1=1; loop1<size; loop1++){
        T item = arr[loop1];
        unsigned int loop2 = loop1;
        while(loop2>0 && arr[loop2-1]>item){
            arr[loop2] = arr[loop2-1];
            loop2--;
        }
        arr[loop2] = item;
    }
}

template<typename T>
void Sorting<T>::SelectionSort(T arr[], const unsigned int size){
    for(unsigned int loop1=0; loop1<size-1; loop1++){
        unsigned int maxIndex = Util::findMaxIndex(arr, size-loop1);
        Util::swap(arr[maxIndex], arr[size-loop1-1]);
    }
}

template<typename T>
void Sorting<T>::RankSort(T arr[], int rank[], const unsigned int size){
    for(unsigned int loop1=0; loop1<size; loop1++){
        while(rank[loop1] != loop1){
            Util::swap(arr[loop1], arr[rank[loop1]]);
            Util::swap(rank[loop1], rank[rank[loop1]]);
        }
    }
}

template<typename T>
const unsigned int Sorting<T>::QuickPartition(T arr[], int beg, int end){
    unsigned int index=beg;
    for(unsigned int loop1=beg+1; loop1<=end; loop1++){
        if(arr[loop1]<arr[beg]){
            index++;
            Util::swap(arr[loop1], arr[index]);
        }
    }

    Util::swap(arr[beg], arr[index]);
    return index;
}

template<typename T>
void Sorting<T>::QuickSortUtil(T arr[], int beg, int end){
    if(beg < end){
        const unsigned int pivotIndex = QuickPartition(arr, beg, end);
        QuickSortUtil(arr, beg, pivotIndex-1);
        QuickSortUtil(arr, pivotIndex+1, end);
    }
}

template<typename T>
void Sorting<T>::QuickSort(T arr[], const unsigned int size){
    QuickSortUtil(arr, 0, size-1);
}

template<typename T>
void Sorting<T>::maxHeapify(T arr[], unsigned int index, const unsigned int size){
    while(true){
        const unsigned int leftChild = 2*index+1, rightChild = 2*index+2;
        if(leftChild > size-1){
            // No child case : Node at index is leaf node
            break;
        }else if(rightChild <= size-1){
            // Both children case
            unsigned int maxIndex = arr[leftChild]>arr[rightChild]?leftChild:rightChild;
            if(arr[index] < arr[maxIndex]){
                Util::swap(arr[index], arr[maxIndex]);
                index = maxIndex;
            }else{
                break;
            }
        }else{
            // One child case
            if(arr[leftChild]>arr[index]){
                Util::swap(arr[index], arr[leftChild]);
            }

            break; // Had one child only, swapped or not, no more comparison possible
        }
    }
}

template<typename T>
void Sorting<T>::maxHeapDel(T arr[], const unsigned int size){
    for(unsigned int loop1=0; loop1<size-1; loop1++){
        Util::swap(arr[0], arr[size-loop1-1]);
        maxHeapify(arr, 0, size-loop1-1);
    }
}

template<typename T>
void Sorting<T>::HeapSort(T arr[], const unsigned int size){
    for(int loop1=size-1; loop1>=0; loop1--){
        maxHeapify(arr, loop1, size);
    }
    maxHeapDel(arr, size);
}

template<typename T>
void Sorting<T>::Merge(T arr[], const unsigned int beg, const unsigned int mid, const unsigned end){
    const unsigned size = end-beg+1;
    T *temp = new T[size];
    unsigned int pointer1 = beg, pointer2 = mid+1, pointer3 = 0;

    while(pointer1<=mid && pointer2<=end){
        if(arr[pointer1] < arr[pointer2]){
            temp[pointer3] = arr[pointer1];
            pointer1++, pointer3++;
        }else{
            temp[pointer3] = arr[pointer2];
            pointer2++, pointer3++;
        }
    }

    while(pointer1<=mid){
        temp[pointer3] = arr[pointer1];
        pointer1++, pointer3++;
    }

    while(pointer2<=end){
        temp[pointer3] = arr[pointer2];
        pointer2++, pointer3++;
    }

    unsigned int pointer4=beg;
    for(unsigned int loop1=0; loop1<pointer3; loop1++){
        arr[pointer4++] = temp[loop1];
    }

    delete temp;
}

template<typename T>
void Sorting<T>::MergeSortUtil(T arr[], int beg, int end){
    if(beg<end){
        int mid = (beg+end)/2;
        MergeSortUtil(arr, beg, mid);
        MergeSortUtil(arr, mid+1, end);
        Merge(arr, beg, mid, end);
    }
}

template<typename T>
void Sorting<T>::MergeSort(T arr[], const unsigned int size){
    MergeSortUtil(arr, 0, size-1);
}

#endif // SORTING_H
