class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> m;
        vector<int> v, pfx, sfx;
        for(auto c : word) m[c]++;
        for(auto e : m) v.push_back(e.second);
        int n = v.size();
        sort(v.begin(), v.end());
        pfx = v; sfx = v;
        for(int i = 1; i < n; i++) pfx[i] += pfx[i - 1];
        for(int i = n - 2; i >= 0; i--) sfx[i] += sfx[i + 1];
        // for(auto e : v) cout <<e << " "; cout << endl;
        // for(auto e : pfx) cout <<e << " "; cout << endl;
        // for(auto e : sfx) cout <<e << " "; cout << endl;
        int res = 1e9;
        for(int i = 0; i < n; i++)
        {
            int sp = v[i];
            int ep = v[i] + k;
            // cout << sp << " " << ep << endl;
            int spfi = lower_bound(v.begin(), v.end(), sp) - v.begin();
            int epni = upper_bound(v.begin(), v.end(), ep) - v.begin();
            // cout << spfi << " " << epni << endl;
            int ops = 0;
            if(spfi > 0) ops += pfx[spfi - 1];
            if(epni < n) ops += sfx[epni] - ((n - epni) * ep);
            // cout << ops << endl;
            res = min(res, ops);
        }
        return res;
    }
};