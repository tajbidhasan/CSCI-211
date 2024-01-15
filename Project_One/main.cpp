#include <iostream>
#include <cmath>
using namespace std;
/*
 * Find the Value
Write a program to find and print the first perfect square (i*i) whose last two digits
are both odd.
Very important
Make sure to check that the answer you get is indeed a perfect square.
 */

bool isPerfect(int n){
    int root = round(sqrt(n));

    return n == root * root;
}

bool isOkay(int n){
    int last_digit = n % 10;


    int second_last_digit = (n/10) % 10;

    return (last_digit%2) != 0 && (second_last_digit%2) != 0;
}
int main() {


    int num = 0;
    int base_cass = 9999999;

    while(true){
        if(num > base_cass){
            cout<< "No solution.";
            return 0;
        }
        if(isPerfect(num) && isOkay(num)){
            cout<< "Solution: "<< num << endl;
        }
       num++;
    }

}
