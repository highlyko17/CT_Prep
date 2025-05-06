#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int apt[26][26] = {0, };
bool visited[26][26]; // 방문 확인
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int srch(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && apt[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    return cnt;
}


int main(){
    cin >> N;

    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            apt[i][j] = input[j] - '0';
        }
    }

    int apt_cnt = 0;
    vector<int> cnt_each; // 단지별 동수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(apt[i][j] == 1 && !visited[i][j]){
                cnt_each.push_back(srch(i, j));
                apt_cnt++;
            }
        }
    }

    cout << apt_cnt << '\n';
    sort(cnt_each.begin(), cnt_each.end());
    for(auto i = 0; i < cnt_each.size(); i++){
        cout << cnt_each[i] << '\n';
    }

    return 0;
}