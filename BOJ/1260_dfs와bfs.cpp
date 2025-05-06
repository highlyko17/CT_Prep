#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V; // 정접의 개수, 간선의 개수, 출발점
vector<vector<int> > graph(1001);
queue<int> bfsAnswer;
bool bfsVisited[1001] = {false}, dfsVisited[1001] = {false};

void dfs(int num){
    dfsVisited[num] = true;
    cout << num << ' ';

    for(size_t i = 0; i < graph[num].size(); i++){
        int nextNode = graph[num][i];
        if(!dfsVisited[nextNode]) dfs(nextNode);
    }
}

void bfs(int num){
    bfsAnswer.push(num);
    bfsVisited[num] = true;

    while(!bfsAnswer.empty()){
        int currNode = bfsAnswer.front();
        cout << currNode << ' ';
        bfsAnswer.pop();

        //sort(graph[currNode].begin(), graph[currNode].end());

        for(size_t i = 0; i < graph[currNode].size(); i++){
            int nextNode = graph[currNode][i];
            if(!bfsVisited[nextNode]){
                bfsVisited[nextNode] = true;
                bfsAnswer.push(nextNode);
            }
        }
    }

    return ;
}

int main(){
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << endl;
    bfs(V);

    return 0;
}