#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> nums(n + 1, true);
    
    for(int i = 2; i <= n; i++){
        if(nums[i]){
            for(int j = 2; j * i <= n; j++){
                nums[j * i] = false;
            }
            answer++;
        }
    }
    
    return answer;
}