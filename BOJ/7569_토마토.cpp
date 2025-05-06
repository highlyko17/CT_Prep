#include <iostream>
#include <queue>

using namespace std;

int main(){
    int M, N, H;
    cin >> M >> N >> H;

    bool has_unripe = false;
    int box[101][101][101];
    queue<pair<pair<int, int>, int> > q;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> box[k][i][j];
                if(box[k][i][j] == 1) q.push({{i, j}, k});
                else has_unripe = true;
            }
        }
    }

    if(!has_unripe){
        cout << 0;
        return 0;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int df[2] = {1, -1};
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cf = q.front().second;
        q.pop();

        //상하좌우
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M && box[cf][nx][ny] == 0){
                box[cf][nx][ny] =  box[cf][cx][cy] + 1;
                q.push({{nx, ny}, cf});
            }
        }

        //위아래
        for(int i = 0; i < 2; i++){
            int nf = cf + df[i];

            if(nf >= 0 && nf < H && box[nf][cx][cy] == 0){
                box[nf][cx][cy] = box[cf][cx][cy] + 1;
                q.push({{cx, cy}, nf});
            }
        }
    }

    int max_days = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(box[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                if(box[i][j][k] >= 1){
                    max_days = max(max_days, box[i][j][k]);
                }
            }
        }
    }

    cout << max_days - 1;

    return 0;
}