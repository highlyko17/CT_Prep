#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    
    vector<string> board(n + 2, string(m + 2, ' '));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i + 1][j + 1] = storage[i][j];
        }
    }
    
    n += 2; m += 2;
    
    for(string r: requests){
        char target = r[0];
        
        if(r.length() == 2){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(target == board[i][j]) board[i][j] = ' ';
                }
            }
        }
        else{
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pair<int, int>> q;
            
            q.push({0, 0});
            visited[0][0] = true;
            
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            
            while(!q.empty()){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(visited[nx][ny] == true) continue;
                    
                    if(board[nx][ny] == ' '){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            
            vector<pair<int, int>> removeList;
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == target){
                        for(int d = 0; d < 4; d++){
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            
                            if(visited[nx][ny]) {
                                removeList.push_back({i, j});
                                break;
                            }
                        }
                    }
                }
            }
            
            for(auto [x, y]: removeList){
                board[x][y] = ' ';
            }
            
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}