#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int board[101] = {0,};
    bool visited[101] = {false, };
    for(int i = 0; i < N + M; i++){
        int a, b;
        cin >> a >> b;

        board[a] = b;
    }

    queue<pair<int, int> > q;
    q.push({1, 0});
    visited[1] = true;

    while(!q.empty()){
        int l = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(l == 100){
            cout << cnt;
            return 0;
        }

        for(int i = 1; i < 7; i++){
            int nl = l + i;

            if(nl > 100 || visited[nl]) continue;
            if(board[nl] > 0) nl = board[nl];
            q.push({nl, cnt + 1});
            visited[nl] = true;
        }
    }

    return 0;
}