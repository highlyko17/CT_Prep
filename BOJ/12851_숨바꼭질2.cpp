#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    if(N == K){
        cout << 0 << "\n" << 1;
        return 0;
    }

    queue<pair<int, int> > q;
    bool visited[100001] = {false};
    q.push({N, 0});
    visited[N] = true;

    bool first = true;
    int result_sec = -1; // 최소 시간
    int result_cnt = 0; // 경우의 수

    while(!q.empty()){
        int curr_loc = q.front().first;
        int sec = q.front().second;
        q.pop();

        visited[curr_loc] = true;
        if(!first && (curr_loc == K) && (result_sec == sec)){
            result_cnt++;
        }
        
        if(first && (curr_loc == K)){
            result_sec = sec;
            result_cnt++;
            first = false;
        }
        
        for(auto next : {curr_loc * 2, curr_loc - 1, curr_loc + 1}){
            if(next >= 0 && next <= 100000 && !visited[next]){
                q.push({next, sec + 1});
            }
        }
    }

    cout << result_sec << '\n' << result_cnt;

    return 0;
}