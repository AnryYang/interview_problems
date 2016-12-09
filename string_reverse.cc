/*************************************************************************
    > File Name: string_reverse.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Fri 09 Dec 2016 10:43:27 AM
 ************************************************************************/

#include<iostream>
using namespace std;

// reverse a string
void str_reverse(char* start, char* end){
    for(--end; start<end; ++start, --end){
        char c;
        c = *start;
        *start = *end;
        *end = c;
    }
}

// shift left a string by n chars
char* str_shift_left(char* start, char* end, int n){
    str_reverse(start, &start[n]); // reverse the first n chars
    str_reverse(&start[n], end);  // reverse the remaining chars
    str_reverse(start, end); //reverse the whole string
    return start;
}
