#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int w = park[0].length();
    int h = park.size();
    int x = 0, y = 0;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(park[i][j] == 'S'){
                y = i;
                x = j;
                break;
            }
        }
    }
    
    // 방향 설정: N, S, W, E
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

    
    for(int i = 0; i < routes.size(); i++){
        char dir = routes[i][0];
        int dist = routes[i][2] - '0';
        
        int d = 0;
        if (dir == 'N') d = 0;
        else if (dir == 'S') d = 1;
        else if (dir == 'W') d = 2;
        else if (dir == 'E') d = 3;
    
        int nx = x, ny = y;
        bool valid = true;
        
        for(int i = 0; i < dist; i++){
            nx += dx[d];
            ny += dy[d];
            
            if(nx < 0 || ny < 0 || nx >= w || ny >= h || park[ny][nx] == 'X'){
                valid = false;
                break;
            }
        }
        
        if(valid){
            x = nx;
            y = ny;
        }
    }
    
    return {y, x};
}