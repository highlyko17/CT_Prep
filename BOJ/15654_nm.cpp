#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int answer[9];
bool used[9];

void dfs(int depth, int arr[]){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << answer[i] << ' ';
        }
        cout << "\n";
        return ;
    }

    for(int i = 0; i < N; i++){
        if(!used[i]){
            used[i] = true;
            answer[depth] = arr[i];
            dfs(depth + 1, arr);
            used[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;

    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    dfs(0, arr);

    return 0;
}