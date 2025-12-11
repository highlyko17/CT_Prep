#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;

long long srch(long long len, vector<long long>& lines){
    long long cnt = 0;
    
    for(int i = 0; i < K; i++){
        cnt += (lines[i] / len);
    }
    
    return cnt;
}

int main(){
    cin >> K >> N;
    
    vector<long long> lines(K);
    long long maxVal = 0;
    
    for(int i = 0; i < K; i++){
        cin >> lines[i];
        maxVal = max(maxVal, lines[i]);
    }

    long long left = 1;
    long long right = maxVal;
    long long answer = 0;
    
    while(left <= right){
        long long mid = (left + right) / 2;
        long long cnt = srch(mid, lines);
        
        if(cnt >= N){
            answer = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}