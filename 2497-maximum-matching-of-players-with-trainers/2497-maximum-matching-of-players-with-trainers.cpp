class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        multiset<int> ms;
        for(auto ele : trainers) ms.insert(ele);
        for(auto ele : players)
        {
            auto it = ms.lower_bound(ele);
            if(it != ms.end())
            {
                ans++;
                ms.erase(it);
            }
        }
        return ans;
    }
};