#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> running(24, 0);
    
    for(int i = 0; i < 24; i++){
        int need = players[i] / m;
        
        if(running[i] < need){
            int add = need - running[i];
            answer += add;
            
            for(int t = i; t < i + k && t < 24; t++){
                running[t] += add;
            }
        }
    }
    
    return answer;
}