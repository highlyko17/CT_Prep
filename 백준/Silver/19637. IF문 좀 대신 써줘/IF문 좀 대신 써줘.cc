#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<pair<int, string>> level(N);
    for(int i = 0; i < N; i++){
        cin >> level[i].second >> level[i].first;
    }

    for(int i = 0; i < M; i++){
        int num;
        cin >> num;

        int left = 0, right = N - 1, result = 0;

        while(left <= right){
            int mid = (left + right) / 2;

            if(level[mid].first >= num){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        cout << level[result].second << '\n';
    }
    
    return 0;
}