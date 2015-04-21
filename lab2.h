//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab2/lab2.h
/// @brief Assignment1 for CS 14 Spring 2015
/// Contains the list for lab2
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 4 20 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
/// Contains the singly linked list<> and it's functions.
//  ================== END ASSESSMENT HEADER ===============
#ifndef ___LIST___
#define ___LIST___
#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T data):data(data),next(0){}
};

template<typename T>
class List{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        List();
        ~List();
        void display() const;
        void push_front(T value);
        void pop_front();
        void push_back(T value);
        void elementSwap(int pos);

};

// default constructor
template<typename T>
List<T>::List(){
    head = 0;
    tail = 0;
}

// destructor
template<typename T>
List<T>::~List(){
    while(head != 0){
        this->pop_front();
    }
}

//removes the first node
template<typename T>
void List<T>::pop_front(){
    if(head == 0){
        return;
    }
    
    if(head->next == 0){
        delete head;
        head = 0;
        tail = 0;
        return;
    }
    Node<T>* temp = head;
    head = temp->next;
    delete temp;
    
}

// makes a new front node with value
template<typename T>
void List<T>::push_front(T value){
    if(head == 0){
        head = new Node<T>(value);
        tail = head;
        return;
    }
    Node<T>* temp = head;
    head = new Node<T>(value);
    head->next = temp;
}

// makes a new end node with value
template<typename T>
void List<T>::push_back(T value){
    if(head == 0){
        head = new Node<T>(value);
        tail = head;
        return;
    }
    Node<T>* temp = tail;
    tail = new Node<T>(value);
    temp->next = tail;
}

// dispplays the list
template<typename T>
void List<T>::display() const{
    if(head == 0){
        return;
    }

    for(Node<T>* temp = head; temp != tail; temp = temp->next){
        cout << temp->data << " ";
    }
    cout << tail->data;
}

// swaps element pos with pos+1 
// swaps actual pointers not values
// 
template<typename T>
void List<T>::elementSwap(int pos){
    //checking lower edge cases
    if(pos < 0){
        return;
    }
    if(head == 0){
        return;
    }
    Node<T>* counter = head;
    int i;
    //iterates through the list
    for(i = 1; counter != tail; counter = counter->next){
        if(i == pos){
            //swap the nodes
            Node<T>* posNode = counter->next;
            Node<T>* posNext = posNode->next;
            posNode->next = posNext->next;
            posNext->next = posNode;
            counter->next = posNext;
            //keeps tail in the correct position
            if(posNode->next == 0){
                tail = posNode;
            }
            return;
        }
        i++;
    }
}
#endif