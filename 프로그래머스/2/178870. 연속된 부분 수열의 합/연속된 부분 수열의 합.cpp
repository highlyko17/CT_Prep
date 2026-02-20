#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    
    int start = 0;
    long long sum = 0;
    
    int ans_start = 0;
    int ans_end = n - 1;
    
    for(int end = 0; end < n; end++){
        sum += sequence[end];
        
        while(sum > k){
            sum -= sequence[start];
            start++;
        }
        
        if(sum == k){
            if((end - start) < (ans_end - ans_start)){
                ans_end = end;
                ans_start = start;
            }
        }
    }
    
    return {ans_start, ans_end};
}