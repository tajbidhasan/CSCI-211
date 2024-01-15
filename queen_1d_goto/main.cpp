//
// Created by Tajbid Hasan on 1/8/24.
//
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q[8];
    int c = 0;

    q[0]=0;

    Nc:
    c++;
    if(c == 8) goto print;
    q[c]=-1;
    Nr:
    q[c]++;
    if(q[c]==8) goto backTrack;
    for(int i = 0;i < c;i++){
        if(q[c]==q[i] || abs(c-i)==abs(q[c]-q[i])) goto Nr;
    }
    goto Nc;


    backTrack:
    c--;
    if(c==-1) return 0;
    goto Nr;

    print:
    static int counter =0;
    cout<< " Solution No : "<< ++counter << endl;

    for(int i = 0; i< c; i++ ){
        for(int j = 0; j < c; j++){
            cout << (q[j]==i ? "Q ": ". ");
        }cout << endl;
    }cout<<endl;

    goto backTrack;

}
