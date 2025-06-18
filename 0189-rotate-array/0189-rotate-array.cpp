class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        // CUMpilation, pile - ation of CUM

        // Noob (27 May, 2024, 11:24 AM)
        /*
        class Solution {
        public:
            void rotate(vector<int>& nums, int k)
            {
                int n = nums.size();
                k %= n;
                reverse(nums.begin(), nums.end());
                reverse(nums.begin(), nums.begin() + k);
                reverse(nums.begin() + k, nums.end());
            }
        };
        */

        // High (27 May, 2024, 11:55 AM)
        // Confession : 
        // I was not in a right mental state and somehow cooked up this.
        // Which clearly works though.
        // IDK why it underperforms tho.
        // I actually DO think this should have very good TC and SC ofc.

            k %= nums.size();
            int ct = 0;
            for(int start = 0; ct < nums.size(); start++)
            {
                int curr = start;
                int prev = nums[start];
                do{
                    int next = (curr + k) % nums.size();
                    int temp = nums[next];
                    nums[next] = prev;
                    prev = temp;
                    curr = next;
                    ct++;
                }
                while (start != curr);
            }
        

        // Absolute madness [or greatness idk what to say to this]
        // 25 Dec, 2024, 13:52
        /*
            int n = nums.size();
            k %= n; if(k == 0) return;
            int gcd = __gcd(n, k);
            for(int i = 0; i < gcd; i++)
            {
                int dump = nums[i], ind = i;
                for(int j = 0; j < (n / gcd); j++)
                {
                    int nind = ((ind + k) % n);
                    swap(dump, nums[nind]);
                    ind = nind;
                }
            }
        */
    }
};