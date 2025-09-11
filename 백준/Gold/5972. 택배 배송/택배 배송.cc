#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

int N, M;

vector<int> dijkstra(vector<pair<int, int> > roads[]){
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0}); // (거리, 노드)

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for(int i = 0; i < (int)roads[curr_node].size(); i++){
            int next_node = roads[curr_node][i].first;
            int next_dist = roads[curr_node][i].second;

            if(dist[next_node] > curr_dist + next_dist){
                dist[next_node] = curr_dist + next_dist;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    return dist;
}

int main(){
    cin >> N >> M;

    vector<pair<int, int> > roads[N];
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        --a; --b;
        roads[a].push_back({b, c});
        roads[b].push_back({a, c});
    }

    vector<int> dist = dijkstra(roads);

    if (dist[N - 1] == INF) cout << -1 << '\n';
    else cout << dist[N - 1] << '\n';

    return 0;
}