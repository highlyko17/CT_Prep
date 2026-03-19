#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int toMin(string str){    
    int t = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    
    return (t * 60) + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> times;
    
    for(int i = 0; i < book_time.size(); i++){
        int start_min = toMin(book_time[i][0]);
        int end_min = toMin(book_time[i][1]) + 10;
        
        times.push_back({start_min, end_min});
    }
    
    sort(times.begin(), times.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < times.size(); i++){
        int start = times[i].first;
        int end = times[i].second;
        
        if(!pq.empty() && pq.top() <= start){
            pq.pop();
        }
        
        pq.push(end);
    }
    
    return pq.size();
}