#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int N, M;
    cin >> M >> N;

    vector<vector<int>> v(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        string line;
        cin >> line;
        for(int j = 0; j < M; j++){
            v[i][j] = line[j] - '0';
        }
    }

    vector<vector<int>> dij(N, vector<int>(M, 100000));
    priority_queue<pair<int, pair<int, int>>> pq;
    
    pq.push({0, {0, 0}});
    dij[0][0] = 0;

    while(!pq.empty()){
        int AOJ = -pq.top().first;
        int ci = pq.top().second.first;
        int cj = pq.top().second.second;
        pq.pop();

        if(AOJ > dij[ci][cj]) continue;

        for(int i = 0; i < 4; i++){
            int ni = ci + dx[i];
            int nj = cj + dy[i];

            if(ni < 0 || nj < 0 || ni >= N || nj >= M) continue;

            if(dij[ni][nj] > AOJ + v[ni][nj]){
                dij[ni][nj] = AOJ + v[ni][nj];
                pq.push({-dij[ni][nj], {ni, nj}});
            }
        }
    }

    cout << dij[N - 1][M - 1];

    return 0;
}