class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        
        long start = 1;
        long end = x;
        long mid;

        while(start <= end){
            mid = (start + end) / 2;

            if((mid * mid <= x) && (x < (mid + 1) * (mid + 1)))
                return mid;
            else if(mid * mid < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};