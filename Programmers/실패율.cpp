#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float> user(N, 0);
    vector<float> failure(N, 0);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] >= i+1) user[i]++;
            if(stages[j] == i+1) failure[i]++;
        }
        if (user[i] != 0) {
            failure[i] = failure[i] / user[i];
        } else {
            failure[i] = 0;
        }
    }
    
    for(int i = 0; i < N; i++){
        int idx = max_element(failure.begin(), failure.end()) - failure.begin();
        failure[idx] = -1;
        answer.push_back(idx+1);
    }
    
    return answer;
}