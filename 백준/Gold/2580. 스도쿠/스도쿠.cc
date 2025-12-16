#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));

bool check(int i, int j, int num){
    for(int n = 0; n < 9; n++){
        if(sudoku[i][n] == num) return false;
        if(sudoku[n][j] == num) return false;
        if(sudoku[3*(i/3) + n/3][3*(j/3) + n%3] == num) return false;
    }

    return true;
}

bool solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                for(int num = 1; num <= 9; num++){
                    if(check(i, j, num)){
                        sudoku[i][j] = num;

                        if(solve()) return true;

                        sudoku[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
        }
    }

    solve();

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}