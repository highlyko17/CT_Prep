#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isProper(string s){
    stack<int> st;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push(s[i]);
        if(s[i] == ')') {
            if(!st.empty()) 
                st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

string remove(string p){
    p.erase(p.begin());
    p.erase(p.end() - 1);
    
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') p[i] = ')';
        else if(p[i] == ')') p[i] = '(';
    }
    
    return p;
}

string convert(string p){
    if(p == "") return p;
    
    int open = 0, close = 0, idx = 0;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') open++;
        else if(p[i] == ')') close++;
            
        if(open == close){
            idx = i + 1;
            break;
        }
    }
    
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    
    string result = "";
    
    if(isProper(u)){
        result = u + convert(v);
    }
    else{
        result = "(" + convert(v) + ")" + remove(u);
    }
    
    return result;
}

string solution(string p) {
    string answer = "";
    
    answer = convert(p);
    return answer;
}