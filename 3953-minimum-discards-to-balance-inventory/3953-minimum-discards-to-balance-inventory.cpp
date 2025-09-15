class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        map<int, int> mp;
        map<int, int> mm;

        int n = arrivals.size();
        int l = 0, r = 0;
        int disc = 0;
        // int sz = 0;

        set<int> taken;

        while(r < n)
        {
            if(r-l+1 > w)
            {
                if(taken.find(l) != taken.end()) mp[arrivals[l]]--;
                l++;
            }

            if(mp[arrivals[r]] + 1 <= m)
            {
                taken.insert(r);
                mp[arrivals[r]]++;
            }
            else
            {
                disc++;
            }
            
            r++;
        }

        return disc;
    }
};