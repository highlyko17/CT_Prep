#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    long long S;
    cin >> N >> S;

    vector<long long> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    int minLen = N + 1;
    int start = 0;
    long long sum = 0;

    for(int end = 0; end < N; end++){
        sum += v[end];

        while(sum >= S){
            minLen = min(minLen, end - start + 1);
            sum -= v[start++];
        }
    }

    if(minLen == N + 1) cout << 0;
    else cout << minLen;

    return 0;
}