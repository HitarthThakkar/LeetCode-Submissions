class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<pair<int, pair<int, int>>> vp;
        for(int i = 0; i < n; i++)
            {
                vp.push_back({technique2[i] - technique1[i], {technique1[i], technique2[i]}});
            }
        sort(vp.begin(), vp.end());
        // for(auto e : vp) cout << e.first << " " << e.second.first << " " << e.second.second << endl;
        long long res = 0;
        for(auto e : vp)
            {
                if(k > 0)
                {
                    res += e.second.first;
                    k--;
                }
                else
                {
                    if(e.first > 0) res += e.second.second;
                    else res += e.second.first;
                }
            }
        return res;
    }
};