class Solution {
public:
    bool checkRecord(string s) {
        int absence = 0, consecutive = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                absence++;
            }
            else if(s[i] == 'L'){
                ++consecutive;
                if(consecutive == 3){
                    if(s[i-1] == 'L' && s[i-2] == 'L')
                        return false;
                    else {
                        consecutive = 1;
                        for(int j = 1; j <= 2; j++){
                            if(s[i-j] == 'L')
                                consecutive++;
                        }
                    }
                }
            }
        }

        if(absence < 2) return true;
        return false;
    }
};