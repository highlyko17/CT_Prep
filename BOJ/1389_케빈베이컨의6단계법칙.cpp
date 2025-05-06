#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int> > dist(N + 1, vector<int>(N + 1, 1e9));
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(dist[i][k] != 1e9 && dist[k][j]){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int min = 1e9;
    int idx = -1;
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++){
            sum += dist[i][j];
        }
        if(min > sum){
            idx = i;
            min = sum;
        }
    }

    cout << idx;
    return 0;
}