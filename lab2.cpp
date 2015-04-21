//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab2/lab2.cpp
/// @brief Assignment1 for CS 14 Spring 2015
/// Contains functions for lab2
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
/// Contains the functions primeCount and printLots.
//  ================== END ASSESSMENT HEADER ===============
#include "lab2.h"
#include <forward_list>
#include <stack>

using namespace std;



// helper function checks if number is prime
// returns true if i is prime
bool isPrime(int i){
    //test for the bottom edge cases
    if(i <= 1){
        return false;
    }
    if(i == 3 || i == 2){
        return true;
    }
    
    //for faster runtime check if the number is divisible by 2 or 3.
    //Removes a majority of numbers so that the for loop is only used when
    //necessary.
    if(i % 2 == 0 || i % 3 == 0){
        return false;
    }
    //for loop checks all remaining numbers
    for(int j = 5; j * j <= i; j += 6){
        if(i % j == 0 || i % (j + 2) == 0){
            return false;
        }
    }
    return true;
}

// recursive function counts the number of primes in an list<int>
int primeCount(forward_list<int> lst){
    int val = lst.front();
    //peels the first value so it can make the function call with a shorter list
    if(isPrime(val)){
        lst.pop_front();
        if(lst.empty()){
            return 1;
        }
        return primeCount(lst) + 1;
    }
    else{
        lst.pop_front();
        if(lst.empty()){
            return 0;
        }
        return primeCount(lst);
    }
}

// prints elements in positions of L specified by P
template<typename T>
void printLots (forward_list<T> L,forward_list<int> P){
    int i = 0;
    for(forward_list<int>::iterator listItL = L.begin(); listItL != L.end(); listItL++){
        for(forward_list<int>::iterator listItP = P.begin(); listItP != P.end(); listItP++){
            if(*listItP == i){
                cout << *listItL << " ";
            }
        }
        i++;
    }
}
template<typename T>
void listCopy(forward_list<T> L, forward_list<T>& P){
    stack<T> hold;
    while(!P.empty()){
        hold.push(P.front());
        P.pop_front();
    }
    while(!L.empty()){
        P.push_front(L.front());
        L.pop_front();
    }
    while(!hold.empty()){
        P.push_front(hold.top());
        hold.pop();
    }
}

// int main(){
//     cout << "______Testing Function isPrime_______" << endl;
//     forward_list<int> PrimeTest;
//     PrimeTest.push_front(1);
//     PrimeTest.push_front(0);
//     PrimeTest.push_front(-5);
//     PrimeTest.push_front(8);
//     PrimeTest.push_front(2);
//     PrimeTest.push_front(3);
//     PrimeTest.push_front(6);
//     PrimeTest.push_front(61);
//     PrimeTest.push_front(93);
//     PrimeTest.push_front(19);
//     PrimeTest.push_front(17);
//     PrimeTest.push_front(11);
//     PrimeTest.push_front(10);
//     PrimeTest.push_front(5);
//     PrimeTest.push_front(100);
//     cout << "Number of primes in PrimeTest: " << primeCount(PrimeTest) << endl;
//     cout << "Number of primes in PrimeTest: " << primeCount(PrimeTest) << endl;
//     cout << "______________________________________" << endl;
    
//     cout << "______Testing Function printLots______" << endl;
//     forward_list<int> printTest;
//     printTest.push_front(0);
//     printTest.push_front(2);
//     printTest.push_front(6);
//     printTest.push_front(7);
//     printLots(PrimeTest, printTest);
//     cout << endl;
//     cout << "______________________________________" << endl;
    
//     cout << "_____Testing Function elementSwap_____" << endl;
//     List<int> swapTest;
//     swapTest.push_front(6);
//     swapTest.push_front(5);
//     swapTest.push_front(4);
//     swapTest.push_front(3);
//     swapTest.push_front(2);
//     swapTest.push_front(1);
//     swapTest.push_front(0);
//     swapTest.elementSwap(5);
//     swapTest.display();
//     cout << endl;
//     cout << "______________________________________" << endl;
    
//     cout << "______Testing Function listCopy_______" << endl;
//     forward_list<int>::iterator Itr = printTest.begin();
//     cout << "List to be added to: ";
//     for(;Itr != printTest.end();Itr++){
//         cout << *Itr << " ";
//     }
//     cout << endl;
//     cout << "List to be added in reverse: ";
//     Itr = PrimeTest.begin();
//     for(;Itr != printTest.end();Itr++){
//         cout << *Itr << " ";
//     }
//     cout << endl;
    
//     listCopy(PrimeTest,printTest);
//     Itr = printTest.begin();
//     for(;Itr != printTest.end();Itr++){
//         cout << *Itr << " ";
//     }
//     cout << endl;
//     cout << "______________________________________" << endl;

//     return 0;
// }