class Solution
{
private:
    string topoSort(int n, vector<vector<int>> &adj, set<char> &valid)
    {
        // 2025 Hiring Prep Sprint Q6 [Very Good Medium]
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
            if(valid.find('A' + i) != valid.end())
                for (auto nei : adj[i]) indegree[nei]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (valid.find('A' + i) != valid.end() && indegree[i] == 0)
                q.push(i);
        string res = "";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res += (char) ('A' + node);
            for (auto nei : adj[node])
            {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        return res;
    }
public:
    string rankTeams(vector<string>& votes)
    {
        int n = votes.size();
        int len = votes[0].size();
        vector<vector<int>> v(26, vector<int> (len, 0));
        vector<vector<int>> adj(26);
        set<char> valid;
        for(auto ch : votes[0]) valid.insert(ch);
        for(auto s : votes) for(int i = 0; i < len; i++) v[s[i] - 'A'][i]++;
        for(int i = 0; i < 26; i++)
        {
            if(valid.find('A' + i) != valid.end())
            {
                for(int j = i + 1; j < 26; j++)
                {
                    if(valid.find('A' + j) != valid.end())
                    {
                        int k = 0;
                        while(k < len && v[i][k] == v[j][k]) k++;
                        if(k == len || v[i][k] > v[j][k]) adj[i].push_back(j);
                        else if(v[i][k] < v[j][k]) adj[j].push_back(i);
                    }
                }
            }
        }
        return topoSort(26, adj, valid);
    }
};