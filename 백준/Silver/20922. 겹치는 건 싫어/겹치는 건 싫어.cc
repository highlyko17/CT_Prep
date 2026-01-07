#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    map<int, int> cnt;
    int left = 0, right = 0, diff = 0;

    while(right < N){
        cnt[nums[right]]++;

        while(cnt[nums[right]] > K){
            cnt[nums[left]]--;
            left++;
        }
        
        diff = max(diff, right - left + 1);
        right++;
    }

    cout << diff;

    return 0;
}