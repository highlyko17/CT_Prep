#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string S;
    cin >> S;

    int num;
    cin >> num;

    vector<string> A(num);
    for (int i = 0; i < num; ++i) {
        cin >> A[i];
    }

    int s_len = S.length();
    vector<bool> dp(s_len + 1, false);
    dp[0] = true;

    for(int i = 1; i <= s_len; ++i){
        for(int j = 0; j < A.size(); j++){
            int word_len = A[j].length();
            if(i >= word_len && S.substr(i - word_len, word_len) == A[j]){
                if(dp[i - word_len]){
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    if(dp[s_len]) cout << 1;
    else cout << 0;

    return 0;
}