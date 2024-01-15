#include <iostream>
#include <cmath>

using namespace std;

bool isOkay(int arr[], int col){
    for(int i = 0; i < col; i++){
        if(arr[i] == arr[col] || abs(arr[i] - arr[col]) == (col - i)){
            return false;
        }
    }
    return true;
}

void print(int arr[]){
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int board[8] = {0};  // Initialize the board with zeros
    int counter = 0;     // Initialize counter aka solution

    for (int i0 = 0; i0 < 8; i0++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    board[0] = i0;
                                    board[1] = i1;
                                    board[2] = i2;
                                    board[3] = i3;
                                    board[4] = i4;
                                    board[5] = i5;
                                    board[6] = i6;
                                    board[7] = i7;

                                    bool valid = true;
                                    for (int col = 0; col < 8; ++col) {
                                        if (!isOkay(board, col)) {
                                            valid = false;
                                            break;
                                        }
                                    }

                                    if (valid) {
                                        cout << "Solution No: "<< ++counter <<endl;
                                        print(board);

                                        if (counter == 92) {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
