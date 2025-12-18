class Solution
{
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        int n = prices.size();

        vector<long long> ogpfx(1, 0), pospfx(1, 0);

        for(int i = 0; i < n; i++)
        {
            ogpfx.push_back(prices[i]);
            pospfx.push_back(prices[i]);

            ogpfx[i + 1] *= strategy[i];

            ogpfx[i + 1] += ogpfx[i];
            pospfx[i + 1] += pospfx[i];
        }

        // for(auto e : ogpfx) cout << e << " "; cout << endl;
        // for(auto e : pospfx) cout << e << " "; cout << endl;

        long long res = ogpfx.back();

        // [0 -> lo - 1] -> ogpfx
        // [lo -> mid]   -> skip
        // [mid -> hi]   -> pospfx
        // [hi -> end]   -> ogpfx

        int lo = 0;
        int mid = (k / 2) - 1;  // position of the lastZero
        int hi = k - 1;

        while(hi < n)
        {
            // cout << lo << " " << mid << " " << hi << endl;

            long long curres = 0;

            curres = ogpfx[lo];

            curres += (pospfx[hi + 1] - pospfx[mid + 1]);

            curres += ogpfx.back() - ogpfx[hi + 1];

            // cout << curres << endl;

            res = max(res, curres);

            lo++, mid++, hi++;
        }

        return res;
    }
};