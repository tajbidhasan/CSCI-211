#include <iostream>
#include <cmath>

using namespace std;

static int helper[8][5]{
        {-1},
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {6,3,4,5,-1}
};

bool isOkay(int cross[], int index){
    for(int i =0;i< index; i++){
        if(cross[index] == cross[i]) return false;
    }
    for(int i=0; helper[index][i] != -1; i++){
        if(abs(cross[index] - cross[helper[index][i]]) == 1 ){
            return false;
        }
    }
    return true;
}
void print(int cross[]){
    static int count = 0;
    cout << " Solution number: " << ++ count << endl;
    cout <<" "<< cross[0] <<" "<< cross[1] << endl;
    cout << cross[0] <<" "<< cross[3] <<" "<< cross[4] <<" " << cross[5] << endl;
    cout << " "<<cross[6] <<" "<< cross[7] << endl;
}

void next(int cross[], int index){
  if(index > 7){
      print(cross);
      return;
  }

  for(int i = 1; i <=8; i++){
      cross[index] = i;
      if(isOkay(cross,index)){
          next(cross,index+1);
      }
  }
}

int main() {
    int cross[8];
    next(cross,0);
    return 0;
}
