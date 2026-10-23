#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int n = diffs.size();
    
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    int answer = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        long long total_time = times[0];
        
        for (int i = 1; i < n; i++) {
            if (diffs[i] <= mid) {
                total_time += times[i];
            } 
            else {
                long long wrong = diffs[i] - mid;
                total_time += (times[i] + times[i - 1]) * wrong + times[i];
            }
            
            if (total_time > limit) break;
        }
        
        if (total_time <= limit) {
            answer = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}