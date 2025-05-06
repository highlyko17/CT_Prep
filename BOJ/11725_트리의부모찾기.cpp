#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<vector<int> > nodes(N + 1);
    vector<int> answer(N + 1);
    vector<bool> visited(N + 1, false);
    
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    vector<int> s;
    visited[1] = true;
    s.push_back(1);

    while(!s.empty()){
        int curr = s.back();
        s.pop_back();

        for(int i = 0; i < nodes[curr].size(); i++){
            int next = nodes[curr][i];
            if(!visited[next]){
                visited[next] = true;
                answer[next] = curr;
                s.push_back(next);
            }
        }
    }

    for(int i = 2; i <= N; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}