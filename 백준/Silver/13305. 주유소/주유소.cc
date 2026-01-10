#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> dist(N - 1);
    vector<long long> price(N);
    for(int i = 0; i < N - 1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < N; i++){
        cin >> price[i];
    }

    long long minPrice = price[0];
    long long answer = 0;
    for(int i = 0; i < N - 1; i++){
        if(price[i] <= minPrice){
            minPrice = price[i];
        }

        answer += (minPrice * dist[i]);
    }

    cout << answer;

    return 0;
}