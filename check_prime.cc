/*************************************************************************
    > File Name: check_prime.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Fri 09 Dec 2016 10:08:49 AM
 ************************************************************************/

#include<iostream>
#include<math.h>

using namespace std;

 /*
  * check if a number is prime as fast as possible
  * all the prime numbers that are greater than 4, 
  * satisfy that when dividing the prime number by 6, the remainder is 1 or 5, such as 5,7,11,13,17,19
  * the step among all the following prime numbers are 2 and 4 alternately
 */

// the running time is in O(sqrt(n)/6) to O(sqrt(n)/4)
bool isPrime(int n){
    if( n <= 3 ) return true;
    if( n%2 == 0 ) return false;
    if( n%3 == 0 ) return false;

    int i;
    int s = (int)(sqrt((double)n)+0.01);
    int step=4;
    for(i=5; i<=s; i+=step){
        if( n%i == 0 )
            break;
        step^=6;
    }
    return i>s;
}

int main(){
    for(int i=2;i<=100;i++){
        if(isPrime(i))
            cout<< i << " ";
    }
    cout << endl;
}
