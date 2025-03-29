class Solution
{
public:
    bool canChange(string start, string target)
    {
        // 2025 Hiring Prep Sprint Week_2 Q8
        string signature; int i = 0;
        for(auto ch : start) if(ch != '_') signature += ch;
        for(auto ch : target) if(ch != '_') if(ch != signature[i++]) return false;
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