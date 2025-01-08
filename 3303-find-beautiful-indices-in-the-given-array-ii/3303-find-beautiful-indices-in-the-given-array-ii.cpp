class Solution
{
private:
    vector<int> gimmelps(string s)
    {
        int n = s.length(), j = 0; vector<int> lps(n, 0);
        for(int i = 1; i < n; i++) {
            while(j > 0 && s[j] != s[i]) j = lps[j - 1];
            if(s[j] == s[i]) lps[i] = ++j;
        }
        return lps;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        string as = a + '#' + s; string bs = b + '#' + s;
        vector<int> aa, bb, ans;
        vector<int> lpss = gimmelps(as);
        for(int i = a.length(); i < as.length(); i++)
            if(lpss[i] == a.length()) aa.push_back(i - (2 * a.length()));
        lpss = gimmelps(bs);
        for(int i = b.length(); i < bs.length(); i++)
            if(lpss[i] == b.length()) bb.push_back(i - (2 * b.length()));

        for(auto ele : aa)
        {
            int ind = lower_bound(bb.begin(), bb.end(), ele) - bb.begin();
            if(ind != bb.size() && abs(ele - bb[ind]) <= k) { ans.push_back(ele); continue; }
            if(ind != 0 && abs(ele - bb[ind - 1]) <= k) ans.push_back(ele);
        }
        return ans;
    }
};