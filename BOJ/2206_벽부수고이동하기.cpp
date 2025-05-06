#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[1001][1001][2];

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {1, 0}});
    visited[0][0][0] = true;

    bool found = false;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int distance = q.front().second.first;
        int broken = q.front().second.second;
        q.pop();

        if(cx == N - 1 && cy == M - 1){
            cout << distance;
            found = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(!visited[nx][ny][broken] && !arr[nx][ny]){
                visited[nx][ny][broken] = true;
                q.push({{nx, ny}, {distance + 1, broken}});
            }
            else if(arr[nx][ny] && broken == 0 && !visited[nx][ny][1]){
                visited[nx][ny][1] = true;
                q.push({{nx, ny}, {distance + 1, 1}});
            }
        }
    }

    if(!found){
        cout << -1;
    }

    return 0;
}