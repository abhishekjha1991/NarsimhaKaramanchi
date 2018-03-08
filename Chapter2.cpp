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

inline unsigned short findMaxConnectivityUtil(int arr[][5], unsigned short m, unsigned short n){
    int temp = 0;
    arr[m][n] = -32768;

    short Direction[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                            {0, 1}, {1, -1}, {1, 0}, {1,1}};

    for(unsigned short loop1=0; loop1<8; loop1++){
        short newRow = m+Direction[loop1][0];
        short newCol = n+Direction[loop1][1];
        if(newRow < 0 || newRow > 4 || newCol < 0 || newCol > 4 || arr[newRow][newCol] != 1){
            continue;
        }else{
            temp = temp + findMaxConnectivityUtil(arr, newRow, newCol);
        }
    }

    return 1+temp;
}

inline void findMaxConnectivity(int arr[][5]){
    int maxConnectivity = 0;
    for(unsigned short loop1=0; loop1<5; loop1++){
        for(unsigned short loop2=0; loop2<5; loop2++){
            if(arr[loop1][loop2] == 1){
                int temp = findMaxConnectivityUtil(arr, loop1, loop2);
                if(temp > maxConnectivity){
                    maxConnectivity = temp;
                }
            }
        }
    }

    cout<< "Max connectivity :" << maxConnectivity << endl;
}

inline void generateAllStringsOfNBitsUtil(int arr[], int n, unsigned int size){
    if(n==0){
        for(unsigned int loop1=0; loop1<size; loop1++){
            cout << arr[loop1];
        }
        cout << " ";
    }else{
        arr[n-1] = 0;
        generateAllStringsOfNBitsUtil(arr, n-1, size);
        arr[n-1] = 1;
        generateAllStringsOfNBitsUtil(arr, n-1, size);
    }
}

inline void generateAllStringsOfNBits(int n){
    if(n < 1){
        cout << "Invalid size : " << n << endl;
        return;
    }

    int *arr = new int[n]();
    generateAllStringsOfNBitsUtil(arr, n, n);
    cout << endl;
    delete arr;
}

inline void generateAllStringsOfLengthNDrawnFrom1ToKUtil(int arr[], int n, unsigned int k, unsigned int size){
    if(n == 0){
        for(unsigned int loop1=0; loop1<size; loop1++){
            cout << arr[loop1];
        }
        cout << " ";
    }else{
        for(unsigned int loop1=1; loop1<=k; loop1++){
            arr[n-1]=loop1;
            generateAllStringsOfLengthNDrawnFrom1ToKUtil(arr, n-1, k, size);
        }
    }
}

inline void generateAllStringsOfLengthNDrawnFrom1ToK(int n, int k){
    if(n < 1 || k < 1){
        cout << "Invalid inputs." << endl;
        return;
    }

    int *arr = new int[n]();
    generateAllStringsOfLengthNDrawnFrom1ToKUtil(arr, n, k, n);
    cout << endl;
    delete arr;
}


inline void generatePermutationsUtil(char str[], unsigned int first, unsigned int last){
    if(first == last){
        cout << str << " ";
    }else{
        for(unsigned int loop1=first; loop1<last; loop1++){
            char temp = str[first];
            str[first] = str[loop1];
            str[loop1] = temp;
            generatePermutationsUtil(str, first+1, last);
            temp = str[first];
            str[first] = str[loop1];
            str[loop1] = temp;
        }
    }
}

inline void generatePermutations(char str[], int size){
    if((str != 0 && str[0] == '\0') || size == 0){
        cout << "Invalid string." << str << endl;
        return;
    }
    generatePermutationsUtil(str, 0, size);
}

#endif
