#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, a[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }

    int id = 0;
    vector<vector<int> > islands(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 1 && islands[i][j] == 0){
                ++id;
                islands[i][j] = id;
                
                queue<pair<int, int> > q;
                q.push({i, j});

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int d = 0; d < 4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                        if(a[nx][ny] == 1 && islands[nx][ny] == 0){
                            islands[nx][ny] = id;
                            q.push({nx, ny});
                        }
                    }
                }

            }
        }
    }

    vector<vector<int> > owner(N, vector<int>(N, 0));
    vector<vector<int> > dist(N, vector<int>(N, -1));
    queue<pair<int, int> > qq;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 1){
                owner[i][j] = islands[i][j];
                dist[i][j] = 0;
                qq.push({i, j});
            }
        }
    }

    int ans = 100000;
    while(!qq.empty()){
        int x = qq.front().first;
        int y = qq.front().second;
        qq.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(owner[nx][ny] == 0){
                owner[nx][ny] = owner[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                qq.push({nx, ny});
            }
            else if(owner[nx][ny] != owner[x][y]){
                int nd = dist[nx][ny] + dist[x][y];
                if(ans > nd) ans = nd;
            }
        }
    }
    
    cout << ans;

    return 0;
}