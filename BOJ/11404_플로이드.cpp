#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > cities(n + 1, vector<int>(n + 1, 1e9));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        cities[a][b] = min(cities[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        cities[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(cities[i][k] != 1e9 && cities[k][j] != 1e9){
                    cities[i][j] = min(cities[i][j], cities[i][k] + cities[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cities[i][j] == 1e9){
                cout << 0 << ' ';
            }
            else{
                cout << cities[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}