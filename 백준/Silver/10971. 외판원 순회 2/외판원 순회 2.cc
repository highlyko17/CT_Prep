#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
vector<vector<int>> cities;

int srch(int dist, int curr, vector<bool> visited, int cnt){
    if(cnt == N){
        if(cities[curr][0] != 0){
            return dist + cities[curr][0];
        }

        return INF;
    }

    int minCost = INF;

    for(int i = 0; i < N; i++){
        int temp = cities[curr][i];

        if(!visited[i] && temp != 0){
            visited[i] = true;
            minCost = min(minCost, srch(dist + temp, i, visited, cnt + 1));
            visited[i] = false;
        }
    }

    return minCost;
}

int main(){
    cin >> N;

    cities = vector<vector<int>>(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cities[i][j];
        }
    }

    vector<bool> visited(N, false);
    visited[0] = true;
    
    int answer = srch(0, 0, visited, 1);

    cout << answer;

    return 0;
}