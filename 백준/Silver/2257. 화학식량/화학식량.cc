#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;

int getWeight(char c){
    if(c == 'H'){
        return 1;
    }
    else if(c == 'C'){
        return 12;
    }
    else if(c == 'O'){
        return 16;
    }

    return 0;
}

int bracket(){
    int answer = 0, digit = 1;
    bool usedDigit = true;

    while(1){
        char c = s.top();
        s.pop();

        if(c == '(') {
            return answer;
        }
        else if(c == ')'){
            if(!usedDigit){
                answer += (bracket() * digit);
                usedDigit = true;
            }
            else answer += bracket();
        }
        else if(isdigit(c)){
            digit = c - '0';
            usedDigit = false;
        }
        else{
            if(!usedDigit){
                answer += (getWeight(c) * digit);
                usedDigit = true;
            }
            else answer += getWeight(c);
        }
    }

    return 0;
}

int main(){
    string formula;
    cin >> formula;

    for(int i = 0; i < formula.length(); i++){
        s.push(formula[i]);
    }

    int answer = 0, digit = 1;
    bool usedDigit = true;
    while(!s.empty()){
        char c = s.top();
        s.pop();

        if(c == ')') {
            if(!usedDigit){
                answer += (bracket() * digit);
                usedDigit = true;
            }
            else answer += bracket();
        }
        else if(isdigit(c)){
            digit = c - '0';
            usedDigit = false;
        }
        else{
            if(!usedDigit){
                answer += (getWeight(c) * digit);
                usedDigit = true;
            }
            else answer += getWeight(c);
        }
    }

    cout << answer;

    return 0;
}