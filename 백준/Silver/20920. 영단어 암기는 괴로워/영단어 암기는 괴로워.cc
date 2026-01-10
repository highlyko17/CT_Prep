#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> words;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;

        if(temp.length() < M) continue;

        words[temp]++;
    }

    vector<pair<int, pair<int, string>>> orders;
    for(auto w: words){
        string word = w.first;
        int cnt = w.second;
        int len = word.length();

        orders.push_back({-cnt, {-len, word}});
    }

    sort(orders.begin(), orders.end());

    for(int i = 0; i < orders.size(); i++){
        cout << orders[i].second.second << '\n';
    }

    return 0;
}