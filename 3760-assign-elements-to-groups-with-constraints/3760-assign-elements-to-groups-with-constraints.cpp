class Solution
{
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements)
    {
        map<int, int> mp;
        int i = 0;
        for(auto ele : elements)
        {
            if(mp.find(ele) != mp.end()) mp[ele] = min(mp[ele], i);
            else mp[ele] = i;
            i++;
        }

        map<int, int> m;
        vector<int> answer;

        for(auto num : groups)
        {
            if(m.find(num) != m.end())
            {
                answer.push_back(m[num]);
            }
            else
            {
                int ans = 1e9;

                for(int i = 1; (i * i) <= num; i++)
                {
                    if(num % i == 0)
                    {
                        int one = i;
                        int two = (num / i);

                        if(mp.find(one) != mp.end())
                        {
                            ans = min(ans, mp[one]);
                        }
                        if(mp.find(two) != mp.end())
                        {
                            ans = min(ans, mp[two]);
                        }
                    }
                }

                ans = (ans == 1e9 ? -1 : ans);

                answer.push_back(ans);
                m[num] = ans;
            }
        }

        return answer;
    }
};