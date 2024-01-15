#include <iostream>
using namespace std;

int main() {
    int b[8][8]={0};
    int row=0, col=0;
    b[0][0]=1;

nc:
    col++;
    if(col == 8) goto print;

    row = -1;
nr:
    row++;
    if(row == 8) {
        goto backtrack;
    }
    //row text
    for(int i = 0; i<col; i++){
        if(b[row][i] == 1){
            goto nr;
        }
    }
    //upper left diagonal
    for(int i =1; (row - i) >=0 && (col - i) >= 0;i++){
        if(b[row - i][col -i] == 1){
            goto nr;
        }
    }
    // lower left diagonal
    for(int i = 1; (row+1) <= 7 && (col - i) >=0; i++){
        if(b[row+i][col-i] == 1){
            goto nr;
        }
    }
    b[row][col]=1;
    goto nc;
backtrack:
    col--;

    if(col == -1){
        return 0;
    }

    row=0;
    while(b[row][col] != 1){
        row++;
    }
    b[row][col] = 0;
    goto nr;
print:
    static int numSolution = 0;
    cout << " Solution number : "<< ++numSolution << endl;
    for(int i =0; i<8;i++){
        for(int j =0; j < 8; j++){
            cout << (b[i][j] ? "Q ": ". ");
        }
        cout<<endl;
    }
    cout<<endl;
    goto backtrack;
}
