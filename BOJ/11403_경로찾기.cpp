#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int dist[101][101] = {0,};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
        }
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] && dist[k][j]){
                    dist[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}