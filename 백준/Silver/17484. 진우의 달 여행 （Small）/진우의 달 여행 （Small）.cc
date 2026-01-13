#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int grid[7][7];
int dp[7][7][3];
const int INF = 1e9;

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int dir = 0; dir < 3; dir++){
            dp[0][i][dir] = grid[0][i];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int prev = 0; prev < 3; prev++){
                if(dp[i][j][prev] == INF) continue;

                for(int next = 0; next < 3; next++){
                    if(i > 0 && prev == next) continue;

                    int next_j = j + (next - 1);
                    if(next_j < 0 || next_j >= N) continue;

                    int next_dp = dp[i][j][prev] + grid[i + 1][next_j];
                    dp[i + 1][next_j][next] = min(dp[i + 1][next_j][next], next_dp);
                }
            }
        }
    }

    int answer = INF;
    for(int i = 0; i < M; i++){
        for(int dir = 0; dir < 3; dir++){
            answer = min(answer, dp[N - 1][i][dir]);
        }
    }

    cout << answer;

    return 0;
}