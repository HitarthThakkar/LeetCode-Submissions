/*
    SEE THERE IS A DP SOLUTION WHICH IS MUCH MORE OPTIMAL THAN THIS ONE WRITTEN BELOW
    BUT I WHEN I SOLVED THIS QUESTION FIRST, I THOUGHT ABOUT GRAPH AND DAG THINGS.
    SO I IMPLEMENTED THIS.
    BUT IT'S MORE OF A DP PROBLEM AND MORE EFFICIENT USING DP.
    I GOT TO KNOW THIS WHEN I SAW SOMEONE ELSE'S DP SOLUTION.
    SO NOW WHENEVER U SEE THIS PROBLEM AGAIN AND READ THIS STATEMENT,
    THEN TRY SOLVING URSELF USING DP.
    TRY AND TRY AGAIN FOR OPTIMAL SOLUTION.
    BURN YOURSELF.
    AT LEAST YOU WON'T REGRET.
*/

class Solution
{
public:
    int countPaths(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1000000007;

        unordered_map<int, vector<int>> adj;
        unordered_map<int, vector<int>> inverse_adj;
        unordered_map<int, int> indegree;
        queue<int> q;
        int sum = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int id = (n * i) + j;

                for(int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] < grid[i][j])
                    {
                        int pid = (n * nr) + nc;
                        adj[id].push_back(pid);
                        inverse_adj[pid].push_back(id);
                    }
                }

                indegree[id] = adj[id].size();

                if(adj[id].size() == 0) q.push(id);
            }
        }

        while(!q.empty())
        {
            int id = q.front();
            q.pop();

            int allfatherscontributions = 0;

            for(auto fathers : adj[id])
            {
                allfatherscontributions = ((allfatherscontributions % mod) + 
                                                (adj[fathers].back() % mod)) % mod;
            }

            adj[id].push_back(allfatherscontributions + 1);

            for(auto child : inverse_adj[id])
            {
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }

            sum = (((sum % mod) + (adj[id].back() % mod)) % mod);
        }

        return sum;
    }
};


/*


Observation
Let's try to solve the 1D version of this problem. We are given the following array and we can only move forward:

[1,2,3,4,3]. How do we find the number of increasing sequences?

Let's try to pick each element/index as our starting point and find the answer. 1 -> [1,2,3,4] = 4, 2 -> [2,3,4] = 3, 3-> [3,4] = 2, [4] = 1, [3] = 1. Summing these individual values will produce the answer. But what do these individual results essentially mean?

Let's look at [1,2,3,4] = 4, this means starting from 1 we have a total of 4 increasing sequences/paths. [1,2,3,4], [1,2,3], [1,2], [1]. We are calculating the same for each starting point.

The 2D version is similar as it forms a DAG and hence are no cycles in the graph/path.

These observations are the only thing we need to understand and we can do the same in the converted/complex problem with 2D grid and 4 directional movement. For a 2D grid for each starting cell you find the number of elements/cell in the longest possible increasing path for all directions and the sum of all these results will be the answer.

Solution
We use top-down DP to store the intermediate results, each state i,j could be called multiple times and we can cache the results and thus bring down the time complexity.

C++
static int MOD=1e9+7;
static vector<int> dirs={0,1,0,-1,0};
class Solution {
public:
    vector<vector<long>> memo;
    long dp(vector<vector<int>>& grid,int i,int j) {
        long result=1;  // Contribution of current cell as an increasing sequence.
        if(memo[i][j]!=-1)  // Return the cached results if they exist.
            return memo[i][j];
        for(int d=0;d<4;d++) {  // Check all 4 directions.
            int x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]>grid[i][j])
                result=(result+dp(grid,x,y))%MOD;       // Add the total number of cells in the longest path for all directions.
        }
        return memo[i][j]=result;
    }
    int countPaths(vector<vector<int>>& grid) {
        long result=0;
        memo.resize(grid.size(),vector<long>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)      // For each cell as a starting point calculate the number of increasing paths it can contribute.
            for(int j=0;j<grid[0].size();j++)
                result=(result+dp(grid,i,j))%MOD;
        return result;
    }
};


*/