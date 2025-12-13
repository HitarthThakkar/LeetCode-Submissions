class Solution {
public:

    bool isPali(int n)
    {
        string s = "";
        while(n)
            {
                if(n & 1) s += "1";
                else s += "0";
                n /= 2;
            }
        string rev = s;
        reverse(rev.begin(), rev.end());
        return (s == rev);
    }
    
    vector<int> minOperations(vector<int>& nums) {
        set<int> s;
        for(int i = 1; i < 5040; i++)
            {
                if(isPali(i))
                {
                    s.insert(i);
                }
            }

        vector<int> res;
        for(auto e : nums)
            {
                auto it = s.lower_bound(e);
                int op1 = 1e9, op2 = 1e9;
                if(it != s.end()) op1 = *it;
                if(it != s.begin()) {it--, op2 = *it;}
                int r1 = abs(op1 - e);
                int r2 = abs(op2 - e);
                res.push_back(min(r1, r2));
            }
        return res;
    }
};