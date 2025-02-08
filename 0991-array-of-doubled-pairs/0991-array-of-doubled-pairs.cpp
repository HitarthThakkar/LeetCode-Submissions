class Solution
{
public:
    bool canReorderDoubled(vector<int>& arr)
    {
        int n = arr.size();
        n /= 2;
        multiset<int> s(arr.begin(), arr.end());

        while(n--)
        {
            auto it = s.begin();
            int val = *it;

            if(val > 0)
            {
                if(s.find(2 * val) == s.end())
                {
                    return false;
                }
                else
                {
                    auto itr = s.find(2 * val);
                    s.erase(itr);
                    s.erase(it);
                }
            }
            else if(val < 0)
            {
                if(val & 1) return false;

                if(s.find((val / 2)) == s.end())
                {
                    return false;
                }
                else
                {
                    auto itr = s.find((val / 2));
                    s.erase(itr);
                    s.erase(it);
                }
            }
            else
            {
                s.erase(it);
                if(*(s.begin()) == 0)
                {
                    s.erase(s.begin());
                }
                else
                {
                    return false;
                }
            }
        }

        return (s.size() == 0);
    }
};