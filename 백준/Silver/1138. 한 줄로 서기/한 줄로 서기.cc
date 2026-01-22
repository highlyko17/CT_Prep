#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    vector<int> answer(N, 0);
    for(int i = 0; i < N; i++){
        int cnt = 0;
        
        for(int j = 0; j < N; j++){
            if(answer[j] == 0){
                if(cnt == nums[i]){
                    answer[j] = i + 1;
                    break;
                }
                cnt++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << ' ';
    }

    return 0;
}