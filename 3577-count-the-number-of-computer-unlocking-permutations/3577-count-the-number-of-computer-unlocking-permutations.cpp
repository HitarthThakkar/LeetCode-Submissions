class Solution
{
public:
    int countPermutations(vector<int>& complexity)
    {
        int root = complexity[0];
        for(int i = 1; i < complexity.size(); i++)
        {
            if(complexity[i] <= root) return 0;
        }

        int res = 1;
        int till = complexity.size() - 1;
        int mod = 1e9 + 7;

        for(int i = 2; i <= till; i++)
        {
            res = ((((res * 1LL) % mod) * 1LL * ((i * 1LL) % mod)) % mod);
        }

        return res;
    }
};