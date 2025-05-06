#include <iostream>
#include <vector>

using namespace std;

int n;
int max_way = 0;
int max_node = 0;
vector<pair<int, int> > tree[10001];
bool visited[10001] = {false, };

void dfs(int node, int way){
    if (way > max_way) {
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
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    dfs(1, 0);
    
    for(int i = 1; i <= n; i++){
        visited[i] = false;
    }
    max_way = 0;
    dfs(max_node, 0);

    cout << max_way;

    return 0;
}