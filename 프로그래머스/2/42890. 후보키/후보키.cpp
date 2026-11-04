#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int tuple = relation.size();
    int attribute = relation[0].size();
    
    vector<int> candidates;
    
    for(int mask = 1; mask < (1 << attribute); mask++){
        bool minimal = true;
        
        for(int i = 0; i < candidates.size(); i++){
            if((candidates[i] & mask) == candidates[i]){
                minimal = false;
                break;
            }
        }
        
        if(!minimal) continue;
        
        set<vector<string>> s;
        
        for(int i = 0; i < tuple; i++){
            vector<string> str;
            
            for(int j = 0; j < attribute; j++){
                if(mask & (1 << j)){
                    str.push_back(relation[i][j]);
                }
            }
            
            s.insert(str);
        }
        
        if(s.size() == tuple){
            candidates.push_back(mask);
        }
        
    }
    
    return candidates.size();
}