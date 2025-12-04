#include <iostream>
#include <vector>

using namespace std;

int n, teamCount;
vector<int> students;
vector<bool> visited;
vector<bool> finished;

void dfs(int num){
    visited[num] = true;
    int next = students[num];

    if(!visited[next]) dfs(next);
    else if(!finished[next]){
        teamCount++;

        for(int i = next; i != num; i = students[i]){
            teamCount++;
        }
    }

    finished[num] = true;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cin >> n;

        students = vector<int>(n + 1);
        visited = vector<bool>(n + 1, false);
        finished = vector<bool>(n + 1, false);
        teamCount = 0;

        for(int i = 1; i <= n; i++){
            cin >> students[i];
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]) dfs(i);
        }

        cout << (n - teamCount) << endl;
    }

    return 0;
}