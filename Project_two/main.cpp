#include <iostream>
using namespace std;

/*
 *
 *          An odometer is the display in a car that tells you how many miles you have traveled. Each
    number is displayed in its own “window” and, as you drive, the odometer counts up.
    The problem:
         Write a program that simulates a digital odometer. It has 6 “windows” and will output the miles
    as you travel, starting at 000000 and ending at 999999 (after which you probably want to sell
    the car anyway …).
    How?
        Create a one dimensional integer array of size 6, int win[6], where each element of the array
    represents one window of the odometer. win[5] represents the right-most window and win[0]
    the left-most.
        Create six for loops one inside the other and call the indices of the loops i0 through i5, where i0
    is the index of the outermost loop, and i5 the index of the innermost loop. You can use the
    index values to populate the array win.
    At each iteration win will represent a new configuration of the odometer. So, each time a new
    configuration is generated, print it out to the screen.


 */
void print(int arr[],int size){
    for(int i = 0; i< size;i++){
        cout << arr[i];
    }cout<< " Miles"<<endl;
}
int main() {
    int arr[6];
    for(int i0=0;i0<=9;i0++){
        for(int i1=0;i1<=9;i1++){
            for(int i2=0;i2<=9;i2++){
                for(int i3=0;i3<=9;i3++){
                    for(int i4=0;i4<=9;i4++){
                        for(int i5=0;i5<=9;i5++){
                            arr[0] = i0;
                            arr[1] = i1;
                            arr[2] = i2;
                            arr[3] = i3;
                            arr[4] = i4;
                            arr[5] = i5;
                            print(arr, size(arr));
                        }
                    }
                }
            }
        }
    }
    return 0;
}
