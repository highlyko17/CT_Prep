#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> a;
    vector<string> b;
    
    for(int i = 0; i < str1.length() - 1; i++){
        string temp = "";
        char first = str1[i];
        char second = str1[i + 1];
        
        if(!isalpha(first) || !isalpha(second)) continue;
        
        temp += tolower(first);
        temp += tolower(second);
        
        a.push_back(temp);
    }
    
    for(int i = 0; i < str2.length() - 1; i++){
        string temp = "";
        char first = str2[i];
        char second = str2[i + 1];
        
        if(!isalpha(first) || !isalpha(second)) continue;
        
        temp += tolower(first);
        temp += tolower(second);
        
        b.push_back(temp);
    }
    
    int up = 0;
    int down = a.size() + b.size();
    
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                up++;
                b.erase(b.begin() + j);
                break;
            }
        }
    }
    
    if(a.size() == 0 && b.size() == 0) answer = 65536;
    else answer = up * 65536 / (down - up);
    cout << up << down;
    return answer;
}