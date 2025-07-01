#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    vector<int> test_cases(T);
    int MAX = 0;
    for(int i = 0; i < T; i++){
        cin >> test_cases[i];
        MAX = max(MAX, test_cases[i]);
    }
    
    vector<int> dp(MAX + 1, 0);
    dp[0] = 1;

    for(int num : {1, 2, 3}){
        for(int i = num; i <= MAX; i++){
            dp[i] += dp[i - num];
        }
    }

    for(int i = 0; i < test_cases.size(); i++){
        cout << dp[test_cases[i]] << '\n';
    }

    return 0;
}