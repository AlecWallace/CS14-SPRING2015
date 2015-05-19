//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab6/lab6.h
///
/// @author Alec Wallace [awall006@ucr.edu]
/// @student id 861102503
/// @date 5 19 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
/// Selection sort
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <utility>

using namespace std;

template<typename L>
void selectionsort(L &l){
    typename L::iterator first;     // holds the first value in the unsorted
                                    // section of the data. Data is sorted when 
                                    // first + 1 == last.
    typename L::iterator last;      // a constant to l.end()
    typename L::iterator counter;   // iterates through the unsorted section of 
                                    // data.
    typename L::iterator smallest;  // temporary storage for the smallest data 
                                    // value  in unsorted
    first = l.begin();
    counter = first;
    last = l.end();
    // loops through the data structure until first + 1 == last ie it is sorted
    for(;first + 1 != last; first++){
        smallest = first + 1;
        // loop to find the smallest unsorted value
        for(counter = first; counter != last; counter++){
            // finding the smallest unsorted value
            if(*smallest > *counter){
                smallest = counter;
            }
        }
        // swaps the smallest unsorted value with the first value in unsorted 
        // making it part of the sorted data thus first is incremented to 
        // reflect this
        if(*smallest != *first){
            swap(*smallest,*first);
        }

    }
}