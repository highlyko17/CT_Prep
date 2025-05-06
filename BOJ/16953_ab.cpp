#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    long long a, b;  // int → long long 변경
    cin >> a >> b;

    if(a == b){
        cout << 1;
        return 0;
    }

    queue<pair<long long, int>> q;  // int → long long 변경
    q.push({a, 1});  // 초기값 1 (연산 횟수 포함)

    while(!q.empty()){
        long long num = q.front().first;
        int count = q.front().second;
        q.pop();

        for(long long next : {num * 2, num * 10 + 1}){  // int → long long 변경
            if(next == b){
                cout << count + 1;  // 연산 횟수 + 1
                return 0;
            }
            if(next <= b){
                q.push({next, count + 1});
            }
        }
    }

    cout << -1;
    return 0;
}
