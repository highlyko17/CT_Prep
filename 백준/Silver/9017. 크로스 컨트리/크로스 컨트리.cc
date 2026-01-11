#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> teams(N);
        map<int, int> team_count;
        
        for(int i = 0; i < N; i++){
            cin >> teams[i];
            team_count[teams[i]]++;
        }

        vector<int> scores(N);
        int score = 1;
        for(int i = 0; i < N; i++){
            if(team_count[teams[i]] == 6){
                scores[i] = score++;
            } else {
                scores[i] = 0;
            }
        }

        map<int, vector<int>> team_scores;
        for(int i = 0; i < N; i++){
            if(scores[i] > 0){
                team_scores[teams[i]].push_back(scores[i]);
            }
        }

        int winner_idx = -1;
        int winner_score = 100000;
        int winner_5th = 100000;

        for(auto& p : team_scores){
            int team = p.first;
            vector<int>& s = p.second;
            
            if(s.size() >= 6){
                int total = s[0] + s[1] + s[2] + s[3];
                int fifth = s[4];
                
                if(total < winner_score || 
                   (total == winner_score && fifth < winner_5th)){
                    winner_idx = team;
                    winner_score = total;
                    winner_5th = fifth;
                }
            }
        }

        cout << winner_idx << '\n';
    }

    return 0;
}