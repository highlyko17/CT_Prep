#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

string target = "123456780";

bool solvable(string puzzle){
    int inv = 0;

    for(int i = 0; i < 9; i++){
        if(puzzle[i] == '0') continue;
        for(int j = i + 1; j < 9; j++){
            if(puzzle[j] == '0') continue;
            if(puzzle[i] > puzzle[j]) inv++;
        }
    }

    return (inv % 2 == 0);
}

int bfs(string puzzle){
    if(puzzle == target) return 0;

    unordered_set<string> visited;
    queue<pair<string, int> > q;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    visited.insert(puzzle);
    q.push({puzzle, 0});

    while(!q.empty()){
        string curr = q.front().first;
        int depth = q.front().second;
        q.pop();

        int zeroIdx = curr.find('0');
        int zerox = zeroIdx / 3;
        int zeroy = zeroIdx % 3;

        for(int i = 0; i < 4; i++){
            int nx = zerox + dx[i];
            int ny = zeroy + dy[i];

            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;

            int nIdx = nx * 3 + ny;
            string next = curr;
            swap(next[nIdx], next[zeroIdx]);

            if(visited.find(next) == visited.end()){
                if(next == target) return depth + 1;
                visited.insert(next);
                q.push({next, depth + 1});
            }
        }
    }

    return -1;
}

int main(){
    string puzzle = "";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp;
            cin >> temp;

            puzzle += (temp + '0');
        }
    }

    if(!solvable(puzzle)){
        cout << -1;
        return 0;
    }

    cout << bfs(puzzle);

    return 0;
}