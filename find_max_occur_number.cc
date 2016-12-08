/*************************************************************************
    > File Name: find_max_occur_number.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Thu Dec  8 22:16:29 2016
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

/*
 * Problem: given an integer array whose length is n, the values in this array range from 1 to m, m<n
 * Question: Find the integer x with highest occurence in O(n), you are not allowed to use extra space
*/

int main(){
    // init the array, n and m
    const int n = 50;
    const int m = 20;

    int i = 0;
    int arr[n];
    //randomly generate an array
    while(i<n){
        srand(time(NULL)+i);
        arr[i] = rand()%m+1;
        cout << arr[i] << " ";
        i++;
    }

    // start to find the integer x
    int x;
    i = 0;
    while(i<n){
        arr[ arr[i]%m ] += m;
        i++;
    }

    arr[n-1] = 0; //to store the max occurrence

    i = 0;
    while(i<m){
        if(arr[i]/m > arr[n-1]){
            arr[n-1] = arr[i]/m;
            x = i;
        }
        i++;
    }

    x = x==0?20:x;

    cout << endl <<  x << " has the highest occurrence" << endl;
}
