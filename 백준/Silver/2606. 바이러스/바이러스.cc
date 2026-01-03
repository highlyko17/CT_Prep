#include <iostream>
#include <vector>

using namespace std;

int N, M, answer = 0;
vector<vector<int>> computers;
vector<bool> visited;

void dfs(int curr){
    for(int i = 0; i < computers[curr].size(); i++){
        int temp = computers[curr][i];

        if(!visited[temp]){
            visited[temp] = true;
            answer++;
            dfs(temp);
        }
    }

    return;
}

int main(){
    cin >> N >> M;

    computers = vector<vector<int>>(N);
    visited = vector<bool>(N, false);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        computers[a - 1].push_back(b - 1);
        computers[b - 1].push_back(a - 1);
    }

    visited[0] = true;
    dfs(0);

    cout << answer;

    return 0;
}