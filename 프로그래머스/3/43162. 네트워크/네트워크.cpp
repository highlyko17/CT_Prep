#include <string>
#include <vector>

using namespace std;

bool visited[201] = {false};

void dfs(int n, vector<vector<int>> computers, int idx){
    for(int i = 0; i < n; i++){
        if(!visited[i] && computers[idx][i] == 1){
            visited[i] = true;
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(n, computers, i);
            answer++;
        }
    }
    
    return answer;
}