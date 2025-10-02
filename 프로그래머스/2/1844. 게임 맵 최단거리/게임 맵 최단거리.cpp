#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); //세로, i, x
    int m = maps[0].size(); //가로, j, y
    
    //if(maps[n - 2][m - 1] == 0 && maps[n - 1][m - 2] == 0) return -1;
    
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({1, {0, 0}});
    visited[0][0] = true;
    
    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(x == n - 1 && y == m - 1){
            return cnt;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if(maps[nx][ny] == 1 && !visited[nx][ny]){
                q.push({cnt + 1, {nx, ny}});
                visited[nx][ny] = true;
            }
        }
    }
    
    return -1;
}