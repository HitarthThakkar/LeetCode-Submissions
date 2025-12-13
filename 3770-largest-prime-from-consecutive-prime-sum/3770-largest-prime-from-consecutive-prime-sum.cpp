class Solution {
public:

    int CONST = 5 * 100000;

    vector<int> prime = vector<int>(CONST, 1);

    void sieve()
    {
        prime[0] = prime[1] = 0;
        for(int i = 2; i * i < CONST; i++)
        {
            if(prime[i] == 1)
            {
                for(int j = i * i; j < CONST; j += i) prime[j] = 0;
            }
        }
    }
    
    int largestPrime(int n) {
        sieve();
        vector<int> primes;
        for(int i = 0; i < CONST; i++) if(prime[i]) primes.push_back(i);

        long long sum = 0;
        int lpns = 0;
        int i = 0;

        while(sum < n)
        {
            // cout << primes[i] << " " << sum << " " << lpns << endl;
            sum += primes[i];
            if(sum <= n && sum < CONST && prime[sum]) lpns = sum;
            i++;
        }
        
        return lpns;
    }
};