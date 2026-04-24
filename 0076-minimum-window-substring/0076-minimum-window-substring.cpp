class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        unordered_map<char,int> ft;
        for(const char &c : t) ft[c]++;
        int count = ft.size();                  // count of distinct characters we need

        int l = 0;
        int resInd = -1, resLen = 1e9;

        for(int r = 0; r < n; r++) {
            if(ft.find(s[r]) != ft.end()) {
                ft[s[r]]--;
                if(ft[s[r]] == 0) count--;      // Our need of this character is now fulfilled.
            }

            while(count == 0) {
                if(r - l + 1 < resLen) {
                    resInd = l;
                    resLen = (r - l + 1);
                }

                if(ft.find(s[l]) != ft.end() ) {
                    ft[s[l]]++;
                    if(ft[s[l]] > 0) count++;
                }

                l++;
            }
        }

        return (resInd == -1 ? "" : s.substr(resInd, resLen));
    }
};