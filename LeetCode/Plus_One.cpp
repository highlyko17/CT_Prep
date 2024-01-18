class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        vector<int> num;
        num.push_back(1);

        for(int i = 0; i < digits.size(); i++)
            num.push_back(digits[i]);

        return num;
    }
};