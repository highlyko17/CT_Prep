#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int V, E, start;
    cin >> V >> E;
    cin >> start;

    vector<vector<pair<int, int> > > g(V + 1);
    for(int i = 0; i < E; i++){
        int a, b, c; // a: 시작노드 b: 도착노드 c: 가중치
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }

    vector<int> dist(V + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int currNode = pq.top().second;
        int currWeight = pq.top().first;
        pq.pop();

        if(currWeight > dist[currNode]) continue;

        for(int i = 0; i < g[currNode].size(); i++){
            int nextNode = g[currNode][i].first;
            int nextWeight = g[currNode][i].second;

            if(dist[nextNode] > currWeight + nextWeight){
                dist[nextNode] = currWeight + nextWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == 1e9)
            cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}