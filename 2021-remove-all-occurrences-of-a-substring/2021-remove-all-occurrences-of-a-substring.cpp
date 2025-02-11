class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int p = part.length();
        string temp = "";
        while(true) {
            bool change = false;
            for(int i = 0; i < s.length(); i++) {
                if(i + p <= s.length() && s.substr(i, p) == part)
                {
                    change = true;
                    temp += s.substr(0, i); temp += s.substr(i + p, s.length() - i - p);
                    s = temp; temp = "";
                    break;
                }
            }
            if(!change) return s;
        }
    }
};