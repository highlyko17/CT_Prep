#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> area;
vector<int> num(100, 0);

void srch(int x, int y, vector<vector<int>> &newArea){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N || newArea[nx][ny] <= 0) continue;
        
        newArea[nx][ny] = 0;
        srch(nx, ny, newArea);
    }

    return ;
}

int main(){
    cin >> N;
    area = vector<vector<int>>(N, vector<int>(N));

    int minH = 100;
    int maxH = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> area[i][j];

            minH = min(minH, area[i][j]);
            maxH = max(maxH, area[i][j]);
        }
    }

    for(int h = minH - 1; h < maxH; h++){
        vector<vector<int>> newArea = area;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                newArea[i][j] -= h;
            }
        }

        int temp = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(newArea[i][j] > 0){
                    newArea[i][j] = 0;
                    srch(i, j, newArea);
                    temp++;
                }
            }
        }

        answer = max(answer, temp);
    }

    cout << answer;

    return 0;
}