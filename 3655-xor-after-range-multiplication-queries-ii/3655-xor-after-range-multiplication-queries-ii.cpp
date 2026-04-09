class Solution
{
public:

    int m = 1e9 + 7;

    int powermod(int a, int b)
    {
        int res = 1;
        if(a == 0) return 0;

        while(b)
        {
            if(b & 1) res = (res * 1LL * a) % m;
            b >>= 1;
            a = (a * 1LL * a) % m;
        }

        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));  // SQRD

        unordered_map<int, vector<vector<int>>> smallKMap;

        for(auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            if(k >= blockSize)
            {
                for(int i = l; i <= r; i += k) nums[i] = (nums[i] * 1LL * v) % m;
            }
            else
            {
                smallKMap[k].push_back(query);
            }
        }

        for(auto &[k, allQueries] : smallKMap)
        {
            vector<long long> diff(n, 1);

            for(auto &query : allQueries)
            {
                int l = query[0];
                int r = query[1];
                int v = query[3];

                diff[l] = (diff[l] * 1LL * v) % m;

                int t = ((r - l) / k) + 1;
                int R = (t * k) + l;

                if(R < n) diff[R] = (diff[R] * 1LL * powermod(v, m - 2)) % m;
            }

            for(int i = 0; i < n; i++)
            {
                if(i - k >= 0)
                {
                    diff[i] = (diff[i] * 1LL * diff[i - k]) % m;
                }
            }

            for(int i = 0; i < n; i++)
            {
                nums[i] = (nums[i] * 1LL * diff[i]) % m;
            }
        }

        int result = 0;
        for(int &num : nums) result ^= num;
        return result;
    }
};