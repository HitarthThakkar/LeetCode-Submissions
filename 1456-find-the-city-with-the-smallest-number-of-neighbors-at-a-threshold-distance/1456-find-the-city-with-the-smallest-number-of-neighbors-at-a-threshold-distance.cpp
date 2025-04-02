class Solution
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int> (n, 1e9));

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(auto e : edges)
        {
            int from = e[0];
            int to = e[1];
            int weight = e[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }

        // Chunky Boy
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int answer = 0;
        int mini = 1e9;

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++) if(dist[i][j] <= distanceThreshold) count++;
            mini = min(mini, count);
            if(mini == count) answer = i;
        }

        return answer;
    }
};