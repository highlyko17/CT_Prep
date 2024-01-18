class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> befRow;
        
        for(int i = 0; i < numRows; i++){
            vector<int> currRow(i + 1, 1);

            for(int j = 1; j < i; j++){
                currRow[j] = befRow[j - 1] + befRow[j];
            }

            ans.push_back(currRow);
            befRow = currRow;
        }

        return ans;
    }
};