class Solution
{
public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int, int> m;
        for(auto e : answers) m[e]++;
        int rabbits = 0;
        for(auto e : m)
        {
            if(e.second == 1) rabbits += (e.first + 1);
            else {
                int times = (e.second / (e.first + 1));
                if(e.second % (e.first + 1) != 0) times++;
                rabbits += (times * (e.first + 1));
            }
        }
        return rabbits;
    }
};