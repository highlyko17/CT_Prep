#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ps[51][51];
int arr[51][51];

int sum(int x1, int y1, int x2, int y2){
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            ps[i][j] = arr[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    long long answer = 0;

    //세로 3등분
    for(int i = 1; i <= M - 2; i++){
        for(int j = i + 1; j <= M - 1; j++){
            long long a = sum(1, 1, N, i);
            long long b = sum(1, i + 1, N, j);
            long long c = sum(1, j + 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    //가로 3등분
    for(int i = 1; i <= N - 2; i++){
        for(int j = i + 1; j <= N - 1; j++){
            long long a = sum(1, 1, i, M);
            long long b = sum(i + 1, 1, j, M);
            long long c = sum(j + 1, 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    //세로, 가로
    for(int i = 1; i <= M - 1; i++){
        for(int j = 1; j <= N - 1; j++){
            long long a = sum(1, 1, N, i);
            long long b = sum(1, i + 1, j, M);
            long long c = sum(j + 1, i + 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    //가로, 세로
    for(int i = 1; i <= M - 1; i++){
        for(int j = 1; j <= N - 1; j++){
            long long a = sum(1, 1, j, i);
            long long b = sum(j + 1, 1, N, i);
            long long c = sum(1, i + 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    //가로
    //세로
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long a = sum(1, 1, i, M);
            long long b = sum(i + 1, 1, N, j);
            long long c = sum(i + 1, j + 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    //세로
    //가로
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= M - 1; j++){
            long long a = sum(1, 1, i, j);
            long long b = sum(1, j + 1, i, M);
            long long c = sum(i + 1, 1, N, M);

            answer = max(answer, a*b*c);
        }
    }

    cout << answer;

    return 0;
}