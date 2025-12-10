#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<bool> isPrime(10000, false);

bool ifPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }

    return true;
}

void makePrime(){
    for(int i = 1000; i <= 9999; i++){
        if(ifPrime(i)) isPrime[i] = true;
    }
}

int bfs(int start, int target){
    vector<bool> visited(10000, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(curr == target) return level;

        string curr_str = to_string(curr);
        
        for(int i = 0; i < 4; i++){
            char curr_c = curr_str[i];
            for(char c = '0'; c <= '9'; c++){
                if(curr_c == c) continue;
                if(i == 0 && c == '0') continue;
                
                curr_str[i] = c;
                int next = stoi(curr_str);

                if(isPrime[next] && !visited[next]){
                    q.push({next, level + 1});
                    visited[next] = true;
                }
            }
            curr_str[i] = curr_c;
        }
    }

    return -1;
}

int main(){
    int T;
    cin >> T;

    makePrime();

    while(T--){
        int start, target;
        cin >> start >> target;

        if(start == target){
            cout << 0 << '\n';
            continue;
        }

        int answer = bfs(start, target);

        if(answer == -1) cout << "Impossible\n";
        else cout << answer << "\n";
    }

    return 0;
}