//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab7/main.cc
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 26 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <set>
#include <chrono>
#include <ctime>
#include <ratio>
#include <algorithm>
// #include "lab7.h"

using namespace std;

void test_sets(int n, const vector<string>& vect){
    double un_in, un_find, or_in, or_find;
    unordered_set<string> un_set;
    set<string> or_set;
    chrono::system_clock::time_point begin;
    chrono::system_clock::time_point end;
    // testing insert
    // start time test for unordered
    begin = chrono::system_clock::now();
    for(int i = 0 ; i < n; i++){
        un_set.insert(vect.at(i));
    }
    end = chrono::system_clock::now();
    un_in = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    // end time test for ordered
    
    // start time test for unordered
    begin = chrono::system_clock::now();
    for(int i = 0 ; i < n; i++){
        or_set.insert(vect.at(i));
    }
    end = chrono::system_clock::now();
    or_in = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    // end time test for ordered
    
    // testig find
    // start time test for unordered
    begin = chrono::system_clock::now();
    for(int i = 0 ; i < n; i++){
        un_set.find(vect.at(i));
    }
    end = chrono::system_clock::now();
    un_find = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    // end time test for ordered
    
    // start time test for unordered
    begin = chrono::system_clock::now();
    for(int i = 0 ; i < n; i++){
        or_set.find(vect.at(i));
    }
    end = chrono::system_clock::now();
    or_find = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    // end time test for ordered
    or_in /= n;
    un_in /= n;
    or_find /= n;
    un_find /= n;
    // prrinting the output
    ofstream output("data.txt", ios::out | ios::app);
    output << n << " " << or_in << " " << un_in << " " << or_find << " " << un_find << "\n";
    output.close();
}

int main(int argc, char* arga[]){
    ofstream output("data.txt");
    output.close();
    vector<string> words;
    if(argc != 2){
        cout << "Enter the file to be used" << endl;
        exit(-1);
    }
    string temp;
    ifstream input(arga[1]);
    if(!input){
        cout << "ERROR Opening file. " << arga[1] << endl;
        exit(0);
    }
    while(input.peek() != -1){
        input >> temp;
        words.push_back(temp);
    }
    
    // for(unsigned i = 0; i < words.size(); i++){
    //     cout << words.at(i) << " ";
    // }
    // tests the function
    for(int i = 0; i < 10; i++){
        for(int n = 5000; n <= 50000; n += 5000){
                test_sets(n,words);
        }
        random_shuffle(words.begin(), words.end());
    }

    cout << endl;
    return 0;
}