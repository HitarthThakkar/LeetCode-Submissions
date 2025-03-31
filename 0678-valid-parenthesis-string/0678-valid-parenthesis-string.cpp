class Solution
{
public:
    bool checkValidString(string s)
    {
        vector<int> l, st;
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(') l.push_back(i);
            else if(ch == '*') st.push_back(i);
            else
            {
                if(l.size() > 0) l.pop_back();
                else if(st.size() > 0) st.pop_back();
                else return false;
            }
        }
        if(l.size() > st.size()) return false;
        while(l.size() > 0)
        {
            if(l.back() < st.back())
            {
                l.pop_back();
                st.pop_back();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};