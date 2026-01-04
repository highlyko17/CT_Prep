#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T;

int main(){
    cin >> T;

    while(T--){
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        int scores[101][101] = {0};
        int orders[101] = {0};
        int cnt[101] = {0};

        for(int i = 0; i < m; i++){
            int team_id, questions_id, score;
            cin >> team_id >> questions_id >> score;

            scores[team_id][questions_id] = max(scores[team_id][questions_id], score);
            orders[team_id] = i;
            cnt[team_id]++;
        }

        vector<pair<int, pair<int, pair<int, int>>>> ranks;
        for(int i = 1; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= k; j++){
                sum += scores[i][j];
            }

            ranks.push_back({sum, {-cnt[i], {-orders[i], i}}});
        }

        sort(ranks.rbegin(), ranks.rend());

        for(int i = 0; i < n; i++){
            if(ranks[i].second.second.second == t){
                cout << i + 1 << endl;
            }
        }
    }

    return 0;
}