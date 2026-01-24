#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int sushi[30001];
bool check[3001];

int main(){
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++){
        cin >> sushi[i];
    }

    int maxCnt = 0;

    for(int i = 0; i < N; i++){
        int flag = 0, coupon = 1;

        for(int j = i; j < i + k; j++){
            if(!check[sushi[j % N]]) check[sushi[j % N]] = true;
            else flag++;
        }

        if(check[c]) coupon = 0;
        maxCnt = max(maxCnt, k - flag + coupon);
        memset(check, false, sizeof(check));
    }

    cout << maxCnt;

    return 0;
}