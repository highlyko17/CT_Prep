#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int cnt[10001] = {0};
    
    int left = 0;
    int right = 0;
    
    for(int i = 0; i < topping.size(); i++){
        int idx = topping[i];
        
        if(cnt[idx] == 0) right++;
        
        cnt[idx]++;
    }
    
    bool visited[10001] = {false};
    
    for(int i = 0; i < topping.size(); i++){
        int idx = topping[i];
        
        if(!visited[idx]){
            left++;
            visited[idx] = true;
        }
        
        cnt[idx]--;
        
        if(cnt[idx] == 0) right--;
        
        if(left == right) answer++;
    }
    
    return answer;
}