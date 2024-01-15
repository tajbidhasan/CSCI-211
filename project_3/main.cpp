
//race result
#include <iostream>
#include <map>

using namespace std;

int main() {
    string raceResult;

    while(true){

        cout << " Enter the race result or 'done' to exit: " ;
        getline(cin,raceResult);

        if(raceResult == "done"){
            break;
        }

        map<char,int>scoreSum;
        map<char,int>runnerCount;

        int position = 1;

        for(int i =0; i< raceResult.length(); i++){
            char team = toupper(raceResult[i]);
            scoreSum[team] += position;
            runnerCount[team]++;
            position++;
        }

        int teamSize = runnerCount.begin()->second;
        bool equalTeam = true;

        for(auto runner : runnerCount){
            if(runner.second != teamSize){
                cout<<"Invalid runner count."<<endl;
                equalTeam= false;
                break;
            }
        }

        if(!equalTeam){
            continue;
        }
        char winner;
        float lowestScore = 10000000.0;

        for(auto score : scoreSum){
            float averageScore = static_cast<float> (score.second)/ teamSize;
            cout << "Team: " << score.first<< " : " <<  averageScore << endl;

            if(averageScore < lowestScore){
                lowestScore = averageScore;
                winner = score.first;
            }
        }

        cout << "Winning team is "<<winner<<" with score of "<< lowestScore<< endl;

    }

    return 0;
}
