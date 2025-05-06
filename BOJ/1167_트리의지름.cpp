#include <iostream>
#include <vector>

using namespace std;

int V;
vector<pair<int, int> > tree[100001];
bool visited[100001];
int max_node = 0, max_way = 0;

void dfs(int node, int way){
    if(way > max_way){
        max_way = way;
        max_node = node;
    }

    visited[node] = true;
    for(int i = 0; i < tree[node].size(); i++){
        int next = tree[node][i].first;
        int weight = tree[node][i].second;

        if(!visited[next]){
            dfs(next, way + weight);
        }
    }
}

int main(){
    cin >> V;

    for(int i = 0; i < V; i++){
        int node;
        cin >> node;
        while(1){
            int connected, distance;
            cin >> connected;

            if(connected == -1) break;

            cin >> distance;

            tree[node].push_back({connected, distance});
            tree[connected].push_back({node, distance});
        }
    }

    dfs(1, 0);

    for(int i = 1; i <= V; i++){
        visited[i] = false;
    }
    max_way = 0;
    dfs(max_node, 0);

    cout << max_way;

    return 0;
}