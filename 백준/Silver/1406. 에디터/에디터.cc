#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;

    int M;
    cin >> M;

    stack<char> left, right;
    for(int i = 0; i < str.length(); i++){
        left.push(str[i]);
    }

    for(int i = 0; i < M; i++){
        char c;
        cin >> c;

        if(c == 'P'){
            char cc;
            cin >> cc;

            left.push(cc);
        }
        else if(c == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(c == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if(c == 'B'){
            if(!left.empty()){
                left.pop();
            }
        }
    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    return 0;
}