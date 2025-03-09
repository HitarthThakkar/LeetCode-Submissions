class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;
        
        int src = image[sr][sc];

        q.push({sr, sc});
        vis.insert({sr, sc});
        image[sr][sc] = color;

        while(!q.empty())
        {
            int sz = q.size();
            bool change = false;

            while(sz--)
            {
                int x = q.front().first;
                int y=q.front().second;

                q.pop();

                vector<int> dx = {-1, 0, 0, 1};
                vector<int> dy = {0, -1, 1, 0};

                for(int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i];
                    int yy = y + dy[i];

                    if(xx >= 0 && yy >= 0 && xx < m && yy < n && image[xx][yy] == src && vis.find({xx, yy}) == vis.end())
                    {
                        change = true;
                        image[xx][yy] = color;
                        q.push({xx, yy});
                        vis.insert({xx, yy});
                    }
                }
            }

            if(!change)
            {
                return image;
            }
        }

        return image;
    }
};