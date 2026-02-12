#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> liq(N);
    for(int i = 0; i < N; i++){
        cin >> liq[i];
    }

    sort(liq.begin(), liq.end());

    int left = 0, right = N - 1;
    long long min_diff = 2000000000;
    long long ans_left = liq[left], ans_right = liq[right];

    while(left < right){
        long long sum = liq[left] + liq[right];
        long long diff = abs(sum);

        if(diff < min_diff){
            min_diff = diff;
            ans_left = liq[left];
            ans_right = liq[right];
        }

        if(sum < 0){
            left++;
        }
        else if(sum > 0){
            right--;
        }
        else break;
    }

    cout << ans_left << ' ' << ans_right;

    return 0;
}