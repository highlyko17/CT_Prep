#include <string>
#include <vector>

using namespace std;

int answer = 0;
string aeiou = "AEIOU";
string target = "";

void dfs(string word, int& cnt){
    if(target == word){
        answer = cnt;
        return;
    }
    
    if(word.length() >= 5) return;
    
    for(int i = 0; i < 5; i++){
        if(answer == 0)
            cnt++;
            dfs(word + aeiou[i], cnt);
    }
}

int solution(string word) {
    target = word;
    
    int start_cnt = 0;
    dfs("", start_cnt);

    return answer;
}