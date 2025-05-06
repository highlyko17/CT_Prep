#include <iostream>
#include <queue>

using namespace std;

int M, N;
int box[1001][1001];
bool has_unripe = false;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j}); 
            }
            if (box[i][j] == 0) {
                has_unripe = true; 
            }
        }
    }
    
    if (!has_unripe) {
        cout << 0;
        return 0;
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0) {
                box[nx][ny] = box[x][y] + 1; 
                q.push({nx, ny});
            }
        }
    }
    
    int max_days = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (box[i][j] > 1) {
                max_days = max(max_days, box[i][j]);
            }
        }
    }
    
    cout << max_days - 1;
    return 0;
}