#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, answer = 0;
    cin >> N;

    vector<int> buildings(N);
    for(int i = 0; i < N; i++){
        cin >> buildings[i];
    }

    vector<int> cnt(N, 0);
    for(int i = 0; i < N; i++){
        double maxVal = -10000000000;
        for(int j = i + 1; j < N; j++){
            int x = j - i;
            int y = buildings[j] - buildings[i];
            double grad = y * 1.0 / x;

            if(grad <= maxVal){
                continue;
            }

            maxVal = grad;
            cnt[i]++;
            cnt[j]++;
        }
    }

    cout << *max_element(cnt.begin(), cnt.end());

    return 0;
}