#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int answer = INT_MAX;

void dfs(int stage, int total,
        vector<int> &cnt,
        vector<vector<int>> &cost,
        vector<vector<int>> &hint){
    
    if(stage == n){
        answer = min(total, answer);
        return;
    }
    
    int used = min(n - 1, cnt[stage]);
    int current = total + cost[stage][used];
    
    if(current >= answer) return;
    
    if(stage == n - 1){
        dfs(stage + 1, current, cnt, cost, hint);
        return;
    }
    
    dfs(stage + 1, current, cnt, cost, hint);
    
    for(int i = 1; i < hint[stage].size(); i++){
        int temp = hint[stage][i] - 1;
        cnt[temp]++;
    }
    
    dfs(stage + 1, current + hint[stage][0], cnt, cost, hint);
    
    for(int i = 1; i < hint[stage].size(); i++){
        int temp = hint[stage][i] - 1;
        cnt[temp]--;
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    n = cost.size();
    
    vector<int> cnt(n, 0);
    
    dfs(0, 0, cnt, cost, hint);
    
    return answer;
}