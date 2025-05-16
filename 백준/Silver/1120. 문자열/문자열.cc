#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;

    int aLen = A.length();
    int bLen = B.length();
    int min_diff = 50;

    for(int i = 0; i <= bLen - aLen; i++){
        int diff = 0;
        for(int j = 0; j < aLen; j++){
            if(A[j] != B[i + j]){
                diff++;
            }
        }

        min_diff = min(min_diff, diff);
    }

    cout << min_diff;

    return 0;
}