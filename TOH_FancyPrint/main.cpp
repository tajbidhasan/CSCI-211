#include <iostream>
#include <vector>

using namespace std;
void printTowers(const vector<int> towers[],int n) {
    cout << "\nCurrent Tower States:\n";
    for (int level = n - 1; level >= 0; --level) {
        for (int i = 0; i < 3; ++i) {
            if (level < towers[i].size()) {
                cout << towers[i][level] << "\t";  // Print disk
            } else {
                cout << "|\t";  // Print pole
            }
        }
        cout << "\n";
    }
    cout << "A\tB\tC\n";  // Label towers
    cout << "-------------------------\n";
}


int main() {
    vector<int> towers[3];

    int disks;
    cout<<"Enter the number of disk: ";
    cin>> disks;

    for(int i = disks; i>0;--i){
        towers[0].push_back(i);
    }
    int from =0;
    int to;

    if(disks%2==0){
        to=2; //even
    }else{
        to=1; // old
    }

    int candidate = 1;
    int move = 0;

    while(towers[1].size() != disks){
        cout << "Move #" << ++move << ": Transfer ring " << candidate
             << " from tower " << char(from + 'A') << " to tower " << char(to + 'A') << "\n";
        towers[to].push_back(towers[from].back());
        towers[from].pop_back();

        printTowers(towers,disks);

        if(towers[(to + 2)%3].empty()){
            from = (to+1)%3;
        }else if(towers[(to+1)%3].empty()){
            from = (to+2)%3;
        }else{
            from=(towers[(to+1)%3].back() < towers[(to+2)%3].back()) ? (to+1) % 3 : (to+2) %3;
        }
        //update the candidate
        candidate = towers[from].back();

        if(disks%2==0){
            to=(towers[(from+2)%3].empty() || candidate < towers[(from+2)%3].back()) ? (from+2) % 3 : (from+1) % 3;
        }else{
            to = (towers[(from+1)%3].empty() || candidate < towers[(from+1)%3].back()) ? (from+1)%3 : (from+2) % 3;
        }

    }

    return 0;
}
