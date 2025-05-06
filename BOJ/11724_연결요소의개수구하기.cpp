#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int> > V;
static vector<bool> visited;

void DFS(int v){
    if(visited[v]) return;

    visited[v] = true;

    for(int i : V[v]){
        if(!visited[i]) DFS(i);
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    V.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;

        V[start].push_back(end);
        V[end].push_back(start);
    }

    int count = 0;

    for(int i = 1; i < N + 1; i++){
        if(!visited[i]){
            count++;
            DFS(i);
        }
    }

    cout << count << endl;
}