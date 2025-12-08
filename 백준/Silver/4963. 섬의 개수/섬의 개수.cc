#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

void dfs(int x, int y){
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] || !map[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny);
    }

    return ;
}

int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        map = vector<vector<int>>(h, vector<int>(w));
        visited = vector<vector<bool>>(h, vector<bool>(w, false));
        answer = 0;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(i, j);
                    answer += 1;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}