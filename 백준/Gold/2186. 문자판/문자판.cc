#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int N, M, K, answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char board[101][101];
int dp[101][101][81] = {-1, };
string word;

int dfs(int depth, int x, int y){
    if(depth == word.length() - 1) return 1;

    int ret = dp[x][y][depth];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 4; i++){
        for(int step = 1; step <= K; step++){
            int nx = x + dx[i] * step;
            int ny = y + dy[i] * step;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] == word[depth + 1]){
                ret += dfs(depth + 1, nx, ny);
            }
        }
    }

    dp[x][y][depth] = ret;
    return ret;
}

int main(){
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    cin >> word;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == word[0])
                answer += dfs(0, i, j);
        }
    }
    
    cout << answer;

    return 0;
}