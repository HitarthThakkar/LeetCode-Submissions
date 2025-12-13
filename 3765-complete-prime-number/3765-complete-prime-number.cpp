class Solution {
public:

    bool isPrime(long long int n)
    {
        if(n == 1) return false;
        for(int i = 2; i < n; i++)
            {
                if(n % i == 0) return false;
            }
        return true;
    }
    
    bool completePrime(int num) {
        long long int n = 0;
        long long int numcp = num;
        long long int mul = 1;
        while(numcp)
        {
            n += (numcp % 10) * mul;
            numcp /= 10; mul *= 10;
            // isPrime(n);
            if(!isPrime(n)) return false;
        }
        string nn = to_string(num);
        reverse(nn.begin(), nn.end());
        n = 0, numcp = stoi(nn), mul = 1;

        while(numcp)
        {
            n *= 10;
            n += (numcp % 10);
            numcp /= 10;
            // isPrime(n);
            if(!isPrime(n)) return false;
        }

        return true;
    }
};