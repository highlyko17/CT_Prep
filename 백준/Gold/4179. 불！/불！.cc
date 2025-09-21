#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;

int main(){
    cin >> R >> C;

    vector<vector<char> > v(R, vector<char>(C));
    pair<int, int> j_coord, f_coord;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    queue<pair<pair<int, int>, int> > jq, fq;
    vector<vector<bool> > jvisited(R, vector<bool>(C, false)), fvisited(R, vector<bool>(C, false));
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> v[i][j];

            if(v[i][j] == 'J'){
                j_coord = {i, j};
                jvisited[i][j] = true;
            }
            else if(v[i][j] == 'F'){
                fq.push({{i, j}, 0});
                fvisited[i][j] = true;
            }
        }
    }

    jq.push({{j_coord}, 0}); fq.push({{f_coord}, 0});

    while(!jq.empty()){
        pair<int, int> jcurr = jq.front().first;
        int jmin = jq.front().second;
        jq.pop();

        if(jcurr.first == 0 || jcurr.second == 0 || jcurr.first == R-1 || jcurr.second == C-1){
            cout << jmin + 1;
            return 0;
        }

        while(!fq.empty() && fq.front().second == jmin){
            pair<int, int> fcurr = fq.front().first;
            int fmin = fq.front().second;
            fq.pop();

            for(int i = 0; i < 4; i++){
                int nx = fcurr.first + dx[i];
                int ny = fcurr.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C || fvisited[nx][ny]) continue;

                if(v[nx][ny] != '#'){
                    v[nx][ny] = 'F';
                    fvisited[nx][ny] = true;
                    fq.push({{nx, ny}, fmin + 1});
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int nx = jcurr.first + dx[i];
            int ny = jcurr.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C || jvisited[nx][ny]) continue;

            if(v[nx][ny] == '.'){
                v[nx][ny] = 'J';
                jvisited[nx][ny] = true;
                jq.push({{nx, ny}, jmin + 1});
            }
        }

    }

    cout << "IMPOSSIBLE";

    return 0;
}