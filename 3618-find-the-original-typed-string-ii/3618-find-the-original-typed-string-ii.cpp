class Solution
{
public:
    int M = 1e9 + 7;

    int possibleStringCount(string word, int k)
    {
        // pure recursion was 711 / 846 testcases passed
        // recursion + memo was 829 / 846 testcases passed
        // iterative dp was 833 / 846 testcases passed

        // now we need to speed up the third inner for loop somehow
        // in third loop, we are essentially doing this : 
        // dp[i][count] = dp[i + 1][count + 1] + dp[i + 1][count + 2]
        //                      + .... + dp[i + 1][count + take] where count + take must be < k.
        // if we have prefix sum of dp[i + 1], it might help doing this in O(1) and thus problem solved.

        if(k > word.length())
        {
            return 0;
        }

        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++)
        {
            if(word[i] == word[i - 1])
            {
                count++;
            }
            else
            {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long int p = 1;
        for(int &f: freq)
        {
            p = (p * f) % M;
        }

        if(freq.size() >= k)
        {
            return p;
        }

        // find invalid and subtract from p [but iteratively].

        int n = freq.size();

        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

        // base case
        for(int count = k - 1; count >= 0; count--)
        {
            dp[n][count] = 1;
        }

        // everything same as iterative upto this point.

        for(int i = n - 1; i >= 0; i--)
        {

            vector<int> pfx(k + 1, 0);  // 1 based

            for(int h = 1; h <= k; h++)
            {
                pfx[h] = (pfx[h - 1] + dp[i + 1][h - 1]) % M; // think, make table urself
            }

            for(int count = k - 1; count >= 0; count--)
            {
                int l = count + 1;
                int r = count + freq[i];

                if(r + 1 > k)
                {
                    r = k - 1;  // last time's break condition equivalent
                }


                if(l <= r)
                {
                    dp[i][count] = (pfx[r + 1] - pfx[l] + M) % M;
                }
            }
        }

        return ((p - dp[0][0] + M) % M);
    }
};