class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        if(num % 2 == 0){
            for(double i = 2; i <= num / 2; i += 2){
                if(i * i == num) return true;
            }
        }
        else {
            for(double i = 1; i <= num / 2; i += 2){
                if(i * i == num) return true;
            }
        }
        return false;
    }
};