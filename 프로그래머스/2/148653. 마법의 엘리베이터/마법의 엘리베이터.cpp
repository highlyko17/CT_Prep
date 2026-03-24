#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int d = storey % 10;
        storey /= 10;
        
        if(d < 5){
            answer += d;
        }
        else if(d > 5){
            answer += (10 - d);
            storey++;
        }
        else{
            if(storey % 10 >= 5){
                answer += 5;
                storey++;
            }
            else{
                answer += 5;
            }
        }
    }
    
    return answer;
}