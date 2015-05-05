//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab4/lab4.h
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 5 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <queue>
#include <utility>
#include <stack>

// using namespace std;

//recursive node print function for preorder
void prePrint(int m, int n, int k){
    if(m + n > k){
        return;
    }
    std::cout << m << " " << n << std::endl;
    prePrint(2*m - n, m, k);
    prePrint(2*m + n, m, k);
    prePrint(m + 2*n, n, k);
}

//origional function. Given number sum cannot be over 
//makes call to recursive function to print nodes in preorder
void preOrder(int k){
    std::cout << "pre-order" << std::endl;
    prePrint(2,1,k);
    prePrint(3,1,k);
}


//recursive node print function for postorder
void postPrint(int m, int n, int k){
    if(m + n > k){
        return;
    }
    postPrint(2*m - n, m, k);
    postPrint(2*m + n, m, k);
    postPrint(m + 2*n, n, k);
    std::cout << m << " " << n << std::endl;
}

//origional function. Given number sum cannot be over 
//makes call to recursive function to print nodes in postorder
void postOrder(int k){
    std::cout << "post-order" << std::endl;
    postPrint(2,1,k);
    postPrint(3,1,k);
}

//recursive function to enque the numbers in p
void sortEnque(int m, int n, int k, std::priority_queue<std::pair<int,int>> &p){
    if(m + n > k){
        return;
    }
    std::pair<int,int> temp(m+n,m);
    p.push(temp);
    sortEnque(2*m - n, m, k, p);
    sortEnque(2*m + n, m, k, p);
    sortEnque(m + 2*n, n, k, p);
}


//function to print out tree in order of sums use priority queue
//pair holds the sum and first number
void sort(int k){
    std::cout << "sorted" << std::endl;
    std::priority_queue<std::pair<int,int>> pairs;
    std::stack<std::pair<int,int>> temp;
    sortEnque(2,1,k,pairs);
    sortEnque(3,1,k,pairs);
    
    while(!pairs.empty()){
        temp.push(pairs.top());
        pairs.pop();
    }
    
    while(!temp.empty()){
        std::cout << temp.top().second << " " 
            << temp.top().first-temp.top().second << std::endl;
        temp.pop();
    }
}

