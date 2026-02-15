#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, INF = 1e9;
vector<vector<int>> W;

int srch(int depth, int curr_city, int dist, vector<bool> visited){
    if(depth == N){
        if(W[curr_city][0] != 0){
            return dist + W[curr_city][0];
        }

        return INF;
    }

    int minCost = INF;

    for(int i = 0; i < N; i++){
        int next_dist = W[curr_city][i];

        if(next_dist != 0 && !visited[i]){
            visited[i] = true;
            minCost = min(minCost, srch(depth + 1, i, dist + next_dist, visited));
            visited[i] = false;
        }
    }

    return minCost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    W.resize(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> W[i][j];
        }
    }

    vector<bool> visited(N, false);
    visited[0] = true;
    
    int answer = srch(1, 0, 0, visited);
    cout << answer;

    return 0;
}