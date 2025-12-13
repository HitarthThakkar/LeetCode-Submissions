class Solution {
public:

    vector<int> sieve(int n) {
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;
        for(int i = 2; i * i <= n; i++) {
            if(prime[i] == 1) {
                for(int j = i * i; j <= n; j += i) prime[j] = 0;
            }
        }
        return prime;
    }
    
    int largestPrime(int n) {
        if(n < 2) return 0;
        vector<int> prime = sieve(n);
        vector<int> primes;
        for(int i = 0; i <= n; i++) if(prime[i]) primes.push_back(i);

        long long sum = 0;
        int lpns = 0;
        int i = 0;

        while(sum < n) {
            sum += primes[i];
            if(sum <= n && prime[sum]) lpns = sum;
            i++;
        }
        
        return lpns;
    }
};