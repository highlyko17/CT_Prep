#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[101];
bool visited[101], finished[101];
vector<int> result;

void dfs(int x, vector<int> &path){
    visited[x] = true;
    path.push_back(x);

    int next = arr[x];
    if(!visited[next]){
        dfs(next, path);
    }
    else if(!finished[x]){
        auto it = find(path.begin(), path.end(), next);
        
        while(it != path.end()){
            result.push_back(*it);
            it++;
        }
    }

    finished[x] = true;
    path.pop_back();
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            vector<int> path;
            dfs(i, path);
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}