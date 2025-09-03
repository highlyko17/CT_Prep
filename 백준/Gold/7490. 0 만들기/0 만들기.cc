#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> answer;

void dfs(int num, string expr){
    if(num > N){
        string temp = "";
        for(int i = 0; i < expr.length(); i++){
            if(expr[i] != ' ') temp += expr[i];
        }

        int result = 0;
        char op = '+';
        for(int i = 0; i < temp.length(); i++){
            if(isdigit(temp[i])){
                int val = 0;
                while(i < temp.length() && isdigit(temp[i])){
                    val = (val * 10) + (temp[i] - '0');
                    i++;
                }
                i--;

                if(op == '+') result += val;
                else result -= val;
            }
            else{
                op = temp[i];
            }
        }

        if(result == 0){
            answer.push_back(expr);
        }
        return;
    }

    dfs(num + 1, expr + " " + to_string(num));
    dfs(num + 1, expr + "+" + to_string(num));
    dfs(num + 1, expr + "-" + to_string(num));
}

int main(){
    int test_num;
    cin >> test_num;

    while(test_num--){
        cin >> N;

        dfs(2, "1");

        sort(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << "\n";
        }
        cout << "\n";

        answer.clear();
    }

}