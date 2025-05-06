#include <iostream>
#include <vector>

using namespace std;
int N, M, answer = 0;
int visited[30];
vector<vector<int> > v(30);

void dfs(int num){
    if(num == N){
        answer++;
        return;
    }

    for(int i = 0; i < v[num].size(); i++){
        if(!visited[v[num][i]]){
            visited[v[num][i]] = 1;
            dfs(v[num][i]);
            visited[v[num][i]] = 0;
        }
    }
}

int main(){
    freopen("66input.txt", "rt", stdin);

    int a, b;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
    }

    visited[1] = 1;
    dfs(1);
    cout << answer;

    return 0;
}