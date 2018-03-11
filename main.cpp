#include "Chapter2.cpp"
#include "Chapter4.cpp"
#include "Chapter10.cpp"

void testFactorialUsingRecursion(){
    factorialRecursion(0);
    factorialRecursion(5);
    factorialRecursion(10);
    factorialRecursion(-3);
}

void testFactorialUsingIteration(){
    factorialIterative(0);
    factorialIterative(5);
    factorialIterative(10);
    factorialIterative(-3);
}

void testBackwardPrinting(){
    printNumbersBackwardRecursive(-11);
    printNumbersBackwardRecursive(11);
}

void testTowersOfHanoi(){
    towersOfHanoi('A', 'B', 'C', 0);
    towersOfHanoi('A', 'B', 'C', 1);
    towersOfHanoi('A', 'B', 'C', 2);
    towersOfHanoi('A', 'B', 'C', 5);
}

void testSortedArrayUsingRecursion(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    checkIfSortedRecursion(arr, 10);
    arr[0] = 2;
    checkIfSortedRecursion(arr, 10);
    arr[1] = 1;
    checkIfSortedRecursion(arr, 10);
}

void testLenghtOfConnectedCellsOf1s(){
    int arr[][5] = {{0, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 1, 1, 1},
                    {1, 1, 0, 0, 1},
                    {0, 1, 0, 1, 0}};

    findMaxConnectivity(arr);
}

void testGenerateAllStringsOfNBits(){
    generateAllStringsOfNBits(0);
    generateAllStringsOfNBits(1);
    generateAllStringsOfNBits(2);
}

void testGenerateAllStringsOfLengthNDrawnFrom1ToK(){
    generateAllStringsOfLengthNDrawnFrom1ToK(0, 0);
    generateAllStringsOfLengthNDrawnFrom1ToK(1, 0);
    generateAllStringsOfLengthNDrawnFrom1ToK(0, 1);
    generateAllStringsOfLengthNDrawnFrom1ToK(1, 5);
    generateAllStringsOfLengthNDrawnFrom1ToK(5, 1);
    generateAllStringsOfLengthNDrawnFrom1ToK(5, 2);
    generateAllStringsOfLengthNDrawnFrom1ToK(5, 5);
    generateAllStringsOfLengthNDrawnFrom1ToK(4, 5);
    generateAllStringsOfLengthNDrawnFrom1ToK(5, 4);
}

void testGeneratePermutations(){
    generatePermutations("\0", 2);
    char str[5] = {'a', 'b', 'c', 'd', '\0'};
    generatePermutations(str, 4);
}

void testChapter2(){
    testFactorialUsingRecursion();
    testFactorialUsingIteration();
    testBackwardPrinting();
    testTowersOfHanoi();
    testSortedArrayUsingRecursion();
    testLenghtOfConnectedCellsOf1s();
    testGenerateAllStringsOfNBits();
    testGenerateAllStringsOfLengthNDrawnFrom1ToK();
    testGeneratePermutations();
}

void testChapter4(){
    BasicStackTesting();
    testBalancedSymbols();
    testFindMinInConstantTime();
    testPalindromeUsingStack();
    //testReverseAStackUsingRecursion();
}

void testChapter10(){
    testBubbleSort();
    testInsertionSort();
    testSelectionSort();
    testRankSort();
    testQuickSort();
    testHeapSort();
    testMergeSort();
}

int main()
{
    //testChapter2();
    //testChapter4();
    testChapter10();
    cout << endl << endl << endl;
    return 0;
}
