#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, E;
int v1, v2;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < cost) continue;

        for (auto &edge : graph[curr]) {
            int next = edge.first;
            int next_cost = edge.second + cost;

            if (dist[next] > next_cost) {
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }

    return dist;
}

int main() {
    cin >> N >> E;
    graph.resize(N + 1);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    vector<int> fromStart = dijkstra(1);
    vector<int> fromV1 = dijkstra(v1);
    vector<int> fromV2 = dijkstra(v2);

    int path1 = INF;
    int path2 = INF;

    if (fromStart[v1] != INF && fromV1[v2] != INF && fromV2[N] != INF) {
        path1 = fromStart[v1] + fromV1[v2] + fromV2[N];
    }

    if (fromStart[v2] != INF && fromV2[v1] != INF && fromV1[N] != INF) {
        path2 = fromStart[v2] + fromV2[v1] + fromV1[N];
    }

    int result = min(path1, path2);

    if (result == INF) cout << -1;
    else cout << result;

    return 0;
}
