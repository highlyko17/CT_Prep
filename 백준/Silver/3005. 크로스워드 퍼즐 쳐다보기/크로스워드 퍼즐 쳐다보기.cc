#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> board(R);
    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }

    vector<string> answer;
    for(int i = 0; i < R; i++){
        string temp = "";

        for(int j = 0; j < C; j++){
            if(board[i][j] == '#'){
                if(temp.length() >= 2){
                    answer.push_back(temp);
                }
                temp = "";
            }
            else temp += board[i][j];
        }

        if(temp.length() >= 2)
            answer.push_back(temp);
    }

    for(int j = 0; j < C; j++){
        string temp = "";

        for(int i = 0; i < R; i++){
            if(board[i][j] == '#'){
                if(temp.length() >= 2){
                    answer.push_back(temp);
                }
                temp = "";
            }
            else temp += board[i][j];
        }

        if(temp.length() >= 2)
            answer.push_back(temp);
    }

    sort(answer.begin(), answer.end());

    cout << answer[0];

    return 0;
}