#include <iostream>
#include <string>
#include <vector> 
#include <climits> 
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string W;
        cin >> W;

        int K;
        cin >> K;

        vector<int> alphabets(26);
        for(int j = 0; j < W.length(); j++){
            ++alphabets[W[j] - 'a'];
        }

        int answer3 = INT_MAX;
        int answer4 = -1;

        for(int j = 0; j < W.length(); j++){
            if(alphabets[W[j] - 'a'] < K) continue;

            int cnt = 0;
            for(int k = j; k < W.length(); k++){
                if(W[k] == W[j]) cnt++;

                if(cnt == K){
                    answer3 = min(answer3, k - j + 1);
                    answer4 = max(answer4, k - j + 1);
                    break;
                }
            }
        }

        if(answer3 == INT_MAX || answer4 == -1){
            cout << -1 << '\n';
        }
        else {
            cout << answer3 << ' ' << answer4 << '\n';
        }
    }

    return 0;
}
