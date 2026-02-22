#include<vector>
#include<queue>

using namespace std;



int solution(vector<vector<int> > maps)
{
    int n = maps.size(); int m = maps[0].size();
    
    int dn[4] = {1, -1, 0, 0};
    int dm[4] = {0, 0, 1, -1};
    
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    
    while(!q.empty()){
        int dist = q.front().first;
        int cn = q.front().second.first;
        int cm = q.front().second.second;
        q.pop();
        
        if(cn == n - 1 && cm == m - 1){
            return dist;
        }
        
        for(int i = 0; i < 4; i++){
            int nn = cn + dn[i];
            int nm = cm + dm[i];
            
            if(nn < 0 || nm < 0 || nn >= n || nm >= m || !maps[nn][nm]) continue;
            
            q.push({dist + 1, {nn, nm}});
            maps[nn][nm] = 0;
        }
    }  
    
    return -1;
}