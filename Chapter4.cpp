#ifndef CHAPTER_4
#define CHAPTER_4
#include "include\Stack.h"
#include "include\Util.h"

inline void BasicStackTesting(){
    Stack<int> myStack;
    cout << "isEmpty() " << bool(myStack.isEmpty()) << endl;
    cout << myStack.top() << endl;
    myStack.pop();
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.pop();
}

inline bool testBalancedSymbolsUtil(const char* str){
    Stack<char> testStack = Stack<char>(Util::getCStringSize(str));
    const char* ptr = str;
    while(*ptr != '\0'){
        if(*ptr == '{' || *ptr == '[' || *ptr == '('){
            testStack.push(*ptr);
            //cout << "Pushed : " << *ptr << endl;
        }else if(*ptr == '}' || *ptr == ']' || *ptr == ')'){
            if(testStack.isEmpty()){
                return false;
            }else{
                char top = testStack.top();
                testStack.pop();
                //cout << "Top : " << top << endl;
                if((*ptr == '}' && top != '{') ||
                    (*ptr == ']' && top != '[') ||
                    (*ptr == ')' && top != '(')){
                        return false;
                }
            }
        }

        ptr++;
    }

    if(testStack.isEmpty() == true){
        return true;
    }else{
        return false;
    }
}

inline void testBalancedSymbols(){
    char testStrings[][20] = {"{(a*b)}$c}\0", "[{(a*b)}~c}\0", "[{(a*b)}&c]\0", "{{(a*b)}*c}\0", "(A+B)+(C+D)", "((A+B)+(C-D)",
                                "((A+B)+[C-D])", "((A+B)+[C-D]}"};
    for(unsigned short loop1=0; loop1<8; loop1++){
        cout << "Is " << testStrings[loop1] << " balanced ? ";
        testBalancedSymbolsUtil(testStrings[loop1])?cout<<"True":cout<<"False";
        cout << endl;
    }
}

inline void testFindMinInConstantTime(){
    int arr[] = {5,1,4,6,2,0,-1,3,-1};
    int size = 9;

    Stack<int> mainStack(size);
    MinStack<int> minStack(size);
    for(unsigned short loop1=0; loop1<size; loop1++){
        mainStack.push(arr[loop1]);
        minStack.push(arr[loop1]);
        cout << " Min now: " << minStack.top() << endl;
    }

    while(mainStack.isEmpty() == false){
        cout << " Min now: " << minStack.top() << endl;
        minStack.pop(mainStack.top());
        mainStack.pop();
    }
}

inline bool testPalindromeUsingStackUtil(const char* str){
    unsigned int size = Util::getCStringSize(str);
    Stack<char> myStack(size);
    for(unsigned int loop1=0; loop1<size; loop1++){
        myStack.push(str[loop1]);
    }

    for(unsigned int loop1=0; loop1<size; loop1++){
        if(myStack.top() != str[loop1]){
            return false;
        }
        myStack.pop();
    }

    return true;
}

inline void testPalindromeUsingStack(){
    char str[][20] = {"abccba\0","abccbaa\0", "abcbcba\0", "abcbcbab\0", "babcbcbab\0"};
    for(unsigned short loop1=0; loop1<5; loop1++){
        bool result = testPalindromeUsingStackUtil(str[loop1]);
        cout << "Palindrom(" << str[loop1] <<") : "; (result==1)?cout<<"True":cout<<"False"; cout<<endl;
    }
}

/*inline void testReverseAStackUsingRecursionUtil(Stack<int>& myStack){
    if(myStack.isEmpty()){
        return;
    }

    int ele = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, );
    myStack.push(ele);
}


inline void testReverseAStackUsingRecursion(){
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    testReverseAStackUsingRecursionUtil(myStack);
    cout << "Reversed Stack : ";
    cout << myStack.top() << " ";
    myStack.pop();
    cout << myStack.top() << " ";
    myStack.pop();
    cout << myStack.top() << " ";
    myStack.pop();
    cout << myStack.top() << " ";
    myStack.pop();
    cout << myStack.top() << " ";
    myStack.pop();
}*/

#endif // CHAPTER_4
