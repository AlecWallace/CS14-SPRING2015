//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab4/main.cc
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
#include <fstream>
#include "lab4.h"
#include <sstream>

using namespace std;

int main(int argc, char* arga[]){
    if(argc != 2){
        cout << "enter the number." << endl;
        exit(-1);
    }
    stringstream ss;
    ss << arga[1];
    int num;
    ss >> num;
    preOrder(num);
    postOrder(num);
    sort(num);
}