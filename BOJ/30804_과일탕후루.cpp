#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    int cnt[10] = {0, }, types = 0, answer = 0;
    queue<int> q;
    while(N--){
        int fruit;
        cin >> fruit;

        q.push(fruit);

        if(cnt[fruit]++ == 0){
            ++types;
        }

        while(types > 2){
            int curr = q.front();
            q.pop();

            if(--cnt[curr] == 0){
                --types;
            }
        }

        int s = q.size();
        answer = max(answer, s);
    }

    cout << answer;

    return 0;
}