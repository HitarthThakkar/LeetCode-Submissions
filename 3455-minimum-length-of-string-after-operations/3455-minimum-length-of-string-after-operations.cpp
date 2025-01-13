class Solution
{
public:
    int minimumLength(string s)
    {
        int came = 0;
        int freq = 0;
        for(auto ele : s)
        {
            came |= (1 << (ele - 'a'));
            freq ^= (1 << (ele - 'a'));
        }
        came = __builtin_popcount(came);
        freq = __builtin_popcount(freq);
        return ((came * 2) - freq);
    }
};