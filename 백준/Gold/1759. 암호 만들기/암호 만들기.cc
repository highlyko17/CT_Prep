#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> cur, chars;

bool checkVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int idx, int depth, int vowel, int cons){
    if(depth == L){
        if(vowel >= 1 && cons >= 2){
            for(char c : cur) cout << c;
            cout << '\n';
        }
        return ;
    }

    for(int i = idx; i < C; i++){
        cur.push_back(chars[i]);
        if(checkVowel(chars[i]))
            dfs(i + 1, depth + 1, vowel + 1, cons);
        else dfs(i + 1, depth + 1, vowel, cons + 1);
        cur.pop_back();
    }
}

int main(){
    cin >> L >> C;
    chars.resize(C);
    for(int i = 0; i < C; i++) cin >> chars[i];
    sort(chars.begin(), chars.end());

    dfs(0, 0, 0, 0);

    return 0;
}