class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<bool> possible(n, true);
        map<int, int> mp;
        for(auto pair : trust) possible[pair[0] - 1] = false;
        for(int i = 0; i < n; i++) if(possible[i] == true) mp[i + 1] = n - 1;
        for(auto pair : trust)
        {
            mp[pair[1]]--;
            if(mp[pair[1]] == 0) return pair[1];
        }
        for(auto ele : mp) if(ele.second == 0) return ele.first;
        return -1;
    }
};