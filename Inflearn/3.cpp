#include <iostream>

using namespace std;

int main(){
    int N, sum = 0;

    cin >> N;

    for(int i = 1; i < N; i++){
        if(N % i == 0){
            if(i != 1) cout << " + ";
            sum += i;
            cout << i;
        }
    }
    cout << " = " << sum;

    return 0;
}