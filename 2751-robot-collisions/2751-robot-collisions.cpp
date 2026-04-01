class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions)
    {
        int n = positions.size();
        unordered_map<int, int> rInd;
        for(int i = 0; i < n; i++) rInd[positions[i]] = i;
        stack<int> rst;
        sort(positions.begin(), positions.end());
        for(int i = 0; i < n; i++)
        {
            int realInd = rInd[positions[i]];
            if(directions[realInd] == 'R')
            {
                rst.push(realInd);
            }
            else
            {
                bool done = false;
                while(!rst.empty() && !done)
                {
                    int righterInd = rst.top();
                    int lefterInd = realInd;
                    if(healths[righterInd] > healths[lefterInd])
                    {
                        healths[righterInd]--;
                        healths[lefterInd] = -1;
                        done = true;
                    }
                    else if(healths[righterInd] < healths[lefterInd])
                    {
                        healths[lefterInd]--;
                        healths[righterInd] = -1;
                        rst.pop();
                    }
                    else
                    {
                        healths[lefterInd] = -1;
                        healths[righterInd] = -1;
                        rst.pop();
                        done = true;
                    }
                }
            }
        }
        vector<int> ans;
        for(auto ele : healths) if(ele != -1) ans.push_back(ele);
        return ans;
    }
};