#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> dist(N - 1);
    vector<int> price(N);
    for(int i = 0; i < N - 1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < N; i++){
        cin >> price[i];
    }

    int minPrice = price[0], answer = 0;
    for(int i = 0; i < N - 1; i++){
        if(price[i] <= minPrice){
            minPrice = price[i];
        }

        answer += (minPrice * dist[i]);
    }

    cout << answer;

    return 0;
}