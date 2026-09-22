#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> newRectangle;
bool visited[105][105];
int board[105][105] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i = 0; i < rectangle.size(); i++){
        newRectangle.push_back({rectangle[i][0] * 2, rectangle[i][1] * 2, rectangle[i][2] * 2, rectangle[i][3] * 2});
    }
    
    for(int i = 0; i < newRectangle.size(); i++){
        int x1 = newRectangle[i][0];
        int y1 = newRectangle[i][1];
        int x2 = newRectangle[i][2];
        int y2 = newRectangle[i][3];
        
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                if(board[x][y] == 2) continue;
                
                if(x == x1 || x == x2 || y == y1 || y == y2) board[x][y] = 1;
                else board[x][y] = 2;
            }
        }
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {characterX, characterY}});
    visited[characterX][characterY] = true;
    
    while(!q.empty()){
        int dist = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(cx == itemX && cy == itemY){
            return dist / 2;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 102 || ny >= 102 || visited[nx][ny]) continue;
            
            if(board[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push({dist + 1, {nx, ny}});
            }
        }
    }

    
    return -1;
}