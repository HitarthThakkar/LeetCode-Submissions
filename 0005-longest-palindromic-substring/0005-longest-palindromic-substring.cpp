class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int msp = 0; int mexLen = 0;
        for(int mid = 0; mid < n; mid++) {
            int x = 0;
            for(x = 0; mid + x < n && mid - x >= 0; x++)
                if(s[mid - x] != s[mid + x]) break;
            int sp = mid - x + 1; int len = (2 * x - 1);
            if(len > mexLen) { mexLen = len; msp = sp; }
        }
        for(int mid = 0; mid < n; mid++) {
            int x = 0;
            for(x = 0; mid - x >= 0 && mid + x + 1 < n; x++)
                if(s[mid - x] != s[mid + x + 1]) break;
            int sp = mid - x + 1; int len = (2 * x);
            if(len > mexLen) { mexLen = len; msp = sp; }
        }
        return s.substr(msp, mexLen);
    }
};