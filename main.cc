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
#include "lab3.h"

int main(){
    cout << "_________Testing fixed__________" << endl;
    TwoStackFixed<int> there(100,50);
    for(int i = 0; i < 50; i++){
        there.pushStack1(i);
        there.pushStack2(i);
    }
    there.display();
    for(int i = 0; i < 50; i++){
        there.popStack1();
        there.popStack2();
    }
    cout << endl;
    there.display();
    cout << endl;
    
    cout << "_________Testing Optimal__________" << endl;
    TwoStackOptimal<int> testOpt(100);
    for(int i = 0; i < 100; i++){
        testOpt.pushFlexStack1(i);
    }
    testOpt.display();
    for(int i = 0; i < 99; i++){
        testOpt.popFlexStack1();
    }
    cout << endl;
    testOpt.display();
    cout << endl;
    
    for(int i = 0; i < 100; i++){
        testOpt.pushFlexStack2(i);
    }
    testOpt.display();
    for(int i = 0; i < 50; i++){
        testOpt.popFlexStack2();
    }
    cout << endl;
    testOpt.display();
    cout << endl;
    
    for(int i = 0; i < 50; i++){
        testOpt.pushFlexStack1(i);
        testOpt.pushFlexStack2(i);
    }
    testOpt.display();
    for(int i = 0; i < 100; i++){
        testOpt.popFlexStack1();
        testOpt.popFlexStack2();
    }
    cout << endl;
    testOpt.display();
    cout << endl;
    
    stack<int> A;
    stack<int> B;
    stack<int> C;
    for(int i = 5; i >= 0; i--){
        A.push(i);
    }
    showTowerStates(5,A,B,C);
    while(!C.empty()){
        cout << C.top() << " ";
        C.pop();
    }
    
    return 0;
}
