class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> smallestRanges;

        if(nums.size() == 0)
            return smallestRanges;
        if(nums.size() == 1){
            smallestRanges.push_back(to_string(nums[0]));
            return smallestRanges;
        }

        int start = nums[0];
        for(int i = 0; i < nums.size() - 1; i++){
            if (nums[i + 1] == nums[i] + 1) continue;
            if (start == nums[i]) {
                smallestRanges.push_back(to_string(start));
            } else {
                string range = to_string(start) + "->" + to_string(nums[i]);
                smallestRanges.push_back(range);
            }
            start = nums[i + 1];
        }

        if (start == nums.back()) {
            smallestRanges.push_back(to_string(start));
        } else {
            string range = to_string(start) + "->" + to_string(nums.back());
            smallestRanges.push_back(range);
        }

        return smallestRanges;
    }
};