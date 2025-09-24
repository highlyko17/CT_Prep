#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer = 81;
int dx[4] = {0, -1, 0, 1};  // 0: 오른쪽 1: 위쪽 2: 왼쪽 3: 아래쪽
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int> > cctv;
vector<vector<vector<int> > > dir = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

void dfs(int depth, vector<vector<int> > office){
    if(depth == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(office[i][j] == 0) cnt++;
            }
        }
        answer = min(answer, cnt);

        return;
    }

    int currx = cctv[depth].first;
    int curry = cctv[depth].second;
    int currcctv = office[currx][curry];

    for(int i = 0; i < dir[currcctv].size(); i++){
        auto temp = office;

        for(int d: dir[currcctv][i]){
            int nx = currx;
            int ny = curry;
            
            while(true){
                nx += dx[d];
                ny += dy[d];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                if(temp[nx][ny] == 6) break;
                if(temp[nx][ny] == 0) temp[nx][ny] = -1;
            }
        }

        dfs(depth + 1, temp);
    }
}

int main(){
    cin >> N >> M;
    
    vector<vector<int> > office(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> office[i][j];

            if(office[i][j] != 0 && office[i][j] != 6){
                cctv.push_back({i, j});
            }
        }
    }

    dfs(0, office);

    cout << answer;

    return 0;
}