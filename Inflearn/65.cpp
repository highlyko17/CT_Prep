#include <iostream>

using namespace std;

int map[10][10];
int visited[10][10];
int answer = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(x >= 7 && y >= 7){
        answer++;
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 1 && nx <= 7 && ny >= 1 && ny <= 7 && !visited[nx][ny] && !map[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;
        }
    }
}

int main(){
    freopen("65input.txt", "rt", stdin);

    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 7; j++){
            scanf("%d", &map[i][j]);
        }
    }

    visited[1][1] = 1;
    dfs(1, 1);
    cout << answer;

    return 0;
}