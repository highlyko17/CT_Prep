#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int house[33][33];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> house[i][j];
        }
    }
    
    long long dp[33][33][3] = {0};
    
    dp[1][2][0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(house[i][j] == 1) continue;
            
            if(j+1 <= N && house[i][j+1] == 0) {
                dp[i][j+1][0] += dp[i][j][0];
                dp[i][j+1][0] += dp[i][j][2];
            }
            
            if(i+1 <= N && house[i+1][j] == 0) {
                dp[i+1][j][1] += dp[i][j][1];
                dp[i+1][j][1] += dp[i][j][2];
            }
            
            if(i+1 <= N && j+1 <= N && house[i+1][j] == 0 && house[i][j+1] == 0 && house[i+1][j+1] == 0) {
                dp[i+1][j+1][2] += dp[i][j][0];
                dp[i+1][j+1][2] += dp[i][j][1];
                dp[i+1][j+1][2] += dp[i][j][2];
            }
        }
    }
    
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << endl;
    
    return 0;
}