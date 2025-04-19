class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            bool stays = true;

            while(!st.empty() && (st.top() * asteroids[i] < 0) && (st.top() > 0))
            {
                int v1 = abs(st.top());
                int v2 = abs(asteroids[i]);

                if(v1 < v2)
                {
                    st.pop();
                }
                else if(v1 == v2)
                {
                    st.pop();
                    stays = false;
                    break;
                }
                else
                {
                    stays = false;
                    break;
                }
            }

            if(stays) st.push(asteroids[i]);
        }

        vector<int> result;

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};