#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    int house[N + 1][3];
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> house[i][j];
        }
    }

    int dp[N + 1][3];
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];

    for(int i = 2; i <= N; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }

    int result = min({dp[N][0], dp[N][1], dp[N][2]});
    cout << result;

    return 0;
}