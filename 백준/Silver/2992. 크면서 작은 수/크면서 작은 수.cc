#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string X;
    cin >> X;

    int start = stoi(X);
    int minNum = 999999;
    sort(X.begin(), X.end());

    do {
        int num = stoi(X);
        
        if(num > start){
            minNum = min(minNum, num);
        }
    } while (next_permutation(X.begin(), X.end()));

    if(minNum == 999999) cout << 0;
    else cout << minNum;

    return 0;
}