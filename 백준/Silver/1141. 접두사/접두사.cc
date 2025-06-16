#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = n;

    vector<string> v;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        v.push_back(str);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int len = v[i].length();
        for(int j = i + 1; j < n; j++){
            if(v[i] == v[j].substr(0, len)){
                ans -= 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}