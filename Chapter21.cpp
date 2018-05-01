#ifndef CHAPTER_21
#define CHAPTER_21

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Util.h"

using namespace std;


void printMatrixSpirallyUtil(int mat[][4], int row, int col){
    int k=0, l=0;

    while(k<row && l<col){
        for(int i=l; i<col; i++){
            cout << mat[k][i] << " ";
        }
        k++;

        for(int i=k; i<row; i++){
            cout << mat[i][col-1] << " ";
        }
        col--;

        if(k<row){
            for(int i=col-1; i>=l; i--){
                cout << mat[row-1][i] << " ";
            }
            row--;
        }

        if(l<col){
            for(int i=row-1; i>=k; i--){
                    cout << mat[i][l] << " ";
            }
            l++;
        }
    }
}
void printMatrixSpirally(){
    int mat1[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}, {17,18,19,20}};  //5X4
    printMatrixSpirallyUtil(mat1, 5, 4);

    cout << endl;

    int mat2[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};     //3X4
    printMatrixSpirallyUtil(mat2, 3, 4);
}

void shuffleDeckOfCards(){
    enum Suit {Hearts=1, Clubs, Spades, Diamonds, None};

    class Card{
    public:
        Suit suit;
        unsigned int rank;
        ostream& operator<<(ostream &os){
            if(rank==1){
                os << "A";
            }else if(rank ==11){
                os << "J";
            }else if(rank ==12){
                os << "Q";
            }else if(rank ==13){
                os << "K";
            }else{
                os << rank;
            }

            os << (unsigned int)suit << endl;

            return os;
        }
    };

    Card Deck[52];

    int card = 0;
    for(unsigned int i=1; i<=4; i++){
        Suit suit;
        switch(i){
            case 1: suit = Hearts; break;
            case 2: suit = Clubs;  break;
            case 3: suit = Spades; break;
            case 4: suit = Diamonds; break;
        }

        for(int i=1; i<=13; i++){
            Deck[card].suit = suit;
            Deck[card].rank = i;
            card++;
        }
    }

    srand(time(NULL));
    for(int i=51; i>0; i--){
        int j = rand()%(i+1);
        Card temp = Deck[i];
        Deck[i] = Deck[j];
        Deck[j] = temp;
    }

    for(int i=0; i<52; i++){
        cout << Deck[i].rank << " " << (unsigned int)(Deck[i].suit) << endl;
    }
}

unsigned int countAllPossiblePathsUtil(int m, int n){
    if(m==0 || n==0){
        return 1;
    }

    return countAllPossiblePathsUtil(m-1, n) + countAllPossiblePathsUtil(m, n-1);
}

void countAllPossiblePaths(){
    cout << "No of pahs with m = 1 and n = 1 : " << countAllPossiblePathsUtil(1,1) << endl;
    cout << "No of pahs with m = 2 and n = 2 : " << countAllPossiblePathsUtil(2,2) << endl;
    cout << "No of pahs with m = 3 and n = 3 : " << countAllPossiblePathsUtil(3,3) << endl;
    cout << "No of pahs with m = 4 and n = 4 : " << countAllPossiblePathsUtil(4,4) << endl;
}

void moveSpacesToTheBeginningUsingSwaps(char str[]){
    cout << str << "  :  ";
    int i = Util::getCStringSize(str)-1;
    for(int j=i; j>=0; j--){
        if(str[j] != ' '){
            Util::swap(str[j], str[i--]);
        }
    }

    cout << str << endl;
}

void moveSpacesToTheBeginningWithoutSwaps(char str[]){
    cout << str << "  :  ";
    int i = Util::getCStringSize(str)-1;
    for(int j=i; j>=0; j--){
        if(str[j] != ' '){
            str[i--] = str[j];
        }
    }

    while(i>=0){
        str[i--] = ' ';
    }
    cout << str << endl;
}

void moveSpacesToTheBeginning(){
    char str[] = "move these spaces to the beginning.\0";
    moveSpacesToTheBeginningUsingSwaps(str);
    char str1[] = "move these spaces to the beginning.\0";
    moveSpacesToTheBeginningWithoutSwaps(str1);
}

void moveTheSpacesToTheEndUsingSwaps(char str[]){
    cout << str << "  :  ";
    for(int i=0, j=0; j<Util::getCStringSize(str);j++){
        if(str[j] != ' '){
            Util::swap(str[i++], str[j]);
        }
    }

    cout << str << endl;
}

void moveTheSpacesToTheEndWithoutSwaps(char str[]){
    cout << str << "  :  ";
    int i,j;
    for(i=0, j=0; j<Util::getCStringSize(str); j++){
        if(str[j] != ' '){
            str[i++] = str[j];
        }
    }

    while(i<Util::getCStringSize(str)){
        str[i++] = ' ';
    }

    cout << str << endl;
}
void moveTheSpacesToTheEnd(){
    char str[] = "move these spaces to the end.\0";
    moveTheSpacesToTheEndUsingSwaps(str);
    char str1[] = "move these spaces to the end.\0";
    moveTheSpacesToTheEndWithoutSwaps(str1);
}

void moveAllZerosToTheEndUtil(int arr[], unsigned int size){
    Util::printArray(arr, size);
    int i,j;
    for(i=0, j=0; j<size; j++){
        if(arr[j] != 0){
            Util::swap(arr[i++], arr[j]);
        }
    }

    cout << "After moving all zeros to the end : ";
    Util::printArray(arr, size);
}

void moveAllZerosToTheEnd(){
    int arr[] = {1,9,8,4,0,0,2,7,0,6,0};
    moveAllZerosToTheEndUtil(arr, sizeof(arr)/sizeof(arr[0]));
}

void segregatePositiveAndNegativeUtil(int arr[], int size){
    cout << "Array : "; Util::printArray(arr, size);
    int i, j;
    for(i=0, j=0; j<size; j++){
        if(arr[j]<0){
            Util::swap(arr[j], arr[i++]);
        }
    }

    cout << "After segregation : "; Util::printArray(arr, size);
}

void segregatePositiveAndNegative(){
    int arr[] = {-5, 3, 2, -1, 4, -8};
    segregatePositiveAndNegativeUtil(arr, sizeof(arr)/sizeof(arr[0]));
}

void rotateArrayBy1ElementEachTime(int arr[], int size, unsigned int d){
    int d1 = d%size;
    while(d1--){
        int firstElement = arr[0];
        for(int i=1; i<size; i++){
            arr[i-1] = arr[i];
        }
        arr[size-1] = firstElement;
    }

    cout << "After " << d << " rotations : "; Util::printArray(arr, size);
}

void rotateArrayByReversingInPartsAndThenInFull(int arr[], int size, unsigned int d){
    for(int i=0, j=d-1; i<j; i++,j--){
        Util::swap(arr[i], arr[j]);
    }

    for(int i=d, j=size-1; i<j; i++,j--){
        Util::swap(arr[i], arr[j]);
    }

    for(int i=0, k=size-1; i<k; i++,k--){
        Util::swap(arr[i], arr[k]);
    }

    cout << "After " << d << "rotations : "; Util::printArray(arr, size);
}

void rotateArray(){
    int arr[] = {1,2,3,4,5,6,7};
    rotateArrayBy1ElementEachTime(arr, sizeof(arr)/sizeof(arr[0]), 7);
    int arr1[] = {1,2,3,4,5,6,7};
    rotateArrayByReversingInPartsAndThenInFull(arr1, sizeof(arr1)/sizeof(arr1[0]), 7);
}
#endif // CHAPTER_21
