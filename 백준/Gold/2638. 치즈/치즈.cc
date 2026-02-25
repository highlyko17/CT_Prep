#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int answer = 0;

    while(true){
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            auto [cx, cy] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(visited[nx][ny]) continue;

                if(board[nx][ny] == 0){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        vector<pair<int,int>> removeList;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 1){
                    int cnt = 0;

                    for(int d = 0; d < 4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                        if(visited[nx][ny]) cnt++;
                    }

                    if(cnt >= 2)
                        removeList.push_back({i,j});
                }
            }
        }

        if(removeList.empty()) break;

        for(auto [x,y] : removeList)
            board[x][y] = 0;

        answer++;
    }

    cout << answer;

    return 0;
}