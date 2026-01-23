#include <iostream>
#include <vector>

using namespace std;

int paper[130][130];
int cnt[2];

bool isSame(int row, int col, int size){
    int first = paper[row][col];

    for(int i = row; i < row + size; i++){
        for(int j = col; j < col + size; j++){
            if(first != paper[i][j]) return false;
        }
    }

    return true;
}

void solve(int row, int col, int size){
    if(isSame(row, col, size)){
        cnt[paper[row][col]]++;
        return;
    }

    int newSize = size / 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            solve(row + i * newSize, col + j * newSize, newSize);
        }
    }

    return;
}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << cnt[0] << '\n' << cnt[1];

    return 0;
}