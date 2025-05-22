#define pai pair<int, int>
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        for(auto e : nums) mp[e]++;
        priority_queue<pai, vector<pai>, greater<pai>> pq;
        while(k--)
        {
            pq.push({mp.begin()->second, mp.begin()->first});
            mp.erase(mp.begin());
        }
        while(!mp.empty())
        {
            if(pq.top().first < mp.begin()->second)
            {
                pq.pop();
                pq.push({mp.begin()->second, mp.begin()->first});
            }
            mp.erase(mp.begin());
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};