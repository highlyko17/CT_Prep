#include <iostream>
#include <stack>

using namespace std;

int main(){
    int idx = 1;

    while(1){
        string str;
        int answer = 0;
        stack<char> s;

        cin >> str;

        if(str.size() != 0 && str[0] == '-') break;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '{'){
                s.push('{');
            }
            else{
                if(!s.empty()) s.pop();
                else{
                    answer++;
                    s.push('{');
                }
            }
        }
        if(s.empty())
            cout << idx++ << ". " << answer << '\n';
        else {
            answer += s.size() / 2;
            cout << idx++ << ". " << answer << '\n';
        }
    }

    return 0;
}