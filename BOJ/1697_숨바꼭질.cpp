#include <iostream>
#include <queue>

using namespace std;

int N, K, answer;
bool visited[100001];

void bfs(int num){
    queue<pair<int, int> > q;
    q.push({num, 0});
    visited[num] = true;

    while(!q.empty()){
        int currNum = q.front().first;
        int currTime = q.front().second;
        q.pop();

        if(currNum == K){
            answer = currTime;
            return ;
        }

        for(auto x : {currNum - 1, currNum + 1, currNum * 2}){
            if(x >= 0 && x <= 100000 && !visited[x]){
                visited[x] = true;
                q.push({x, currTime + 1});
            }
        }
    }
}

int main(){
    cin >> N >> K;
    if(N == K){
        cout << 0;
        return 0;
    }
    
    bfs(N);
    cout << answer;

    return 0;
}