//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab3/lab3.h
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 4 27 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
//  ================== END ASSESSMENT HEADER ===============
#ifndef ___LIST___
#define ___LIST___
#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class TwoStackFixed{
    private:
        T* list;
        int size1, size2, cap1, cap2, sizeT;
        bool isFullStack1(); //helper function to check whether first stack is full.
        bool isFullStack2(); //helper function to check whether second stack is full.
        bool isEmptyStack1(); //helper function to check whether first stack is empty.
        bool isEmptyStack2(); //helper function to check whether second stack is empty.
        
    public:
        TwoStackFixed(int size, int maxtop); //constructor that constructs array 
                                             //of size and constructs empty stacks
                                             //with maxtop specifying the partition for stacks. 
        void pushStack1(T value); //to push element into first stack.
        void pushStack2(T value); //to push element into second stack.
        T popStack1(); //to pop element from first stack.
        T popStack2(); //to pop element from second stack.
        void display();
};




// default constructor
template<typename T>
TwoStackFixed<T>::TwoStackFixed(int size, int maxtop){
    sizeT = size;
    size1 = 0;
    size2 = 0;
    cap2 = maxtop;
    cap1 = maxtop;
    list = new T[size];
}

template<typename T>
void TwoStackFixed<T>::pushStack1(T value){
    if(this->isFullStack1()){
        return;
    }
    list[size1] = value;
    size1++;
}

template<typename T>
void TwoStackFixed<T>::pushStack2(T value){
    if(this->isFullStack2()){
        return;
    }
    list[sizeT-size2] = value;
    size2++;
}

template<typename T>
T TwoStackFixed<T>::popStack1(){
    if(this->isEmptyStack1()){
        return 0;
    }
    size1--;
    return list[size1];
}

template<typename T>
T TwoStackFixed<T>::popStack2(){
    if(this->isEmptyStack2()){
        return 0;
    }
    size2--;
    return list[sizeT-size2];
}

template<typename T>
bool TwoStackFixed<T>::isFullStack1(){
    if(size1 == cap1){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackFixed<T>::isFullStack2(){
    if(size2 == cap2){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackFixed<T>::isEmptyStack1(){
    if(size1 == 0){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackFixed<T>::isEmptyStack2(){
    if(size2 == 0){
        return true;
    }
    return false;
}

template<typename T>
void TwoStackFixed<T>::display(){
    for(int i = size1-1; i >= 0; i--){
        cout << list[i] << " ";
    }
    cout << endl;
    for(int i = size2-1; i >= 0; i--){
        cout << list[sizeT-i] << " ";
    }
}

template<typename T>
class TwoStackOptimal{
    private:
        T* list;
        int size1, size2, sizeT;
        bool isFullStack1(); //helper function to check whether first stack is full.
        bool isFullStack2(); //helper function to check whether second stack is full.
        bool isEmptyStack1(); //helper function to check whether first stack is empty.
        bool isEmptyStack2(); //helper function to check whether second stack is empty.
        
    public:
        TwoStackOptimal(int size); //constructor that constructs array 
                                               //of size and constructs empty stacks.
        void pushFlexStack1(T value); //to push element into first stack.
        void pushFlexStack2(T value); //to push element into second stack.
        T popFlexStack1(); //to pop element from first stack.
        T popFlexStack2(); //to pop element from second stack.
        void display();
};




// default constructor
template<typename T>
TwoStackOptimal<T>::TwoStackOptimal(int size){
    sizeT = size;
    size1 = 0;
    size2 = 0;
    list = new T[size];
}

template<typename T>
void TwoStackOptimal<T>::pushFlexStack1(T value){
    if(this->isFullStack1()){
        return;
    }
    list[size1] = value;
    size1++;
}

template<typename T>
void TwoStackOptimal<T>::pushFlexStack2(T value){
    if(this->isFullStack2()){
        return;
    }
    list[sizeT-size2] = value;
    size2++;
}

template<typename T>
T TwoStackOptimal<T>::popFlexStack1(){
    if(this->isEmptyStack1()){
        return 0;
    }
    size1--;
    return list[size1];
}

template<typename T>
T TwoStackOptimal<T>::popFlexStack2(){
    if(this->isEmptyStack2()){
        return 0;
    }
    size2--;
    return list[sizeT-size2];
}

template<typename T>
bool TwoStackOptimal<T>::isFullStack1(){
    if((size1 + size2) == sizeT){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackOptimal<T>::isFullStack2(){
    if((size2 + size1) == sizeT){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackOptimal<T>::isEmptyStack1(){
    if(size1 == 0){
        return true;
    }
    return false;
}

template<typename T>
bool TwoStackOptimal<T>::isEmptyStack2(){
    if(size2 == 0){
        return true;
    }
    return false;
}

template<typename T>
void TwoStackOptimal<T>::display(){
    for(int i = size1 -1; i >= 0; i--){
        cout << list[i] << " ";
    }
    cout << endl;
    for(int i = size2-1; i >= 0; i--){
        cout << list[sizeT-i] << " ";
    }
}


// move n−1 discs from A to B. This leaves disc n alone on peg A
// move disc n from A to C
// move n−1 discs from B to C so they sit on disc n
// ther is no way to print the name of the different pegs correctly as the problem is given.
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C){
    if(n == 1){
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg A to C." << endl;
        A.pop();
        return;
    }
    showTowerStates(n -1, A, C, B);
    C.push(A.top());
    cout << "Moved " << A.top() << " from peg A to C." << endl;
    A.pop();
    showTowerStates(n -1, B, A, C);
    return;
}
#endif