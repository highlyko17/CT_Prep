#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, answer = 1;
vector<string> v;
bool visited[26] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int curr){
    answer = max(answer, curr);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < R && ny < C){
            if(!visited[v[nx][ny] - 'A']){
                visited[v[nx][ny] - 'A'] = true;
                dfs(nx, ny, curr + 1);
                visited[v[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main(){
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        string s;
        cin >> s;

        v.push_back(s);
    }

    visited[v[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer;

    return 0;
}