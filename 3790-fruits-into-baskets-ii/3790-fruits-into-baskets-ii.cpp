class Solution
{
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int n = fruits.size();
        int ans = 0;
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            bool found = false;
            for(int j = 0; j < n; j++)
            {
                if(s.find(j) == s.end() && baskets[j] >= fruits[i])
                {
                    found = true;
                    s.insert(j);
                    break;
                }
            }
            if(!found) ans++;
        }
        return ans;
    }
};