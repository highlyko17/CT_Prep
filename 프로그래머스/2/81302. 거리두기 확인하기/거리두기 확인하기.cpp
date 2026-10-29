#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(vector<string>& room, int x, int y) {
    bool visited[5][5] = {false};

    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (dist == 2) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5
                || visited[nx][ny]) continue;

            if (room[nx][ny] == 'X') continue;

            if (room[nx][ny] == 'P') return false;

            visited[nx][ny] = true;
            q.push({{nx, ny}, dist + 1});
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {
        bool flag = true;

        for (int j = 0; j < 5 && flag; j++) {
            for (int k = 0; k < 5; k++) {

                if (places[i][j][k] == 'P') {
                    if (!check(places[i], j, k)) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}