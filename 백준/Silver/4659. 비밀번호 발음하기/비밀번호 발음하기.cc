#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else return false;
}

bool firstCondition(string str){
    for(char c : str){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
    }

    return false;
}

bool secondCondition(string str){
    int len = str.length();

    for(int i = 2; i < len; i++){
        if(isVowel(str[i - 2]) && isVowel(str[i - 1]) && isVowel(str[i])){
            return false;
        }
        if(!isVowel(str[i - 2]) && !isVowel(str[i - 1]) && !isVowel(str[i])){
            return false;
        }
    }

    return true;
}

bool thirdCondition(string str){
    int len = str.length();

    for(int i = 1; i < len; i++){
        if(str[i] == 'e' || str[i] == 'o') continue;
        if(str[i - 1] == str[i]) return false;
    }

    return true;
}

int main(){
    while(1){
        string s;
        cin >> s;

        if(s == "end") break;

        if(firstCondition(s) && secondCondition(s) && thirdCondition(s))
            cout << '<' << s << "> is acceptable.\n";
        else cout << '<' << s << "> is not acceptable.\n";
    }

    return 0;
}