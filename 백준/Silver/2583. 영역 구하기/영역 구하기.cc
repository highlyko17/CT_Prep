#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];
int M, N, K;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int y, int x){
    if(arr[y][x] == 1) return 0;
    if(y < 0 || y >= M || x < 0 || x >= N) return 0;
    
    arr[y][x] = 1;

    int area = 1;

    for(int i = 0; i < 4; i++){
        area += dfs(y + dy[i], x + dx[i]);
    }

    return area;
}

int main(){
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; y++){
            for(int x = x1; x < x2; x++){
                arr[y][x] = 1;
            }
        }
    }

    vector<int> answer;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 0){
                answer.push_back(dfs(i, j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }

    return 0;
}