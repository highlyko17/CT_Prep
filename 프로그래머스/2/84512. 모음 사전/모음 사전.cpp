#include <string>
#include <vector>

using namespace std;

int answer = 0;
string aeiou = "AEIOU";
int cnt = 0;
string target;

void dfs(string word){
    if(word == target){
        answer = cnt;
        return;
    }
    
    if(word.length() >= 5) return;
    
    for(int i = 0; i < 5; i++){
        //if(answer == 0){
            cnt++;
            dfs(word + aeiou[i]);
        //}
    }
}

int solution(string word) {
    target = word;
    
    dfs("");
    
    return answer;
}