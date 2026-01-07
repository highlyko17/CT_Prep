#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, D;
    cin >> N >> D;
    
    vector<pair<int, int>> shortcuts[10001];
    
    for(int i = 0; i < N; i++){
        int start, dest, len;
        cin >> start >> dest >> len;
        if(dest <= D) { 
            shortcuts[start].push_back({dest, len});
        }
    }
    
    vector<int> dist(D + 1);
    for(int i = 0; i <= D; i++){
        dist[i] = i; 
    }
    
    for(int i = 0; i <= D; i++){
        if(i > 0) {
            dist[i] = min(dist[i], dist[i-1] + 1);
        }
        
        for(auto& shortcut : shortcuts[i]){
            int dest = shortcut.first;
            int len = shortcut.second;
            dist[dest] = min(dist[dest], dist[i] + len);
        }
    }
    
    cout << dist[D] << endl;
    
    return 0;
}