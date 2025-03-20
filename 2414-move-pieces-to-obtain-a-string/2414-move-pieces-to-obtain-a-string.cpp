class Solution
{
public:
    bool canChange(string start, string target)
    {
        string signature;
        for(auto ch : start) if(ch != '_') signature += ch;
        int i = 0;
        for(auto ch : target)
            if(ch != '_') if(ch != signature[i++]) return false;
        if(i < signature.length()) return false;
        int l = 0, r = 0;
        for(int i = 0; i < start.length(); i++)
        {
            if(start[i] == 'L') l--;
            if(target[i] == 'L') l++;
            if(start[i] == 'R') r++;
            if(target[i] == 'R') r--;
            if(l < 0 || r < 0) return false;
        }
        return true;
    }
};