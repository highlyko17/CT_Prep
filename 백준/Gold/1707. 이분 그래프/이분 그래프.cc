#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int K;
    cin >> K;

    for(int z = 0; z < K; z++){
        int V, E;
        cin >> V >> E;

        vector<vector<int> > v(V);
        vector<int> board(V, -1);

        for(int i = 0; i < E; i++){
            int u, e;
            cin >> u >> e;

            v[u - 1].push_back(e - 1);
            v[e - 1].push_back(u - 1);
        }

        bool isBipartite = true;

        for(int i = 0; i < V; i++){
            if(board[i] == -1){
                queue<pair<int, bool> > q;
                board[i] = 0;
                q.push({i, 0});

                while(!q.empty() && isBipartite){
                    int idx = q.front().first;
                    bool curr = q.front().second;
                    q.pop();

                    for(int j = 0; j < v[idx].size(); j++){
                        int nxt = v[idx][j];

                        if(board[nxt] == -1){
                            board[nxt] = !curr;
                            q.push({nxt, !curr});
                        }
                        else if(board[nxt] == board[idx]){
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }

        if (isBipartite) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}