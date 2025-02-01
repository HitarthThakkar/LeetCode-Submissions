class Solution {
public:
    string findValidPair(string s) {
        map<char,int>mp;
        for(auto ele : s) mp[ele]++;
        for(int i=0;i<s.length()-1;i++)
            {
                if(s[i] != s[i+1])
                {
                    int one = (int)s[i] - 48;
                    int two = (int)s[i + 1] - 48;

                    if(one == mp[s[i]] && two == mp[s[i+1]])
                    {
                        string ans;
                        ans += s[i];
                        ans += s[i+1];
                        return ans;
                    }
                    
                }
            }
        return "";
    }
};