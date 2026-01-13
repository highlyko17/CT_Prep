#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1e9;
int N, M;
int grid[1001][1001];
int dp[1001][1001][4];

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int d = 0; d < 3; d++){
                dp[i][j][d] = INF;
            }
        }
    }

    for(int j = 0; j < M; j++){
        for(int d = 0; d < 3; d++){
            dp[0][j][d] = grid[0][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int prev_d = 0; prev_d < 3; prev_d++){
                if(dp[i][j][prev_d] == INF) continue;

                for(int next_d = 0; next_d < 3; next_d++){
                    if(i > 0 && prev_d == next_d) continue;

                    int next_j = j + (next_d - 1);
                    int next_cost = dp[i][j][prev_d] + grid[i + 1][next_j];

                    dp[i + 1][next_j][next_d] = min(dp[i + 1][next_j][next_d], next_cost);
                }
            }
        }
    }

    int answer = INF;
    for(int j = 0; j < M; j++){
        for(int d = 0; d < 3; d++){
            answer = min(answer, dp[N - 1][j][d]);
        }
    }

    cout << answer;

    return 0;
}