#include <iostream>
#include <vector>

using namespace std;

int paper[2200][2200];
int cnt[3]; // -1, 0, 1의 개수 (인덱스: 0->-1, 1->0, 2->1)

bool isSame(int row, int col, int size){
    int first = paper[row][col];

    for(int i = row; i < row + size; i++){
        for(int j = col; j < col + size; j++){
            if(paper[i][j] != first) return false;
        }
    }

    return true;
}

void solve(int row, int col, int size){
    if(isSame(row, col, size)){
        int num = paper[row][col];
        cnt[num + 1]++;
        return;
    }

    int newSize = size / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            solve(row + i * newSize, col + j * newSize, newSize);
        }
    }

}

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];

    return 0;
}