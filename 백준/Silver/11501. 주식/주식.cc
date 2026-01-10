#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> stocks(N);
        for(int i = 0; i < N; i++){
            cin >> stocks[i];
        }

        int maxStock = stocks[N - 1];
        long long sum = 0;
        for(int i = N - 1; i >= 0; i--){
            if(maxStock <= stocks[i]){
                maxStock = stocks[i];
            }
            else{
                sum += (maxStock - stocks[i]);
            }
        }

        cout << sum << '\n';
    }

    return 0;
}