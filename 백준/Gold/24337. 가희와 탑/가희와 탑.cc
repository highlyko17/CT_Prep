#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long N;
    int a, b;
    cin >> N >> a >> b;

    if((long long)a + (long long)b - 1 > N) {
        cout << -1;
        return 0;
    }

    int t = max(a, b);
    vector<int> h;
    for(int i = 1; i <= a - 1; i++) h.push_back(i);
    h.push_back(t);
    for(int i = b - 1; i >= 1; i--) h.push_back(i);

    long long k = (long long)h.size();
    long long m = N - k;
    vector<int> ans;

    if(a == 1){
        ans.push_back(h[0]);
        for(int i = 0; i < m; i++) ans.push_back(1);
        for(int i = 1; i < h.size(); i++) ans.push_back(h[i]);
    }
    else{
        for(int i = 0; i < m; i++) ans.push_back(1);
        for(int i = 0; i < h.size(); i++) ans.push_back(h[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }

    return 0;
}