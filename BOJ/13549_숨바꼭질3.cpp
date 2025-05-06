#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    if(N == K){
        cout << 0;
        return 0;
    }

    bool visited[100001] = {false, };
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, N});
    visited[N] = true;

    while(!pq.empty()){
        int sec = pq.top().first;
        int location = pq.top().second;
        pq.pop();

        if(location == K){
            cout << sec;
            return 0;
        }

        int num = location * 2;
        if(num >= 0 && num <= 100000 && !visited[num]){
            pq.push({sec, num});
            visited[num] = true;
        }
        for(auto x : {location + 1, location - 1}){
            if(x >= 0 && x <= 100000 && !visited[x]){
                pq.push({sec + 1, x});
                visited[x] = true;
            }
        }
    }

    return 0;
}