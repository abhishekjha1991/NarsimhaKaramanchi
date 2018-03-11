#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using namespace std;

class Util
{
    public:
        /** Default constructor */
        Util();
        /** Default destructor */
        virtual ~Util() = 0;
        static int getCStringSize(const char*);

        template <typename T>
        static void swap(T& v1, T& v2){
            T temp = v1;
            v1 = v2;
            v2 = temp;
        }

        template<typename T>
        static void printArray(T arr[], unsigned int size){
            cout << "Array : ";
            for(unsigned int loop1=0; loop1<size; loop1++){
                cout << arr[loop1] << " ";
            }

            cout << endl;
        }

        template<typename T>
        static int findMaxIndex(T arr[], int size){
            unsigned int maxIndex = 0;
            for(unsigned int loop1=1; loop1<size; loop1++){
                if(arr[loop1] > arr[maxIndex]){
                    maxIndex = loop1;
                }
            }

            return maxIndex;
        }

        template<typename T>
        static int* generateRankArray(T arr[], int size){
            int *rankArray = new int[size];
            for(unsigned int loop1=0; loop1<size; loop1++){
                rankArray[loop1] = 0;
            }

            for(unsigned int loop1=0; loop1<size-1; loop1++){
                for(unsigned int loop2=loop1+1; loop2<size; loop2++){
                    if(arr[loop1]>arr[loop2]){
                        rankArray[loop1]++;
                    }else{
                        rankArray[loop2]++;
                    }
                }
            }
            return rankArray;
        }


    protected:

    private:
};

inline int Util::getCStringSize(const char* str){
    const char* ptr = str;
    unsigned int size = 0;
    while(*ptr++){
        size++;
    }
    return size;
}

#endif // UTIL_H
