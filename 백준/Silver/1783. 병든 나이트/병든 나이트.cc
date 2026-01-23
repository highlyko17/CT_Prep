#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    if(N == 1 || M == 1){
        cout << 1;
        return 0;
    }

    if(N == 2 && M == 2){
        cout << 1;
        return 0;
    }

    if(M == 2){
        cout << 2;
        return 0;
    }

    if(N == 2){
        cout << min(4, (M + 1) / 2); 
        return 0;
    }

    if(M >= 7){
        cout << M - 2;
        return 0;
    }

    cout << min(4, M);

    return 0;
}