class Solution
{
public:
    char kthCharacter(long long k, vector<int>& operations)
    {
        int overhead = 0;

        while(k > 1)
        {
            long long power = 0;
            while(pow(2, power) < k) power++;
            int j = power - 1;

            long long int msb = 1LL << (63 - __builtin_clzll(k));

            if(operations[j] == 1)
            {
                // remove the first set bit and overhead++
                if(k - msb == 0) k /= 2;
                else k -= msb;
                overhead++;
            }
            else
            {
                // remove first set bit no overhead
                if(k - msb == 0) k /= 2;
                else k -= msb;
            }

            j--;
        }

        overhead %= 26;
        return ((char) 'a' + overhead);
    }
};