#include <iostream>

using namespace std;

int N, ans = 0;
int house[17][17] = {0};
int dx[3] = {0, 1, 1}; // 가로, 세로, 대각선
int dy[3] = {1, 0, 1};

 
// 방향 => 0 : 가로, 1 : 세로, 2 : 대각선 
void dfs(int x, int y, int dir){
    if(x == N - 1 && y == N - 1){
        ans++;
        return;
    }

    for(int i = 0; i < 3; i++){
        if(dir == 0 && i == 1) continue;
        else if(dir == 1 && i == 0) continue;
        else{
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(i < 2){
                if(house[nx][ny] == 0){
                    dfs(nx, ny, i);
                }
            }
            else{
                if(house[nx][ny] == 0 && house[nx - 1][ny] == 0 && house[nx][ny - 1] == 0){
                    dfs(nx, ny, i);
                }
            }
        }
    }

}


int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> house[i][j];
        }
    }

    dfs(0, 1, 0);

    cout << ans;

    return 0;
}