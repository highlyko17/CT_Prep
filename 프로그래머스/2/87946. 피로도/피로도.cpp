#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int k, vector<vector<int>> dungeons, int result, vector<int> visited){
    bool flag = false;
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            flag = true;
            break;
        }
    }
    
    if(!flag){
        answer = max(answer, result);
        return;
    }
    
    for(int i = 0; i < dungeons.size(); i++){
        if(dungeons[i][0] <= k && !visited[i]){
            visited[i] = true;
            k -= dungeons[i][1];
            
            dfs(k, dungeons, result + 1, visited);
            
            visited[i] = false;
            k += dungeons[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> visited(dungeons.size(), false);
    
    dfs(k, dungeons, 0, visited);
    
    return answer;
}