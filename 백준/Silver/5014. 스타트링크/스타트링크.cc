#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    //건물 총 F층
    //건우 현재 위치 S층
    //스타트링크 위치 G층

    vector<bool> visited(F + 1, false);
    queue<pair<int, int>> q;
    q.push({S, 0});
    visited[S] = true;

    int dir[2] = {U, -D};

    while(!q.empty()){
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(curr == G){
            cout << cnt;
            return 0;
        }

        for(int i = 0; i < 2; i++){
            int next = curr + dir[i];

            if(next <= 0 || next > F || visited[next]) continue;

            visited[next] = true;
            q.push({next, cnt + 1});
        }
    }

    cout << "use the stairs";

    return 0;
}