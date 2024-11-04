class Solution
{
public:
    string compressedString(string word)
    {
        string ans = "";
        int i = 0, n = word.length();
        for(int j = 1; j < n; j++)
        {
            while(j < n && word[j] == word[j - 1]) j++;
            int len = j - i;
            while(len > 9) len -= 9, ans += '9', ans += word[i];
            ans += (char)(len + 48); ans += word[i];
            i = j;
        }
        if(i == n - 1) ans += '1', ans += word[i];
        return ans;
    }
};