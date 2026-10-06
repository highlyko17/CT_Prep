#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer = 0;
int N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<pair<int, int>>> blanks;
vector<vector<pair<int, int>>> puzzle;

vector<pair<int, int>> bfs(int x, int y, int target, vector<vector<int>> board, vector<vector<bool>> &visited){
    vector<pair<int, int>> result;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        result.push_back({cx, cy});
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= N || nx < 0 || ny >= N || ny < 0 || visited[nx][ny] || board[nx][ny] != target) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return result;
}

vector<pair<int, int>> normalize(vector<pair<int, int>> block){
    int minX = 51;
    int minY = 51;
    
    for(auto[x, y] : block){
        minX = min(minX, x);
        minY = min(minY, y);
    }
    
    for(auto&[x, y] : block){
        x -= minX;
        y -= minY;
    }
    
    sort(block.begin(), block.end());
    
    return block;
}

vector<pair<int, int>> rotateBlock(vector<pair<int, int>> block){
    for(auto &[x, y] : block){
        int nx = y;
        int ny = -x;
        
        x = nx;
        y = ny;
    }
    
    return normalize(block);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = game_board.size();
    
    vector<vector<bool>> boardVisited(N, vector<bool>(N, false));
    vector<vector<bool>> tableVisited(N, vector<bool>(N, false));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(game_board[i][j] == 0 && !boardVisited[i][j]){
                vector<pair<int, int>> curr = bfs(i, j, 0, game_board, boardVisited);
                blanks.push_back(normalize(curr));
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(table[i][j] == 1 && !tableVisited[i][j]){
                vector<pair<int, int>> curr = bfs(i, j, 1, table, tableVisited);
                puzzle.push_back(normalize(curr));
            }
        }
    }
    
    //대조
    vector<bool> used(puzzle.size(), false);
    
    for(auto blank : blanks){
        for(int i = 0; i < puzzle.size(); i++){
            if(used[i]) continue;
            
            if(blank.size() != puzzle[i].size()) continue;
            
            vector<pair<int, int>> piece = puzzle[i];
            
            for(int r = 0; r < 4; r++){
                if(blank == piece){
                    used[i] = true;
                    answer += piece.size();
                    break;
                }
                
                piece = rotateBlock(piece);
            }
            
            if(used[i]) break;
        }
    }
    
    return answer;
}