#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 9999999

int main(){
    int cnt = 1;
    while(1){
    int N;
    cin >> N;
    if(N == 0) break;

    vector<vector<int> > rupee(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> rupee[i][j];
        }
    }

    vector<vector<int> > dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int>  > >, greater<pair<int, pair<int, int> > > > pq;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    dist[0][0] = rupee[0][0];
    pq.push({dist[0][0], {0, 0}});

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_x = pq.top().second.first;
        int curr_y = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N ||ny >= N) continue;

            int next_dist = curr_dist + rupee[nx][ny];
            if(dist[nx][ny] > next_dist){
                dist[nx][ny] = next_dist;
                pq.push({next_dist, {nx, ny}});
            }
        }
    }

    cout << "Problem " << cnt++ << ": " << dist[N - 1][N - 1] << "\n";
    }
    return 0;
}