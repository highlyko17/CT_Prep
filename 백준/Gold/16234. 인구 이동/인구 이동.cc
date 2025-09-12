#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 51

int N, L, R, days = 0, sum = 0;
int pop[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool flag = true; //연합 여부

vector<pair<int, int> > v;
queue<pair<int, int> > q;

void bfs(pair<int, int> start){
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        int cx = curr.first; int cy = curr.second;

        for(int i = 0; i < 4; i++){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]){
                if(abs(pop[nx][ny] - pop[cx][cy]) >= L && abs(pop[nx][ny] - pop[cx][cy]) <= R){
                    v.push_back({nx, ny});
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    sum += pop[nx][ny];
                }
            }
        }
    }
}

int main(){
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> pop[i][j];
        }
    }

    while(flag){
        flag = false;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    v.clear();
                    v.push_back({i, j});
                    sum = pop[i][j];
                    bfs({i, j});
                }

                //연합이면
                if(v.size() >= 2){
                    flag = true;
                    for(int k = 0; k < v.size(); k++){
                        pop[v[k].first][v[k].second] = sum / v.size();
                    }
                }
            }
        }

        if(flag) days++;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                visited[i][j] = false;
            }
        }
    }

    cout << days;
    return 0;
}