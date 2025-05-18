#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    string nums[11] = {"zero" ,"one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine"};
    cin >> M >> N;

    vector<pair<string, int>> ans;
    for(int i = M; i <= N; i++){
        string s;
        if(i >= 10){
            s = nums[i / 10] + " " + nums[i % 10];
            ans.push_back({s, i});
        }
        else{
            s = nums[i];
            ans.push_back({s, i});
        }
    }

    sort(ans.begin(), ans.end());

    for(int i = 1; i <= ans.size(); i++){
        cout << ans[i - 1].second << ' ';
        if(i % 10 == 0) cout << '\n';
    }

    return 0;
}