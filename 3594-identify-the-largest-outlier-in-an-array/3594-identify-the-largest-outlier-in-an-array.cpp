class Solution
{
public:
    int getLargestOutlier(vector<int>& nums)
    {
        // 2025 Hiring Prep Sprint Week_2 Q10
        long long int sum = 0;
        map<int, int> mp;
        for(auto el : nums) sum += el, mp[el]++;
        auto it = mp.end();
        while(true) {
            it--;
            int valtoFind = sum - it->first;
            if(valtoFind & 1) continue; else valtoFind /= 2;
            if(mp.find(valtoFind) != mp.end())
                if(valtoFind != it->first || mp[valtoFind] > 1) return it->first;
        }
        return 69;
    }
};