class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        int l = 0, r = 0, trash = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(l != r) {                    
                    reverse(s.begin() + l, s.begin() + r); s[r++] = ' ';
                    l = r;
                }
                else trash++;
            }
            else s[r++] = s[i];
        }
        reverse(s.begin() + l, s.begin() + r);
        while(trash--) s.pop_back();
        while(s.back() == ' ') s.pop_back();
        return s;
    }
};