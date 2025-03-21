class Solution
{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        vector<string> ans;
        int n = recipes.size();
        vector<int> gval(n);
        for(int i = 0; i < n; i++) gval[i] = ingredients[i].size();
        map<string, vector<int>> mp;
        for(int i = 0; i < n; i++)
            for(auto ing : ingredients[i])
                mp[ing].push_back(i);
        queue<string> q;
        for(auto e : supplies) q.push(e);
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            for(auto gp : mp[cur])
            {
                gval[gp]--;
                if(gval[gp] == 0)
                {
                    q.push(recipes[gp]);
                    ans.push_back(recipes[gp]);
                }
            }
        }
        return ans;
    }
};