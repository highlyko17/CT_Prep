#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> board(R);
    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }

    vector<string> words;

    for(int i = 0; i < R; i++) {
        string temp = "";
        for(int j = 0; j < C; j++) {
            if(board[i][j] == '#') {
                if(temp.length() >= 2)
                    words.push_back(temp);
                temp = "";
            } else {
                temp += board[i][j];
            }
        }
        if(temp.length() >= 2)
            words.push_back(temp);
    }

    for(int j = 0; j < C; j++) {
        string temp = "";
        for(int i = 0; i < R; i++) {
            if(board[i][j] == '#') {
                if(temp.length() >= 2)
                    words.push_back(temp);
                temp = "";
            } else {
                temp += board[i][j];
            }
        }
        if(temp.length() >= 2)
            words.push_back(temp);
    }

    sort(words.begin(), words.end());

    cout << words[0];

    return 0;
}
