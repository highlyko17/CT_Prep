#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;

    vector<int> temp;
    string num = "";

    // 1. 문자열 파싱
    for (int i = 1; i < s.size() - 1; i++) {
        if(isdigit(s[i])){
            num += s[i];
        }
        else if(s[i] == ','){
            if(!num.empty()){
                temp.push_back(stoi(num));
                num = "";
            }
        }
        else if(s[i] == '}'){
            if(!num.empty()){
                temp.push_back(stoi(num));
                num = "";
            }
            
            v.push_back(temp);
            temp.clear();
        }
    }

    // 2. 집합 크기순 정렬
    sort(v.begin(), v.end(), cmp);
    
    bool visited[100001] = {false};
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            int num = v[i][j];
            
            if(!visited[num]){
                answer.push_back(num);
                visited[num] = true;
            }
        }
    }

    return answer;
}