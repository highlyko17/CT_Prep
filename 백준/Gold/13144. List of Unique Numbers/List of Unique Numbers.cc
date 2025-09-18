#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    vector<bool> visited(100001, false);
    int start = 0;
    long long ans = 0;
    for(int end = 0; end < N; end++){
        while(visited[v[end]]){
            visited[v[start]] = false;
            start++;
        }
        visited[v[end]] = true;

        ans += (long long)(end - start + 1);
    }

    cout << ans;

    return 0;
}