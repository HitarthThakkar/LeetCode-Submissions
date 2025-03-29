class Solution
{
private:
    bool f(string s, int ignoredIndex) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(l == ignoredIndex) { l++; continue; }
            if(r == ignoredIndex) { r--; continue; }
            if(s[l++] != s[r--]) return false;
        } return true;
    }
public:
    bool validPalindrome(string s)
    {
        if(s.length() < 3) return true;
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l] != s[r]) return (f(s, l) || f(s, r)); l++; r--;
        } return true;
    }
};