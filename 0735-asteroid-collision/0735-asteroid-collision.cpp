class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        int n = asteroids.size();
        vector<int> st;

        for(int i = 0; i < n; i++)
        {
            bool stays = true;

            while(!st.empty() && (st.back() * asteroids[i] < 0) && (st.back() > 0))
            {
                int v1 = abs(st.back());
                int v2 = abs(asteroids[i]);

                if(v1 < v2)
                {
                    st.pop_back();
                }
                else if(v1 == v2)
                {
                    st.pop_back();
                    stays = false;
                    break;
                }
                else
                {
                    stays = false;
                    break;
                }
            }

            if(stays) st.push_back(asteroids[i]);
        }

        return st;
    }
};