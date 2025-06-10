class Solution
{
public:
    long long powermod(long long x, long long y, long long p)
    {
        long long res = 1; x = x % p;
        if (x == 0) return 0;
        while (y > 0) { if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p; }
        return res;
    }
    int superPow(int a, vector<int>& b)
    {
        /*
            Luv Cpp
            2 ways
            
            1) non math implementation
                what is issue in applying powermod ?
                powermod is fully efficient for any value of b.
                the issue is b is not a number.
                powermod method requires to divide b by 2.
                we cannot divide array by 2 like number.
                we have to implement a method to divide array by 2
                and also check if b is zero.
                if we can do it powermod will work
                note that powermod was NOT the bottleneck
                bottleneck was that we have to implement things.

            2) math
                etf EULER TOTIENT FUNCTION
                a^b mod m is same as [ a^( b % phi(m) ) ] % m
                m = 1337 in our case
                phi(m) = m - 1 [if m is prime]
                1337 is NOT prime.
                we have to use formula to find phi(m)
                phi(1337) = 1140
                if we can do b mod 1140 then b would be at max 1139
                and then we can apply powermod easily.

            your choice

            implement array dividing by 2
                        OR
            implement array mod 1140
        */

        // Method 2 : MAth

        int newb = 0;   // b mod 1140

        // (a + b) % m = (a%m + b%m)
        // array can be represented as sum of numbers easily
        // eg. 127 => (100 + 20 + 7)

        for(auto val : b)
        {
            newb = (newb * 10 + val) % 1140;
        }

        return powermod(a, (newb == 0 ? 1140 : newb), 1337);
    }
};