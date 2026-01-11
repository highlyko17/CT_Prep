#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int p, m;
    cin >> p >> m;

    vector<pair<string, int>> players;
    for(int i = 0; i < p; i++){
        int level; 
        string id;
        cin >> level >> id;

        players.push_back({id, level});
    }

    vector<vector<pair<string, int>>> rooms(p);
    int room_idx = 0;
    rooms[0].push_back({players[0].first, players[0].second});
    
    for(int i = 1; i < p; i++){
        bool find = false;
        
        for(int j = 0; j <= room_idx; j++){
            int level_floor = rooms[j][0].second - 10;
            int level_ceiling = rooms[j][0].second + 10;
            int curr_level = players[i].second;
            string curr_id = players[i].first;

            if(rooms[j].size() < m && level_floor <= curr_level && curr_level <= level_ceiling){
                rooms[j].push_back({curr_id, curr_level});
                find = true;
                break;
            }
        }

        if(!find){
            room_idx += 1;
            rooms[room_idx].push_back({players[i].first, players[i].second});
        }
    }

    for(int i = 0; i <= room_idx; i++){
        sort(rooms[i].begin(), rooms[i].end());
        if(rooms[i].size() == m){
            cout << "Started!" << '\n';
        }
        else cout << "Waiting!" << '\n';

       for(int j = 0; j < rooms[i].size(); j++){
        cout << rooms[i][j].second << ' ' << rooms[i][j].first << '\n';
       }
    }

    return 0;
}