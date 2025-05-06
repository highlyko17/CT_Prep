#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool used[9];

void dfs(int depth, int it){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        return ;
    }

    for(int i = it; i <= N; i++){
        arr[depth] = i;
        dfs(depth + 1, i);
    }
}

int main(){
    cin >> N >> M;

    dfs(0, 1);

    return 0;
}