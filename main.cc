//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab5/main.cc
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 12 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
//  ================== END ASSESSMENT HEADER ===============
#include "lab5.h"

using namespace std;

int main(){
    BST<int> T;
    T.insert(7);
    T.insert(3);
    T.insert(1);
    T.insert(0);
    T.insert(2);
    T.insert(5);
    T.insert(4);
    T.insert(6);
    T.insert(11);
    T.insert(9);
    T.insert(8);
    T.insert(10);
    T.insert(13);
    T.insert(12);
    T.insert(14);
    
    BST<int> W;
    W.insert(50);
    W.insert(20);
    W.insert(60);
    W.insert(10);
    W.insert(40);
    W.insert(35);
    W.insert(45);
    W.insert(70);
    
    cout << "Testcase1" << endl;
    cout << "Part1" << endl;
    // W.minCover();
    W.displayMinCover();
    cout << endl << "Part2" << endl; 
    W.FINDSUMPATHTEST(80);
    cout << endl << "Part3" << endl;
    W.VERSUMTEST();
    cout << endl;
    

    cout << endl << "Testcase2" << endl;
    cout << "Part1" << endl;
    // T.minCover();
    T.displayMinCover();
    cout << endl << "Part2" << endl; 
    T.FINDSUMPATHTEST(80);
    cout << endl << "Part3" << endl;
    T.VERSUMTEST();
    cout << endl;
    
    return 0;
}
