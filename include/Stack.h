#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>

using namespace std;

class Error{
    public:
        Error(string str){
            errorString = str;
        }
        void setError(string str){
            errorString = str;
        }

        string getError(){
            return errorString;
        }
    private:
        string errorString;
};

template <class T>
class Stack
{
    public:
        /** Default constructor */
        Stack(int=5);
        /** Default destructor */
        virtual ~Stack();
        bool isEmpty();
        bool isFull();
        void push(T);
        void pop();
        T top();

    protected:

    private:
        T *arr;
        int size;
        int pointer;
};

template <class T>
Stack<T>::Stack(int size)
{
    //ctor
    this->size = size;
    pointer=-1;
    arr = new T[size];
    //cout << "Stack created of size : " << size << endl;
}

template <class T>
Stack<T>::~Stack()
{
    //dtor
    pointer = -1;
    delete arr;
    size = 0;
    //cout << "Stack deleted." << endl;
}

template <class T>
bool Stack<T>::isEmpty(){
    return (pointer == -1);
}

template <class T>
bool Stack<T>::isFull(){
    return (pointer == size-1);
}

template <class T>
void Stack<T>::push(T item){
    try{
        if(false == isFull()){
            pointer++;
            arr[pointer] = item;
        }else{
            Error error("Stack overflow.");
            throw error;
        }
    }catch(Error err){
        cout << "Error occured : " << err.getError() << endl;
    }
}

template<class T>
T Stack<T>::top(){
    // Note : Always check for non-empty stack before calling top.
    // Otherwise, it will return -32768 for empty stacks.
    try {
        if(false == isEmpty()){
            return arr[pointer];
        }else{
            throw Error("Empty Stack.");
        }
    }catch(Error err){
        cout << "Error occurred : " << err.getError() << endl;
        return -32768;
    }
}

template<class T>
void Stack<T>::pop(){
    try {
        if(false == isEmpty()){
            pointer--;
        }else{
            throw Error("Stack underflow.");
        }
    }catch(Error err){
        cout << "Error occurred : " << err.getError() << endl;
    }
}

template <class T>
class MinStack
{
    public:
        /** Default constructor */
        MinStack(int=5);
        /** Default destructor */
        virtual ~MinStack();
        bool isEmpty();
        bool isFull();
        void push(T);
        void pop(T);
        T top();

    protected:

    private:
        T *arr;
        int size;
        int pointer;
};

template <class T>
MinStack<T>::MinStack(int size)
{
    //ctor
    this->size = size;
    pointer=-1;
    arr = new T[size];
    //cout << "Stack created of size : " << size << endl;
}

template <class T>
MinStack<T>::~MinStack()
{
    //dtor
    pointer = -1;
    delete arr;
    size = 0;
    //cout << "Stack deleted." << endl;
}

template <class T>
bool MinStack<T>::isEmpty(){
    return (pointer == -1);
}

template <class T>
bool MinStack<T>::isFull(){
    return (pointer == size-1);
}

template <class T>
void MinStack<T>::push(T item){
    try{
        if(false == isFull()){
            if(isEmpty() || item <= top()){
                pointer++;
                arr[pointer] = item;
            }
        }else{
            Error error("Stack overflow.");
            throw error;
        }
    }catch(Error err){
        cout << "Error occured : " << err.getError() << endl;
    }
}

template<class T>
T MinStack<T>::top(){
    // Note : Always check for non-empty stack before calling top.
    // Otherwise, it will return -32768 for empty stacks.
    try {
        if(false == isEmpty()){
            return arr[pointer];
        }else{
            throw Error("Empty Stack.");
        }
    }catch(Error err){
        cout << "Error occurred : " << err.getError() << endl;
        return -32768;
    }
}

template<class T>
void MinStack<T>::pop(T item){
    try {
        if(false == isEmpty() && item == top()){
            pointer--;
        }else if(isEmpty()){
            throw Error("Stack underflow.");
        }
    }catch(Error err){
        cout << "Error occurred : " << err.getError() << endl;
    }
}

#endif // STACK_H
