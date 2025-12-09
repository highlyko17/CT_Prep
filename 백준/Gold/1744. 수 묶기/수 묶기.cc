#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    int ones = 0, zeros = 0;
    vector<int> pos, neg;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        if(temp > 1) pos.push_back(temp);
        else if(temp == 1) ones++;
        else if(temp == 0) zeros++;
        else neg.push_back(temp);
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    int answer = 0;

    for(int i = 0; i < pos.size(); i += 2){
        if(i + 1 < pos.size()){
            answer += pos[i] * pos[i + 1];
        }
        else answer += pos[i];
    }

    for(int i = 0; i < neg.size(); i += 2){
        if(i + 1 < neg.size()){
            answer += neg[i] * neg[i + 1];
        }
        else{
            if(zeros > 0){
    
            } else {
                answer += neg[i];
            }
        }
    }

    answer += ones;

    cout << answer;
    
    return 0;
}