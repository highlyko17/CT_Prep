#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = n - 1;
    int p = n - 1;
    
    while(true){
        
        while(d >= 0 && deliveries[d] == 0){
            d--;
        }
        
        while(p >= 0 && pickups[p] == 0){
            p--;
        }
        
        if(d < 0 && p < 0) break;
        
        int farthest = max(d, p);

        answer += (long long)(farthest + 1) * 2;
        
        int remain = cap;
        
        while(d >= 0 && remain > 0){
            int cnt = min(remain, deliveries[d]);
            
            deliveries[d] -= cnt;
            remain -= cnt;
            
            if(deliveries[d] == 0) d--;
        }
        
        remain = cap;
        
        while(p >= 0 && remain > 0){
            int cnt = min(remain, pickups[p]);
            
            pickups[p] -= cnt;
            remain -= cnt;
            
            if(pickups[p] == 0) p--;
        }
    }
    
    return answer;
}