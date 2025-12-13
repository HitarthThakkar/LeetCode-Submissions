class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        // 0 3 6 7
        // 0 3 9 16

        // for i = 0, the final score must remain >= 4
        // -0 -3 -6 -7
        // -0 only choice so add 1 to answer

        // for i = 1, the final score must remain >= 2
        // -6 -9 

        int n = damage.size();

        vector<int> pfx(n + 1, 0);
        for(int i = 0; i < n; i++) pfx[i + 1] = pfx[i] + damage[i];

        long long int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int hi = i;
            int lo = 0;
            int res = i + 1;

            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;

                int sum = pfx[i + 1] - pfx[mid];

                if(hp - sum >= requirement[i]) { res = mid; hi = mid - 1; }
                else lo = mid + 1;
            }

            if(res <= i) ans += (i - res + 1);
        }

        return ans;
    }
};