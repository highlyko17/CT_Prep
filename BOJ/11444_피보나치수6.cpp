#include <iostream>

using namespace std;

long long fib[1000000000000000000] = {0};

int main(){
    int n;
    cin >> n;

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n];

    return 0;
}