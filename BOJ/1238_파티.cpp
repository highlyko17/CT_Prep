#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int src, int N, vector<vector<pair<int, int>>>& graph){
    vector<int> dist(N + 1, 1e9);
    dist[src] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, src});

    while(!pq.empty()){
        int weight = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(weight > dist[current]) continue;

        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int next_weight = graph[current][i].second + weight;

            if(dist[next] > next_weight){
                dist[next] = next_weight;
                pq.push({next_weight, next});
            }
        }
    }

    return dist;
}

int main(){
    int N, M, X; // 학생 수, 단방향 도로 수, 파티 마을
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> roads(N + 1);
    vector<vector<pair<int, int>>> reverse_roads(N + 1);
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        roads[a].push_back({b, c});
        reverse_roads[b].push_back({a, c});
    }

    vector<int> to_X = dijkstra(X, N, roads);
    vector<int> from_X = dijkstra(X, N, reverse_roads);

    int max_weight = 0;
    for(int i = 1; i <= N; i++){
        if(i == X) continue;

        max_weight = max(max_weight, to_X[i] + from_X[i]);
    }

    cout << max_weight;
    return 0;
}