#include <string>
#include <vector>

using namespace std;

int compress(int length, string s){
    for(int i = 0; i < s.size();){
        string temp = s.substr(i, length);
        int equal = 1;
        for(int j = i + length; j < s.size(); j += length){
            if(temp == s.substr(j, length)) equal++;
            else break;
        }
        if(equal == 1){
            i += length;
            continue;
        }
        temp = to_string(equal) + temp;
        string rest = s.substr(equal * length + i);
        s = s.substr(0, i) + temp + rest;
        i += temp.size();
    }
    
    return s.size();
}

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= s.size(); i++){
        answer = min(answer, compress(i, s));
    }
    
    return answer;
}