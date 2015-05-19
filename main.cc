//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab6/main.cc
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 19 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
///
//  ================== END ASSESSMENT HEADER ===============
#include "lab6.h"
#include <vector>

using namespace std;

struct nums{
    int one, two;
    bool operator<(const nums& n){
        return this->one < n.one;
    }
    bool operator>(const nums& n){
        return this->one > n.one;
    }
    bool operator==(const nums& n){
        return this->one == n.one;
    }
    bool operator!=(const nums& n){
        return this->one != n.one;
    }
};

int main(){
    vector<int> vect = {10,7,32,108,12,14,6,1,1,8,92,308};
    for(unsigned i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
    selectionsort(vect);
    for(unsigned i = 0; i < vect.size(); i++){
        cout << vect[i] << " ";
    }
    cout << endl;
    
    vector<pair<int,int>> pVect = {make_pair(10,1), make_pair(12,2), make_pair(6,8), make_pair(100,0), make_pair(90,9)};
    for(unsigned i = 0; i < pVect.size(); i++){
        cout << "(" << pVect[i].first << "," << pVect[i].second << ") ";
    }
    cout << endl;
    selectionsort(pVect);
    for(unsigned i = 0; i < pVect.size(); i++){
        cout << "(" << pVect[i].first << "," << pVect[i].second << ") ";
    }
    cout << endl;
    
    cout << "Proof that Selection sort is not stable" << endl;
    vector<nums> nVect;
    nums temp;
    temp.one = 10;
    temp.two = 0;
    nVect.push_back(temp);
    
    temp.one = 10;
    temp.two = 1;
    nVect.push_back(temp);
    
    temp.one = 1;
    temp.two = 0;
    nVect.push_back(temp);
    
    temp.one = 34;
    temp.two = 0;
    nVect.push_back(temp);
    
    temp.one = 900;
    temp.two = 0;
    nVect.push_back(temp);
    
    for(unsigned i = 0; i < nVect.size(); i++){
        cout << "(" << nVect[i].one << "," << nVect[i].two << ") ";
    }
    cout << endl;
    selectionsort(nVect);
    for(unsigned i = 0; i < nVect.size(); i++){
        cout << "(" << nVect[i].one << "," << nVect[i].two << ") ";
    }
    cout << endl;
    
    return 0;
}