#include <iostream>
#include <string>

using namespace std;

bool checkWin(string str, char ch){
    int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for(int i = 0; i < 8; i++){
        int first = lines[i][0], second = lines[i][1], third = lines[i][2];

        if(str[first] == ch && str[second] == ch && str[third] == ch)
            return true;
    }
    return false;
}

int main(){
    while(1){
        string str;
        cin >> str;
        if(str == "end") break;

        int empty = 0, x = 0, o = 0, board[3][3];
        for(int i = 0; i < 9; i++){
            if(str[i] == 'X') x++;
            else if(str[i] == 'O') o++;
            else empty++;
        }

        if(!(x == o || x == o + 1)){
            cout << "invalid\n";
            continue;
        }
        
        //승패 검사
        bool winX = checkWin(str, 'X');
        bool winO = checkWin(str, 'O');

        //둘 다 승리면
        if(winX && winO){
            cout << "invalid\n";
            continue;
        }
        //무승부
        if(!winX && !winO){
            if(empty == 0){
                cout << "valid\n";
            }
            else{
                cout << "invalid\n";
            }
            continue;
        }
        //x가 승리
        if(winX){
            if(x == o + 1) cout << "valid\n";
            else cout << "invalid\n";
            continue;
        }
        //o가 승리
        if(winO){
            if(x == o) cout << "valid\n";
            else cout << "invalid\n";
            continue;
        }
    }

    return 0;
}