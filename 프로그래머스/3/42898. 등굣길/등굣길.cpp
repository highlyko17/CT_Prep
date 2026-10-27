#include <string>
#include <vector>

using namespace std;

//puddles[n][m] = puddles[x][y];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(auto p : puddles){
        dp[p[1]][p[0]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == -1) continue;
            if(i == 1 && j == 1) continue;
            
            int up = 0;
            int left = 0;
            
            if(i > 1 && dp[i - 1][j] != -1){
                up = dp[i - 1][j];
            }
            
            if(j > 1 && dp[i][j - 1] != -1){
                left = dp[i][j - 1];
            }
            
            dp[i][j] = (up + left) % 1000000007;
        }
    }
    
    return dp[n][m];
}