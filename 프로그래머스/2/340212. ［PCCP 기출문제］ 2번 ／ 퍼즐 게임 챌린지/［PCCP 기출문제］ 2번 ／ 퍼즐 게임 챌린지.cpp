#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int puzzle = diffs.size();
    
    int min_diff = 1;
    int max_diff = *max_element(diffs.begin(), diffs.end());
    
    int answer = max_diff;
    
    while(min_diff <= max_diff){
        long long curr_time = times[0];
        int mid_diff = (min_diff + max_diff) / 2;
         
        for(int i = 1; i < puzzle; i++){
            if(diffs[i] <= mid_diff){
                curr_time += times[i];
            }
            else{
                long long wrong = diffs[i] - mid_diff;
                curr_time += times[i] + ((times[i] + times[i - 1]) * wrong);
            }
            
            if(curr_time > limit) break;
        }
        
        if(curr_time <= limit){
            answer = mid_diff;
            max_diff = mid_diff - 1;
        }
        else{
            min_diff = mid_diff + 1;
        }
    }
    
    return answer;
}