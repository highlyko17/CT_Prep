#include <string>
#include <vector>
#include <queue>

using namespace std;

long long getSum(vector<int> sequence){
    long long sum = 0;
    
    for(int i = 0; i < sequence.size(); i++){
        sum += sequence[i];
    }
    
    return sum;
}

int solution(vector<int> queue1, vector<int> queue2) {
    long long firstSum = 0, secondSum = 0, targetSum = 0;
    
    firstSum = getSum(queue1);
    secondSum = getSum(queue2);
    targetSum = (firstSum + secondSum) / 2;
    
    int cnt = 0;
    
    if ((firstSum + secondSum) % 2 != 0) return -1;
    
    queue<int> q1;
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
    }
    
    queue<int> q2;
    for(int i = 0; i < queue2.size(); i++){
        q2.push(queue2[i]);
    }
    
    while(cnt <= (queue1.size() + queue2.size()) * 2){
        if(firstSum == secondSum){
            return cnt;
            break;
        }
        else if(firstSum < secondSum){
            cnt++;
            
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
            
            firstSum += temp;
            secondSum -= temp;
        }
        else{
            cnt++;
            
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
            
            firstSum -= temp;
            secondSum += temp;
        }
    }
    
    return -1;
}