#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int tri[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    int dp[501][501] = {0,};
    dp[1][1] = tri[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
        }
    }

    int maxVal = 0;
    for(int i = 1; i <= n; i++){
        maxVal = max(maxVal, dp[n][i]);
    }
    cout << maxVal;

    return 0;
}