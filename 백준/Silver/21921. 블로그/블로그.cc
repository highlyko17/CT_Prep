#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> visitors(N);
    for(int i = 0; i < N; i++){
        cin >> visitors[i];
    }

    int first = 0, second = first + X - 1, sum = 0, maxSum = -1, pairs = 1;
    for(int i = first; i <= second; i++){
        sum += visitors[i];
    }

    while(second < N){
        if(sum == maxSum){
            pairs++;
        }
        else if(sum > maxSum){
            maxSum = sum;
            pairs = 1;
        }

        sum -= visitors[first];
        first++; second++;
        sum += visitors[second];
    }

    if(maxSum == 0){
        cout << "SAD";
        return 0;
    }
    cout << maxSum << '\n' << pairs;

    return 0;
}