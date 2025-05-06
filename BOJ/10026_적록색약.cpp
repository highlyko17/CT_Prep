#include <iostream>

using namespace std;

int N, area = 0;
char grid[101][101];
bool visited_first[101][101] = {false,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y){
    if(visited_first[x][y]) return;
    visited_first[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited_first[nx][ny] && grid[nx][ny] == grid[x][y]){
            dfs(nx, ny);
        }
    }

}

int main(){
    cin >> N;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            grid[i][j] = input[j];
        }
    }

    //평범한 사람
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited_first[i][j]){
                dfs(i, j);
                area++;
            }
        }
    }

    cout << area << endl;
    area = 0;
    //적록색약
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 'R'){
                grid[i][j] = 'G';
            }
            visited_first[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited_first[i][j]){
                dfs(i, j);
                area++;
            }
        }
    }

    cout << area;

    return 0;
}