class Solution
{
public:
    int numSteps(string s)
    {
        int ops = 0;
        while(!s.empty())
        {
            if(s.back() == '0') {
                s.pop_back();
                ops++;
            }
            else {
                if(s.size() == 1) return ops;

                while(s.size() > 0 && s.back() != '0') {
                    s.pop_back();
                    ops++;
                }
                ops++;
                if(s.size() == 0) return ops;
                else {
                    s.back() = '1';
                }
            }
        }
        return ops;
    }
};