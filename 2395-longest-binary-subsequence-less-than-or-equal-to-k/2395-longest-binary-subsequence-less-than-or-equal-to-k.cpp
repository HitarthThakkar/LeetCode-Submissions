class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        vector<int> zi, oi;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') zi.push_back(i);
            else oi.push_back(i);
        }
        // for(auto e : zi) cout << e << " "; cout << endl;
        reverse(oi.begin(), oi.end());
        // for(auto e : oi) cout << e << " "; cout << endl;
        int minLen = zi.size();
        // cout << "Atleast " << minLen << endl;
        long long int value = 0;
        for(int i = 0; i < oi.size(); i++)
        {
            long long behind = lower_bound(zi.begin(), zi.end(), oi[i]) - zi.begin();
            // cout << "index " << behind << endl;
            behind = (zi.size() - behind) * 1LL;
            // cout << "#" << behind << endl;
            if(behind + i >= 30) return minLen;
            value += pow(2, behind + i);
            // cout << "@" << value << endl;
            if(value <= k) minLen++;
            else return minLen;
        }
        return minLen;
    }
};