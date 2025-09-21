#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> buildings(N);
    for(int i = 0; i < N; i++){
        cin >> buildings[i];
    }

    vector<int> cnt(N, 0);
    vector<int> nearest(N, 0);
    stack<pair<int, int> > s;

    for(int i = 0; i < N; i++){
        while(!s.empty() && s.top().first <= buildings[i]) s.pop();
        if(!s.empty()){
            cnt[i] += s.size();
            int currIdx = i + 1;
            int nextIdx = s.top().second + 1;
            if(nearest[i] == 0) nearest[i] = nextIdx;
            else{
                int savedLen = abs(currIdx - nearest[i]);
                int nextLen = abs(currIdx - nextIdx);
                if(savedLen > nextLen) nearest[i] = nextIdx;
                else if(savedLen == nextLen) nearest[i] = min(nextIdx, nearest[i]);
            }
        }
        s.push({buildings[i], i});
    }

    while(!s.empty()) s.pop();

    for(int i = N - 1; i >= 0; i--){
        while(!s.empty() && s.top().first <= buildings[i]) s.pop();
        if(!s.empty()){
            cnt[i] += s.size();
            int currIdx = i + 1;
            int nextIdx = s.top().second + 1;
            if(nearest[i] == 0) nearest[i] = nextIdx;
            else{
                int savedLen = abs(currIdx - nearest[i]);
                int nextLen = abs(currIdx - nextIdx);
                if(savedLen > nextLen) nearest[i] = nextIdx;
                else if(savedLen == nextLen) nearest[i] = min(nextIdx, nearest[i]);
            }
        }
        s.push({buildings[i], i});
    }

    for(int i = 0; i < N; i++){
        cout << cnt[i];
        if(cnt[i] > 0) cout << ' ' << nearest[i];
        cout << '\n';
    }

    return 0;
}