class Solution
{
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        vector<int> v;
        bool dir = true;

        for(int i = n - 1; i >= 0; i--)
        {
            if(dir)
                for(int j = 0; j < n; j++) v.push_back(board[i][j]);
            else
                for(int j = n - 1; j >= 0; j--) v.push_back(board[i][j]);
            dir = !dir;
        }

        vector<int> dist(n * n, 1e9);
        
        int lastindex = (n * n) - 1;

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            // cout << node << endl;

            if(node == lastindex) return dist[node];

            for(int del = 1; del < 7; del++)
            {
                int dest = node + del;
                // cout << "# " << dest << " ";

                if(dest < v.size())
                {
                    int nd = (v[dest] - 1);
                    // cout << " $ " << nd << endl;
                    // cout << dist[node] << " " << dist[dest] << endl;

                    if(nd < 0)
                    {
                        if((dist[node] + 1) < dist[dest])
                        {
                            dist[dest] = dist[node] + 1;
                            q.push(dest);
                        }
                    }
                    else
                    {
                        if(dist[node] + 1 < dist[nd])
                        {
                            dist[nd] = dist[node] + 1;
                            q.push(nd);
                        }
                    }
                }
            }
        }

        return -1;
    }
};