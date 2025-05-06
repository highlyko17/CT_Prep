#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N;
    cin >> M;

    vector<vector<pair<int, int> > > lines(N + 1);
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        lines[a].push_back({b, c});
    }

    int start, dest;
    cin >> start;
    cin >> dest;

    //queue 사용해서
    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q;
    q.push({0, start});
    dist[start] = 0;

    while(!q.empty()){
        int price = q.top().first;
        int curr_city = q.top().second;
        q.pop();

        if(price > dist[curr_city]) continue;

        for(int i = 0; i < lines[curr_city].size(); i++){
            int nextCity = lines[curr_city][i].first;
            int nextPrice = price + lines[curr_city][i].second; // 현재 도시까지 누적 값 + 다음 도시 값

            if(nextPrice < dist[nextCity]){
                dist[nextCity] = nextPrice;
                q.push({nextPrice, nextCity});
            }
        }   
    }

    cout << dist[dest];
    return 0;
}