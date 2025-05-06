#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, int> > meetings;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;

        meetings.push_back({b, a}); // 끝나는 시간, 시작하는 시간
    }

    sort(meetings.begin(), meetings.end());

    int curr_time = meetings[0].first;
    int answer = 1;
    for(int i = 1; i < N; i++){
        int start_time = meetings[i].second;
        int end_time = meetings[i].first;
        if(start_time >= curr_time){
            answer++;
            curr_time = end_time;
        }
    }

    cout << answer;

    return 0;
}