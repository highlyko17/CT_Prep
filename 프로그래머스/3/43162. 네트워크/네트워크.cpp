#include <string>
#include <vector>

using namespace std;

int visited[201];

void dfs(int curr, vector<vector<int>> computers){
    for(int i = 0; i < computers.size(); i++){
        if(i != curr && computers[curr][i] && !visited[i]){
            visited[i] = true;
            dfs(i, computers);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, cnt = 0;
    
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, computers);
            cnt++;
        }
    }
    
    answer = cnt;
    
    return answer;
}