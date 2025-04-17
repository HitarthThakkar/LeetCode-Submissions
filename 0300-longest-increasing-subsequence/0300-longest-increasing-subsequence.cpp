class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> v;

        for(auto e : nums)
        {
            if(v.empty()) v.push_back(e);
            if(e > v.back()) v.push_back(e); // iykyk v is ALWAYS monotonic.
            else
            {
                int ind = lower_bound(v.begin(), v.end(), e) - v.begin();
                v[ind] = e;
            }
        }

        return v.size();

        /*
                             SYSTEM
                            : Alarm : 
                           Leveled Up !
                           Leveled Up !

            TOPICS LEARNED :
            Patience Sort
            Game of Patience
            Minimum Piles Algo (Greeedy)
            Minimum piles -> follows LIS Rules
            Minimum Piles ==  Length og LIS
            Binary Searching previous tops
            Printing LIS using 2 arrays only {Goto GFG}
            SOURCES :
            https://www.youtube.com/watch?v=S9oUiVYEq7E
            https://www.youtube.com/watch?v=22s1xxRvy28&t=2s
            https://www.yourownmind.com [Not intended as a URL]
        */

    }
};