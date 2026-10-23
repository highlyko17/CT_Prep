#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    for(int a = 1; a <= n - 4; a++){
        for(int b = a + 1; b <= n - 3; b++){
            for(int c = b + 1; c <= n - 2; c++){
                for(int d = c + 1; d <= n - 1; d++){
                    for(int e = d + 1; e <= n; e++){
                        vector<int> code = {a, b, c, d, e};
                        bool flag = true;
                        
                        for(int i = 0; i < q.size(); i++){
                            int cnt = 0;
                            
                            for(int x : code){
                                for(int y : q[i]){
                                    if(x == y) cnt++;
                                }
                            }
                            
                            if(cnt != ans[i]){
                                flag = false;
                                break;
                            }
                        }
                        
                        if(flag) answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}