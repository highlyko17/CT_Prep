#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.length();
    
    for(int i = 0; i < length; i++){
        if(i == 0 && isalpha(s[i])){
            s[i] = toupper(s[i]);
        }
        else if((isalpha(s[i])) && (s[i - 1] == ' ')){
            s[i] = toupper(s[i]);
        }
        else if(isalpha(s[i])){
            s[i] = tolower(s[i]);
        }
        answer += s[i];
    }
    return answer;
}