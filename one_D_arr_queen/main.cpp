#include <iostream>
#include <cmath>

using namespace std;

const int N =8;
int board[N];

bool isSafe(int row, int col){
    for(int i=0; i<row;i++){
        if(board[i]== col || abs(i - row )== abs(board[i]-col)) return false;
    }
    return true;
}

void printBoard(){
    for(int i =0; i<N;i++){
        for(int j =0; j < N;j++){
           cout << (board[i]==j ? "Q ":"* ");
        }
        cout<<endl; // line break after every row
    }
    cout<<endl; // line break after every column
}

void solveNQueen(int row, int &solutionCount){
    if(row==N){
        cout << "Solution #: "<< ++solutionCount << endl;

        for(int i=0;i<N;i++){
            cout << board[i]+1 << " ";
        } cout<<endl;
        cout << "---------------" << endl;

        printBoard();
        return;
    }

    for(int col=0; col < N; col++){
        if(isSafe(row,col)){
            board[row]=col;
            solveNQueen(row + 1,solutionCount);
        }
    }
}

int main(){
    int solutionCount =0;
    solveNQueen(0,solutionCount);

    cout<< "Total Solution Count: " << solutionCount << endl;

    return 0;

}