#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

int simulate(string cur, string target, bool firstSwitch){
    int answer = 0;

    if(firstSwitch){
        answer++;
        cur[0] = (cur[0] == '0' ? '1' : '0');
        cur[1] = (cur[1] == '0' ? '1' : '0');
    }

    for(int i = 1; i < N; i++){
        if(cur[i - 1] != target[i - 1]){
            answer++;
            cur[i - 1] = (cur[i - 1] == '0' ? '1' : '0');
            cur[i] = (cur[i] == '0' ? '1' : '0');
            if(i + 1 < N) cur[i + 1] = (cur[i + 1] == '0' ? '1' : '0');
        }
    }

    if(cur == target) return answer;
    return -1;
}

int main(){
    string cur, target;
    cin >> N;
    cin >> cur >> target;

    int res1 = simulate(cur, target, false);
    int res2 = simulate(cur, target, true);

    if(res1 == -1 && res2 == -1) cout << -1;
    else if(res1 == -1) cout << res2;
    else if(res2 == -1) cout << res1;
    else cout << min(res1, res2);

    return 0;
}