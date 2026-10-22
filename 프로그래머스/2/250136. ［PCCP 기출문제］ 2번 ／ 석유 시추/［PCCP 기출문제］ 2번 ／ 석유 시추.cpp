#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> oil(m, 0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(visited[i][j] || !land[i][j]) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            
            int area = 0;
            vector<bool> column(m, false);
            
            while(!q.empty()){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                area += 1;
                column[cy] = true;
                
                for(int d = 0; d < 4; d++){
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || !land[nx][ny]) continue;
                    
                    
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            
            for(int col = 0; col < m; col++){
                if(column[col]){
                    oil[col] += area;
                }
            }
            
        }
    }
    
    return *max_element(oil.begin(), oil.end());
}