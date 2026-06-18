#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); int m = maps[0].size();
    if(maps[n - 1][m - 2] == 0 && maps[n - 2][m - 1] == 0) return -1;
    
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    maps[0][0] = 0;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(cx == n - 1 && cy == m - 1) return dist;
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= n || ny >= m || nx < 0 || ny < 0 || !maps[nx][ny]) continue;
            
            q.push({{nx, ny}, dist + 1});
            maps[nx][ny] = 0;
        }
    }
        
    return -1;
}