class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, set<int>> mp;
        int i = 0;
        for(auto e : nums)
            {
                mp[e].insert(i);
                mp[e].insert(nums.size() + i);
                i++;
            }
        // for(auto e : mp)
        //     {
        //         cout << e.first << " -> ";
        //         for(auto el : e.second)
        //             cout << el << " ";
        //         cout <<endl;
        //     }
        i = 0;vector<int> ans(queries.size(), 1e9);
        for(auto e : queries)
            {
                int el = nums[e];
                if(mp[el].size() == 2)
                {
                    ans[i] = -1;
                }
                else
                {
                    auto it = mp[el].lower_bound(e);
                    // cout << *it << endl;
                    if(it != mp[el].begin()){
                        it--; ans[i] = e - *it;
                    }
                    else {
                        it = mp[el].end();
                        it--;
                        int val = *it;
                        val %= nums.size();
                        int tt = nums.size() -val + e;
                        ans[i] = min(ans[i], tt);
                    }

                    auto itr = mp[el].upper_bound(e);
                    // cout << *itr << endl;
                    if(itr != mp[el].end()){
                        ans[i] = min(ans[i], *itr - e);
                    }
                }
                i++;
            }
        return ans;
    }
};