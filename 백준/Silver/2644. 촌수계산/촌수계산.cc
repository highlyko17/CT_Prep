#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    int first, second;
    cin >> first >> second;

    int m;
    cin >> m;

    vector<vector<int>> parent(N + 1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        parent[x].push_back(y);
        parent[y].push_back(x);
    }

    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    
    q.push({first, 0});
    visited[first] = true;
    
    int answer;
    while(!q.empty()){
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(curr == second){
            cout << dist;
            return 0;
        }

        for(int i = 0; i < parent[curr].size(); i++){
            int next_node = parent[curr][i];
            if(!visited[next_node]){
                visited[next_node] = true;
                q.push({next_node, dist + 1});
            }
        }
    }

    cout << -1;

    return 0;
}