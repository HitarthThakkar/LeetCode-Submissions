class Solution
{
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n = nums1.size();

        vector<long long> answer(n, 0);

        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
        {
            if(mp[nums1[i]].size() == 0)
            {
                mp[nums1[i]].push_back(i);
            }
            mp[nums1[i]].push_back(nums2[i]);
        }

        multiset<int> s;

        long long sum = 0;

        // for(auto ele : mp)
        // {
        //     cout << ele.first << " -> ";
        //     for(auto e : ele.second)
        //     {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << endl;

        for(auto ele : mp)
        {
            answer[ele.second[0]] = sum;

            for(int i = 1; i < ele.second.size(); i++)
            {
                s.insert(ele.second[i]);
                sum += ele.second[i];
            }

            while(s.size() > k)
            {
                sum -= (*(s.begin()));
                s.erase(s.begin());
            }

        }


        map<int, long long> mpp;

        for(int i = 0; i < n; i++)
        {
            if(answer[i] != 0)
            {
                mpp.insert({nums1[i], answer[i]});
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(answer[i] == 0)
            {
                if(mpp.find(nums1[i]) != mpp.end())
                {
                    answer[i] = mpp[nums1[i]];                    
                }
            }
        }

        return answer;
    }
};