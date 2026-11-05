#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n) {
    int answer = 0;
    
    if(n % 2 == 1) return 0;
    
    vector<long long> dp(n + 1, 0);
    
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i <= n; i += 2){
        dp[i] = (4 * dp[i - 2] - dp[i - 4] + MOD) % MOD;
    }
    
    return dp[n];
}