#include <iostream>

using namespace std;

int N;
int answer = 0;
int arr[15] = {0};

bool check(int q){
    for(int i = 0; i < q; i++){
        if(arr[i] == arr[q] || abs(i - q) == abs(arr[i] - arr[q]))
            return false;
    }
    return true;
}

void nQueen(int q){
    if(q == N){
        answer++;
        return;
    }

    for(int i = 0; i < N; i++){
        arr[q] = i;
        if(check(q)){
            nQueen(q + 1);
        }
    }
}

int main(){
    cin >> N;

    nQueen(0);
    cout << answer;
    return 0;
}