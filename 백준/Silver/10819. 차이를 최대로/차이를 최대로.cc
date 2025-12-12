#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int maxSum = 0;

    do{
        int sum = 0;

        for(int i = 0; i < N - 1; i++){
            sum += abs(nums[i] - nums[i + 1]);
        }

        maxSum = max(maxSum, sum);

    }while(next_permutation(nums.begin(), nums.end()));

    cout << maxSum;

    return 0;
}