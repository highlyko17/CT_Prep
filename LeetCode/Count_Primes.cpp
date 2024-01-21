class Solution {
public:
    int countPrimes(int n) {
        int count = 0;

        if(n <= 2)
            return 0;

        bool primes[n];

        for(int i = 2; i < n; i++){
            primes[i] = true;
        }

        for(int i = 2; i <= sqrt(n); i++){
            if(primes[i]){
                for(int j = i + i; j < n; j += i)
                    primes[j] = false;
            }
        }

        for(int i = 2; i < n; i++){
            if(primes[i]) count++;
        }

        return count;
    }
};