#include <iostream>

using namespace std;
int map[30][30];
int answer = 0;
int visited[20] = {};
int n, m;

void dfs(int v){
    if(v == n) {
        answer++;
    }

    for(int i = 1; i <= n; i++){
        if(map[v][i] && !visited[i]){
            visited[i] = 1;
            dfs(i);
            visited[i] = 0;
        }
    }
}

int main(){
    freopen("64input.txt", "rt", stdin);
    int a, b;

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        map[a][b] = 1; 
    }

    visited[1] = 1;
    dfs(1);
    cout << answer;

    return 0;
}