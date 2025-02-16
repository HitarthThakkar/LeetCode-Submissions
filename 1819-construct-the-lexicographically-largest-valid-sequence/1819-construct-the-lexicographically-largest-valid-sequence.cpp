class Solution
{
private:
    bool recur(int ind, vector<int> &vis, vector<int> &res)
    {
        if(ind == res.size())
        {
            bool flag = true;
            for(auto ele : res) if(ele == -1) flag = false;
            return flag;
        }

        if(res[ind] != -1)
        {
            return recur(ind + 1, vis, res);
        }

        for(int i = vis.size() - 1; i > 0; i--)
        {
            if(!vis[i])
            {
                if(i == 1)
                {
                    bool result = false;
                    res[ind] = 1;
                    vis[i] = 1;
                    result = recur(ind + 1, vis, res);
                    if(result) return true;
                    res[ind] = -1;
                    vis[i] = 0;
                }
                else
                {
                    bool result = false;

                    int val = i;
                    int disind = ind + i;

                    if(disind < res.size() && res[disind] == -1)
                    {
                        res[ind] = val;
                        res[disind] = val;
                        vis[val] = 1;
                        result = recur(ind + 1, vis, res);
                        if(result) return true;
                        res[ind] = -1;
                        res[disind] = -1;
                        vis[val] = 0;
                    }
                }

            }
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> answer((2 * n) - 1, -1);
        vector<int> vis(n + 1, 0); vis[0] = 1;
        recur(0, vis, answer);
        return answer;
    }
};