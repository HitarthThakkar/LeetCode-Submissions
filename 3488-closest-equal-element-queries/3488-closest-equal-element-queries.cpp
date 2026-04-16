class Solution
{
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        vector<int>res;
        unordered_map<int, vector<int>> m;
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        for(auto q:queries){
            int n=nums[q];
            // find left and right to ind in m[num].
            int sz=m[n].size();
            if(sz==1){res.push_back(-1); continue;}
            int ind=lower_bound(m[n].begin(),m[n].end(),q)-m[n].begin();
            int mini=1e9;
            if(ind==0) mini=min(m[n][ind+1]-m[n][ind],((int)nums.size()-m[n].back()+m[n][ind]));
            else if(ind==sz-1) mini=min(m[n][ind]-m[n][ind-1],((int)nums.size()-m[n][ind]+m[n][0]));
            else mini=min(m[n][ind+1]-m[n][ind],m[n][ind]-m[n][ind-1]);
            res.push_back(mini);
        }
        return res;
    }
};