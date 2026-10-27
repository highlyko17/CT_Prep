#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501] = {0};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int row = triangle.size();

    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < row; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0){
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
                continue;
            }
            
            if(j == triangle[i].size() - 1){
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                continue;
            }
            
            int direction = max(dp[i - 1][j], dp[i - 1][j - 1]);
            dp[i][j] = direction + triangle[i][j];
            
        }
    }
    
    for(int i = 0; i < triangle[row - 1].size(); i++){
        if(dp[row - 1][i] > answer) answer = dp[row - 1][i];
    }
    
    return answer;
}