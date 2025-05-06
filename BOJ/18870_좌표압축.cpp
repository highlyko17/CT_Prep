#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> origin(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        origin[i] = arr[i];
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i < N; i++){
        auto idx = lower_bound(arr.begin(), arr.end(), origin[i]) - arr.begin();
        cout << idx << ' ';
    }

    return 0;
}