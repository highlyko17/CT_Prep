#include <iostream>
#include <string>
#include <vector>  
using namespace std;

int N, K, P, X, ans = 0;

string to_k_digits(int X){
    string s(K, '0');
    for(int i = K - 1; i >= 0; i--){
        s[i] = (X % 10) + '0';
        X /= 10;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(!(cin >> N >> K >> P >> X)) return 0;

    int seg[10] = {
        0b1111110, //0
        0b0110000, //1
        0b1101101, //2
        0b1111001, //3
        0b0110011, //4
        0b1011011, //5
        0b1011111, //6
        0b1110000, //7
        0b1111111, //8
        0b1111011  //9
    };

    string sx = to_k_digits(X);
    vector<int> dx(K);
    for(int i = 0; i < K; i++){
        dx[i] = sx[i] - '0';
    }

    for(int num = 1; num <= N; num++){
        if(num == X) continue;

        string snum = to_k_digits(num);
        int flips = 0;
        for(int i = 0; i < K; i++){
            int d1 = dx[i];
            int d2 = snum[i] - '0';

            int diff = seg[d1] ^ seg[d2];
            flips += __builtin_popcount(diff);
            if(flips > P) break;
        }
        if(flips >= 1 && flips <= P) ans++;
    }

    cout << ans << "\n";
    return 0;
}