class Solution
{
public:
    bool checkValidString(string s)
    {
        int lb = 0, star = 0;
        for(auto ch : s)
        {
            if(ch == '(') lb++;
            else if(ch == '*') star++;
            else
            {
                if(lb > 0) lb--;
                else if(star > 0) star--;
                else return false;
            }
        }
        if(lb == 0 && star == 0) return true;
        if(star == 0) return false;
        if(lb == 0) return true;
        if(lb > star) return false;
        // lb == star || star > lb


        vector<int> l, st;

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(') l.push_back(i); // // // // // // 
            else if(ch == '*') st.push_back(i);
            else
            {
                if(l.size() > 0) l.pop_back();
                else if(st.size() > 0) st.pop_back();
                else return false;
            }
        }

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