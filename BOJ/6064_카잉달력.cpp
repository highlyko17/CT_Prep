#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int calc(int M, int N, int x, int y){
    int lim = lcm(M, N);
    for(int a = x; a <= lim; a += M){
        if((a - y) % N == 0){
            return a;
        }
    }

    return -1;
}

int main(){
    int T;
    cin >> T;

    int M, N, x, y;
    vector<int> answer(T);
    for(int i = 0; i < T; i++){
        cin >> M >> N >> x >> y;
        answer[i] = calc(M, N, x, y);
    }

    for(int i = 0; i < T; i++){
        cout << answer[i] << endl;
    }

    return 0;
}