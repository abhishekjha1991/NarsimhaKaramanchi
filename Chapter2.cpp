#ifndef CHAPTER_2
#define CHAPTER_2

#include <iostream>

using namespace std;

inline unsigned long long factorialRecursionUtil(unsigned int n){
    if(n == 0 || n == 1){
        return 1;
    }else{
        return (unsigned long long)(n*factorialRecursionUtil(n-1));
    }
}

inline void factorialRecursion(int n){
    if(n < 0){
        cout << "Factorial not defined for negative integers." << endl;
    }else{
        cout << "factorialRecursive(" << n << ")=" << factorialRecursionUtil(n) << endl;
    }
}

inline unsigned long long factorialIterativeUtil(unsigned int n){
    unsigned long long fac = 1;
    for(unsigned int loop1=1; loop1<=n; loop1++){
        fac *= loop1;
    }

    return fac;
}

inline void factorialIterative(int n){
    if(n < 0){
        cout << "Factorial not defined for negative integers." << endl;
    }else{
        cout << "factorialIterative(" << n << ")=" << factorialIterativeUtil(n) << endl;
    }
}

inline void printNumbersBackwardRecursiveUtil(int n){
    cout << "Printing backward : ";
    while(n){
        cout << n-- << " ";
    }
}

inline void printNumbersBackwardRecursive(int n){
    if(n < 0){
        cout << "This function is defined for only non negative integers." << endl;
        return;
    }

    return printNumbersBackwardRecursiveUtil(n);
}

inline void towersOfHanoiUtil(char src, char dest, char temp, int plates){
    if(plates == 0){
        return;
    }

    towersOfHanoiUtil(src, temp, dest, plates-1);
    cout << "Move a plate from " << src << " to " << dest << endl;
    towersOfHanoiUtil(temp, dest, src, plates-1);
}

inline void towersOfHanoi(char src, char dest, char temp, int plates){
    if(plates < 1){
        cout << "Invalid number of plates : " << plates;
        return;
    }

    cout << endl << "Number of plates : " << plates << endl;
    return towersOfHanoiUtil(src, dest, temp, plates);
    cout << endl;
}

inline bool checkIfSortedRecursionUtil(int arr[], int n){
    if(n == 0){
        return true;
    }else{
        return ((arr[n]>=arr[n-1]) && checkIfSortedRecursionUtil(arr, n-1));
    }
}

inline void checkIfSortedRecursion(int arr[], int size){
    if( false == checkIfSortedRecursionUtil(arr, size-1)){
        cout << "Unsorted array." << endl;
    }else{
        cout << "Sorted array." << endl;
    }
}
#endif
