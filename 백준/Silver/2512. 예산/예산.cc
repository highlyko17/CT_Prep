#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, totalBud;

int main(){
    cin >> N;

    int maxBud = 0, sum = 0;
    vector<int> bud(N);

    for(int i = 0; i < N; i++){
        cin >> bud[i];
        sum += bud[i];
        maxBud = max(maxBud, bud[i]);
    }

    cin >> totalBud;

    if(totalBud >= sum){
        cout << maxBud;
        return 0;
    }

    int minBud = 0;
    int answer = 0;
    
    while(minBud <= maxBud){ 
        int midBud = (minBud + maxBud) / 2;

        int currSum = 0;
        for(int i = 0; i < N; i++){
            currSum += min(bud[i], midBud);
        }

        if(currSum <= totalBud){
            answer = midBud;
            minBud = midBud + 1;
        }
        else{
            maxBud = midBud - 1; 
        }
    }

    cout << answer;

    return 0;
}