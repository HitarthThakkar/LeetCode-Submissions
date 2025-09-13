class Solution
{
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxFreqSum(string s)
    {
        map<char, int> m;
        for(auto c : s) m[c]++;
        int mv = 0, mc = 0;
        for(auto e : m) {
            if(isVowel(e.first)) mv = max(mv, e.second);
            else mc = max(mc, e.second);
        }
        return mc + mv;
    }
};