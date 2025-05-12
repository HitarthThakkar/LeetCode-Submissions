class Solution
{
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        int n = digits.size();
        sort(digits.begin(), digits.end());
        vector<int> result;

        int lasti = -1;

        for(int i = 0; i < n; i++)
        {
            if(lasti >= 0 && digits[i] == digits[lasti]) continue;
            if(digits[i] == 0) continue;

            int lastj = -1;

            for(int j = 0; j < n; j++)
            {
                if(lastj >= 0 && digits[j] == digits[lastj]) continue;
                if(j == i) continue;

                int lastk = -1;

                for(int k = 0; k < n; k++)
                {
                    if(lastk >= 0 && digits[k] == digits[lastk]) continue;
                    if(k == i || k == j || digits[k] & 1) continue;

                    result.push_back((digits[i] * 100) + (digits[j] * 10) + digits[k]);

                    lastk = k;
                }
                
                lastj = j;
            }

            lasti = i;
        }

        return result;
    }
};