#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    stack<char> st;
    int answer = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else answer++;
        }
    }

    while(!st.empty()){
        st.pop();
        answer++;
    }

    cout << answer;
    
    return 0;
}