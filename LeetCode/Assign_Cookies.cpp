class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty() || g.empty()) return 0;

        int count = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i = 0; i < s.size(); i++){
            if(g[j] <= s[i]){
                count++;
                j++;
            }

            if(j >= g.size()) break;
        }
        
        return count;
    }
};