class Solution
{
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        unordered_set<int> s;
        for(auto ele : arr) s.insert(ele);
        int n = arr.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int one = arr[i];
                int two = arr[j];
                int length = 2;
                while(true)
                {
                    if(s.find(one + two) == s.end()) break;
                    int pone = one;
                    one = two;
                    two = pone + two;
                    length++;
                }
                if(length >= 3) result = max(result, length);
            }
        }
        return result;
    }
};