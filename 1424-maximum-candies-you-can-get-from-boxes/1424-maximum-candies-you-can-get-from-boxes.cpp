class Solution
{
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
    {
        int n = status.size();
        int result = 0;

        vector<int> boxFound(n, 0), hogyishaadi(n, 0);

        queue<int> q;

        for(auto e : initialBoxes)
        {
            boxFound[e] = 1;
            if(status[e])
            {
                hogyishaadi[e] = 1;
                q.push(e);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            result += candies[node];

            for(auto k : keys[node])
            {
                status[k] = 1;

                if(boxFound[k] && !hogyishaadi[k])
                {
                    hogyishaadi[k] = 1;
                    q.push(k);
                }
            }

            for(auto b : containedBoxes[node])
            {
                boxFound[b] = 1;

                if(status[b] && !hogyishaadi[b])
                {
                    hogyishaadi[b] = 1;
                    q.push(b);
                }
            }
        }
        return result;
    }
};