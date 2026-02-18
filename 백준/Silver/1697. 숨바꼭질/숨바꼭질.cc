#include <iostream>
#include <queue>

using namespace std;

int N, K, answer;
bool visited[100001];

int main(){
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(curr == K){
            answer = sec;
            break;
        }

        for(auto x: {curr - 1, curr + 1, curr * 2}){
            if(x >= 0 && x <= 100000 && !visited[x]){
                visited[x] = true;
                q.push({x, sec + 1});
            }
        }
    }

    cout << answer;

    return 0;
}