#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool used[9];

void dfs(int depth, int idx){
    if(depth == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        return ;
    }

    for(int i = idx; i <= N; i++){
        if(!used[i]){
            used[i] = true;
            arr[depth] = i;
            dfs(depth + 1, i + 1);
            used[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;

    dfs(0, 1);

    return 0;
}