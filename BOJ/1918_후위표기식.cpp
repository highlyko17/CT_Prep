#include <iostream>
#include <stack>

using namespace std;

int main(){
    string s;
    cin >> s;

    stack<char> ss;
    for(int i = 0; i < s.length(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            cout << s[i];
        }
        else{
            if(s[i] == '(') ss.push(s[i]);
            else if(s[i] == ')'){
                while(!ss.empty() && ss.top() != '('){
                    cout << ss.top();
                    ss.pop();
                }
                if(!ss.empty() && ss.top() == '('){
                    ss.pop();
                }
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!ss.empty() && (ss.top() == '*' || ss.top() == '/')){
                    cout << ss.top();
                    ss.pop();
                }
                ss.push(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!ss.empty() && ss.top() != '('){
                    cout << ss.top();
                    ss.pop();
                }
                ss.push(s[i]);
            }
        }
    }

    while(!ss.empty()){
        cout << ss.top();
        ss.pop();
    }
    return 0;
}