#include <iostream>
#include <queue>

using namespace std;

int n, m, startx, starty;
int arr[1001][1001] = {0}, answer[1001][1001] = {0};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x, y});
    answer[x][y] = 1;

    while(!q.empty()){
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = currx + dx[i];
            int ny = curry + dy[i];

            if(answer[nx][ny] == 0 && arr[nx][ny] != 0 && nx >= 0 && nx < n && ny >= 0 && ny < m){
                answer[nx][ny] = answer[currx][curry] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                startx = i;
                starty = j;
            }
        }
    }

    bfs(startx, starty);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0) cout << "0 ";
            else cout << answer[i][j] - 1 << ' ';
        }
        cout << endl;
    }
}